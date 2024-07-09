set(Headers
    include/QtCmake.h
)
set(sourceCodes
    sources/main.cpp
    sources/QtCmake.cpp

)
set(UI 
    forms/QtCmake.ui
)
set(CMAKE_AUTOUIC_SEARCH_PATHS
    forms 
)

add_executable(QtCmake  
${sourceCodes}
${UI}
${Headers}
)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${PROJECT_NAME} PRIVATE
   include
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)