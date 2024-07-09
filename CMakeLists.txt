cmake_minimum_required(VERSION 3.28)
project(QtCmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
if(WIN32)
    set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})
elseif(UNIX AND NOT APPLE)
      set(CMAKE_PREFIX_PATH "/opt/Qt/5.14.2" ${CMAKE_PREFIX_PATH})
endif()



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED 
    COMPONENTS
        Core
        Gui
        Widgets
)
add_subdirectory(src)



