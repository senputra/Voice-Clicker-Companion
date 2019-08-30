set(PROJECT_NAME Microphone)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED OFF)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.70.0) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/rtaudio/include)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/rtaudio)
    add_library(${PROJECT_NAME} 
        Microphone.cpp
        NetworkStream.cpp
        RtAudio.cpp
        PlaybackStream.cpp
        StreamBuffer.cpp)
    target_link_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/rtaudio/include)
    find_library(COREAUDIO_LIB CoreAudio)
    find_library(COREFOUNDATION_LIB CoreFoundation)
    target_compile_definitions(${PROJECT_NAME} PUBLIC __MACOSX_CORE__)
    target_link_libraries(${PROJECT_NAME} 
        ${Boost_LIBRARIES}
        ${COREAUDIO_LIB} # This is to include the core audio library from mac
        ${COREFOUNDATION_LIB} # This is to include the core audio library from mac
        pthread)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# //	g++ -Wall -D__MACOSX_CORE__ -o audioprobe audioprobe.cpp RtAudio.cpp 
# -framework CoreAudio -framework CoreFoundation -lpthread
