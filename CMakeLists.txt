cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCE_CONFIG "${CMAKE_CURRENT_SOURCE_DIR}/config.ini")
if(WIN32)
    set(VCPKG_ROOT "D:/vside/vcpkg-2024.06.15/scripts/buildsystems/vcpkg.cmake" CACHE PATH "")
    set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT})
    set(CMAKE_PREFIX_PATH 
    "D:/vside/vcpkg-2024.06.15/installed/x64-windows"
    ${CMAKE_PREFIX_PATH})
elseif(UNIX AND NOT APPLE)
    set(CMAKE_PREFIX_PATH 
    "/opt/Qt5.14.2/5.14.2/gcc_64/lib/cmake/Qt5" ${CMAKE_PREFIX_PATH})
endif()
project(QtCmake LANGUAGES CXX)

add_compile_options("/utf-8")
find_package(Qt5 REQUIRED 
    COMPONENTS
        Core
        Gui
        Widgets
)
find_package(log4cplus CONFIG REQUIRED)
#find_package(snap7 CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)



add_subdirectory(materialUi)
add_subdirectory(src)









