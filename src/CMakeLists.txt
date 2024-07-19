set(WIDGETS_INCLUDE_DIR  include/widgetsInclude)

file(GLOB EXE_FILES
    ${WIDGETS_INCLUDE_DIR}/*.h
     sources/*.cpp
)
set(CMAKE_AUTOUIC_SEARCH_PATHS
    forms 
)
qt5_add_resources(QRC_FILES resources/MainWindow.qrc)
add_executable(${PROJECT_NAME}  
${EXE_FILES}
${QRC_FILES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        materialUi
        log4cplus::log4cplus
        ${OpenCV_LIBS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
   include
    ${WIDGETS_INCLUDE_DIR}
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
