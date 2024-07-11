#pragma once

#include <set>
#include <log4cplus/logger.h>
#include <log4cplus/initializer.h>
#include <log4cplus/hierarchy.h>
#include <QScopedPointer>

using namespace log4cplus;
// 调试日志
#define LOG_DEBUG( ...)\
{\
	if(MyLog)\
	{\
		MyLog->WriteLog(log4cplus::DEBUG_LOG_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);\
	}\
}

// 普通日志
#define LOG_INFO( ...)\
{\
	if(MyLog)\
	{\
		MyLog->WriteLog(log4cplus::INFO_LOG_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);\
	}\
}

// 警告日志
#define LOG_WARN( ...)\
{\
	if(MyLog)\
	{\
		MyLog->WriteLog(log4cplus::WARN_LOG_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);\
	}\
}

// 错误日志
#define LOG_ERROR( ...)\
{\
	if(MyLog)\
	{\
		MyLog->WriteLog(log4cplus::ERROR_LOG_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);\
	}\
}

#define DEFALT_LOG_FILE_PATH L""                // 默认日志文件路径
#define DEFALT_LOG_FILE_NAME L"log.log"         // 默认日志文件名
#define DEFALT_MAX_FILE_SIZE 10 * 1024 * 1024   // 默认最大文件大小
#define DEFALT_MAX_FILE_COUNT 100			    // 默认最大文件备份数量
#define DEFALT_IS_ASYNC	true                    // 默认异步
#define DEFALT_MAX_DAYS_COUNT 30                // 默认最多保留日志天数

class Log4CPlusPlusImp
{
public:
	Log4CPlusPlusImp();
	~Log4CPlusPlusImp();

public:
	bool Init();

	void AddFileAppender(
		int level,
		const wchar_t* file_path = DEFALT_LOG_FILE_PATH,
		const wchar_t* file_name = DEFALT_LOG_FILE_NAME,
		unsigned long max_file_size = DEFALT_MAX_FILE_SIZE,
		unsigned long max_file_count = DEFALT_MAX_FILE_COUNT,
		bool is_async = DEFALT_IS_ASYNC
	);

	void EnableDebuggerAppender(bool enable = false);
	void EnableConsoleAppender(bool enable = false);

	const wchar_t* GetLogPath();

	void WriteLog(
		LogLevel logLevel,
		const char* file,
		int line,
		const char* function,
		const wchar_t* format, ...);

private:
	std::wstring GetFullLogFileName(const wchar_t* file_path_base, const wchar_t* file_name);
	bool FileAppenderPathExist(const std::wstring& path);
	bool AddFileAppenderPath(const std::wstring& path);

private:
	Logger m_logger;
	std::unique_ptr<Initializer> m_pInitializer;
	std::unique_ptr<Hierarchy> m_pHierarchy;
	std::set<std::wstring> m_fileAppenderPath;
	std::wstring m_log_path;
};

extern Log4CPlusPlusImp*  MyLog;

