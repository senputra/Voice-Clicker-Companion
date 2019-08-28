cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)


set(PROJECT_NAME Microphone_API)
project(${PROJECT_NAME} VERSION 0.1.0)


set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED OFF)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.70.0) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    include_directories(${CMAKE_SOURCE_DIR}/rtaudio/include)
    include_directories(${CMAKE_SOURCE_DIR}/rtaudio)
    add_library(${PROJECT_NAME} 
        Microphone_API.cpp
        NetworkStream.cpp
	    rtaudio.cpp
        PlaybackStream.cpp
        StreamBuffer.cpp)
    target_link_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
