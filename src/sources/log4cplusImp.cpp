#include "log4cplusImp.h"
#include <iostream>
#include <filesystem>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/win32debugappender.h>
#include <log4cplus/win32consoleappender.h>
#include <log4cplus/helpers/property.h>
#include <log4cplus/logger.h>
#include <log4cplus/spi/filter.h>
#include <log4cplus/spi/loggingevent.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/helpers/loglog.h>
#include <AppConfig.h>

#define DEBUGGER_APPENDER_NAME LOG4CPLUS_TEXT("debuggerAppender")
#define CONSOLE_APPENDER_NAME LOG4CPLUS_TEXT("consoleAppender")
#define FILE_APPENDER_NAME LOG4CPLUS_TEXT("fileAppender")
using namespace std;
using namespace log4cplus;
using namespace log4cplus::spi;
using namespace log4cplus::helpers;

auto filterInfoFunction = [=](const InternalLoggingEvent& event)
-> FilterResult {
	if (event.getLogLevel() == INFO_LOG_LEVEL)
	{
		return ACCEPT;
	}
	return DENY;
	};
auto filterErrorFunction = [=](const InternalLoggingEvent& event)
-> FilterResult {
	if (event.getLogLevel() == ERROR_LOG_LEVEL)
	{
		return ACCEPT;
	}
	return DENY;
	};
auto filterOthersFunction = [=](const InternalLoggingEvent& event)
-> FilterResult {
	if (event.getLogLevel() != INFO_LOG_LEVEL && event.getLogLevel() != ERROR_LOG_LEVEL)
	{
		return ACCEPT;
	}
	return DENY;
	};
Log4CPlusPlusImp::Log4CPlusPlusImp()
{
	m_pInitializer = std::make_unique<log4cplus::Initializer>();
	m_pHierarchy = std::make_unique<log4cplus::Hierarchy>();
	m_logger = m_pHierarchy->getRoot();
}

Log4CPlusPlusImp::~Log4CPlusPlusImp()
{
	m_logger.shutdown();
	m_pHierarchy.reset();
	m_pInitializer.reset();
}


bool Log4CPlusPlusImp::Init()
{
	MyLog = new Log4CPlusPlusImp();
	if (MyLog)
	{
		MyLog->AddFileAppender(1, (AppConfig::AppPath + "/logs").toStdWString().c_str(), L"infos.txt");
		MyLog->AddFileAppender(2, (AppConfig::AppPath + "/logs").toStdWString().c_str(), L"errors.txt");
		MyLog->AddFileAppender(3, (AppConfig::AppPath + "/logs").toStdWString().c_str(), L"other_msgs.txt");
		MyLog->EnableDebuggerAppender(true);
		return true;
	}
	return false;
}



// 添加文件附加器
void Log4CPlusPlusImp::AddFileAppender(
	int level,
	const wchar_t* file_path,
	const wchar_t* file_name,
	unsigned long max_file_size,
	unsigned long max_file_count,
	bool is_async)
{
	try
	{
		// 保证同文件只添加到一个附加器
		std::filesystem::path path(file_path);
		path /= file_name;
		if (FileAppenderPathExist(path.wstring()))
			return;

		// 日志文件
		std::wstring logFile = GetFullLogFileName(file_path, file_name);
		std::wstring s_async = is_async ? L"true" : L"false";

		log4cplus::helpers::Properties properties;
		properties.setProperty(LOG4CPLUS_TEXT("File"), logFile.c_str());
		properties.setProperty(LOG4CPLUS_TEXT("CreateDirs"), LOG4CPLUS_TEXT("true"));
		properties.setProperty(LOG4CPLUS_TEXT("ImmediateFlush"), LOG4CPLUS_TEXT("true"));
		properties.setProperty(LOG4CPLUS_TEXT("MaxFileSize"), std::to_wstring(max_file_size).c_str());
		properties.setProperty(LOG4CPLUS_TEXT("MaxBackupIndex"), std::to_wstring(max_file_count).c_str());
		properties.setProperty(LOG4CPLUS_TEXT("AsyncAppend"), s_async.c_str());
		properties.setProperty(LOG4CPLUS_TEXT("Locale"), LOG4CPLUS_TEXT("en_US.UTF-8"));
		log4cplus::SharedAppenderPtr fileAppend(new log4cplus::RollingFileAppender(properties));
		if (fileAppend)
		{
			if (level == 1)
			{
				fileAppend->addFilter(FilterPtr(new FunctionFilter(filterInfoFunction)));
			}
			else	if (level == 2)
			{
				fileAppend->addFilter(FilterPtr(new FunctionFilter(filterErrorFunction)));
			}
			else	if (level == 3)
			{
				fileAppend->addFilter(FilterPtr(new FunctionFilter(filterOthersFunction)));
			}
			fileAppend->setLayout(std::unique_ptr<Layout>(
				new PatternLayout(LOG4CPLUS_TEXT("[%D{%Y-%m-%d %H:%M:%S.%q}] [%t] %-5p [%M]%n   %m%n--------------------------------------------%n"))));
			m_logger.addAppender(fileAppend);

			AddFileAppenderPath(path.wstring());
		}
	}
	catch (...) {}
}

// 调试日志
void Log4CPlusPlusImp::EnableDebuggerAppender(bool enable)
{
	SharedAppenderPtr debuggerAppender = m_logger.getAppender(DEBUGGER_APPENDER_NAME);

	// 若需启用，且没有添加，则添加
	if (enable && !debuggerAppender)
	{
		debuggerAppender = new Win32DebugAppender();
		if (debuggerAppender)
		{
			debuggerAppender->setName(DEBUGGER_APPENDER_NAME);
			debuggerAppender->setLayout(std::unique_ptr<Layout>(
				new PatternLayout(LOG4CPLUS_TEXT("[%D{%Y-%m-%d %H:%M:%S.%q}] [%t] %-5p (%F:%L::%M) %m%n"))));
			m_logger.addAppender(SharedAppenderPtr(debuggerAppender.get()));
		}
	}
	// 若需禁用，且已经添加，则移除
	else if (!enable && debuggerAppender)
	{
		m_logger.removeAppender(DEBUGGER_APPENDER_NAME);
	}
}

// 控制台日志
void Log4CPlusPlusImp::EnableConsoleAppender(bool enable)
{
	SharedAppenderPtr consoleAppender = m_logger.getAppender(CONSOLE_APPENDER_NAME);

	// 若需启用，且没有添加，则添加
	if (enable && !consoleAppender)
	{
		consoleAppender = new Win32ConsoleAppender();
		if (consoleAppender)
		{
			consoleAppender->setName(CONSOLE_APPENDER_NAME);
			consoleAppender->setLayout(std::unique_ptr<Layout>(
				new PatternLayout(LOG4CPLUS_TEXT("[%D{%Y-%m-%d %H:%M:%S.%q}] [%t] %-5p (%F:%L::%M) %m%n"))));
			m_logger.addAppender(SharedAppenderPtr(consoleAppender.get()));
		}
	}
	// 若需禁用，且已经添加，则移除
	else if (!enable && consoleAppender)
	{
		m_logger.removeAppender(CONSOLE_APPENDER_NAME);
	}
}

// 获取完全的日志路径名
std::wstring Log4CPlusPlusImp::GetFullLogFileName(const wchar_t* file_path_base, const wchar_t* file_name)
{
	try
	{
		std::wstring s_file_path_base(file_path_base);
		std::filesystem::path log_path;

		// 路径
		if (s_file_path_base.size() == 0)
		{
			log_path = std::filesystem::current_path();
		}
		else
		{
			log_path = std::filesystem::path(s_file_path_base);
		}
		m_log_path = log_path.wstring();
		if (!std::filesystem::exists(log_path))
		{
			std::filesystem::create_directories(log_path);
		}

		// 路径+日志文件
		log_path /= std::filesystem::path(file_name);
		return log_path.wstring().c_str();
	}
	catch (...) {}
	return L"";
}

// 获取日志路径
const wchar_t* Log4CPlusPlusImp::GetLogPath()
{
	return m_log_path.c_str();
}

// 打印日志
void Log4CPlusPlusImp::WriteLog(LogLevel logLevel, const char* file, int line, const char* function, const wchar_t* format, ...)
{
	try
	{
		assert(format);
		LOG4CPLUS_MACRO_INSTANTIATE_SNPRINTF_BUF(var);

		tchar const* msg = nullptr;
		int ret = 0;
		std::va_list args;

		do
		{
			va_start(args, format);
			ret = var.print_va_list(msg, format, args);
			va_end(args);
		} while (ret == -1);

		if (msg)
		{
			m_logger.log(logLevel, msg, file, line, function);
		}
	}
	catch (...) {}
}

bool Log4CPlusPlusImp::FileAppenderPathExist(const std::wstring& path)
{
	return m_fileAppenderPath.find(path) != m_fileAppenderPath.end() ? true : false;
}

bool Log4CPlusPlusImp::AddFileAppenderPath(const std::wstring& path)
{
	return m_fileAppenderPath.insert(path).second;
}

Log4CPlusPlusImp* MyLog;
