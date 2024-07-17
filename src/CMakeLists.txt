set(Headers
    "include/Singleton.h"
    "include/MainWindow.h"
 "include/log4cplusImp.h"
 "include/AppConfig.h" 
 "include/AppHelper.h" 
 "include/frmmessagebox.h"
 "include/iconhelper.h"
 "include/mainControl.h" "include/pch.h" "include/Global.h")
set(sourceCodes
    sources/main.cpp
    "sources/MainWindow.cpp"
 "sources/log4cplusImp.cpp" 
 "sources/AppConfig.cpp" 
 "sources/frmmessagebox.cpp" "sources/iconhelper.cpp" "sources/mainControl.cpp" "sources/UiHelper.cpp")
set(UI 
    forms/MainWindow.ui
    forms/frmmessagebox.ui
)
set(CMAKE_AUTOUIC_SEARCH_PATHS
    forms 
)
qt5_add_resources(QRC_FILES resources/MainWindow.qrc)
add_executable(${PROJECT_NAME}  
${sourceCodes}
${UI}
${Headers}
${QRC_FILES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        materialUi
        log4cplus::log4cplus
)

target_include_directories(${PROJECT_NAME} PRIVATE
   include
   ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/include
)
if(WIN32)
    set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)
endif()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${SOURCE_CONFIG}" $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMENT "拷贝配置文件"
)
