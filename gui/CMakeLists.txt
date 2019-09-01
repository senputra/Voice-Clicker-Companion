cmake_minimum_required(VERSION 3.1.0)
set(PROJECT_NAME "VoiceClicker")
project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_DIR "/Users/praxiumsg/Qt/5.13.0")
set( ENV(CMAKE_PREFIX_PATH) ${QT_DIR} )
set(QT_QMAKE_EXECUTABLE ${QT_DIR}/clang_64/bin/qmake)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED OFF)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.70.0) 
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}
        ${POCO_HEADERS}) 
endif()

add_executable(${PROJECT_NAME} 
        TrayApp.ui
        TrayApp.cpp
        main.cpp
        trayassets.qrc
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CONTROLPANEL_INCLUDES})
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_directories(${PROJECT_NAME} PRIVATE
    ${MAKE_LIBRARY_OUTPUT_DIRECTORY})
    
target_link_libraries(${PROJECT_NAME} ControlPanel)


