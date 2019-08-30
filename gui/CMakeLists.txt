cmake_minimum_required(VERSION 3.1.0)
project(VoiceCLicker VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -m64)
set(CMAKE_CXX_FLAGS -m64)
set(CMAKE_EXE_LINKER_FLAGS -m64)
set(CMAKE_MODULE_LINKER_FLAGS -m64)
set(CMAKE_SHARED_LINKER_FLAGS -m64)
set(CMAKE_STATIC_LINKER_FLAGS -m64)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(POCO_HEADERS ../ZeroConfigModule/Poco/DNSSD/include/
    ../ZeroConfigModule/Poco/DNSSD/Bonjour/include/
    ../ZeroConfigModule/Poco/DNSSD/Avahi/include/
    ../ZeroConfigModule/Poco/Net/include/
    ../ZeroConfigModule/Poco/Foundation/include/)
    

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

add_executable(VoiceCLicker 
        TrayApp.ui
        TrayApp.cpp
        main.cpp
        trayassets.qrc
)
target_link_libraries(VoiceCLicker Qt5::Core)
target_link_libraries(VoiceCLicker Qt5::Widgets)
target_link_libraries(VoiceCLicker 
                ${CMAKE_SOURCE_DIR}/build/libControlPanel.a
                ${CMAKE_SOURCE_DIR}/build/libMicrophone.a
                ${CMAKE_SOURCE_DIR}/build/libBuffer.a
                ${CMAKE_SOURCE_DIR}/build/libMicrophone.a
                ${CMAKE_SOURCE_DIR}/build/libRemoteInput.a
                ${CMAKE_SOURCE_DIR}/build/libServiceDiscovery.a)

target_link_libraries(VoiceCLicker 
                ${CMAKE_SOURCE_DIR}/../ZeroConfigModule/Poco/lib/libPocoDNSSD.dylib
                ${CMAKE_SOURCE_DIR}/../ZeroConfigModule/Poco/lib/libPocoNet.dylib
                ${CMAKE_SOURCE_DIR}/../ZeroConfigModule/Poco/lib/libPocoFoundation.dylib)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
