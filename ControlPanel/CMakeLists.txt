cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME "ControlPanel")
project(${PROJECT_NAME} VERSION 0.1.0)

set(POCO_HEADERS ../ZeroConfigModule/Poco/DNSSD/include/
    ../ZeroConfigModule/Poco/DNSSD/Bonjour/include/
    ../ZeroConfigModule/Poco/DNSSD/Avahi/include/
    ../ZeroConfigModule/Poco/Net/include/
    ../ZeroConfigModule/Poco/Foundation/include/)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED OFF)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.70.0) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}
        ${POCO_HEADERS}) 
    add_library(${PROJECT_NAME} ControlPanel.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

message("sadasdsadsa ${POCO_HEADERS} aass ")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
