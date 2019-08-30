cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

project(Voice_Clicker_Companion VERSION 0.1.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(POCO_HEADERS) 
add_subdirectory(buffer)
add_subdirectory(microphone)
add_subdirectory(remote_input)
add_subdirectory(zero_config)
message("This is POCO_HEADERS " ${POCO_HEADERS}) 
add_subdirectory(control_panel)



# add_executable(${PROJECT_NAME} main.cpp)
# set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Voice Clicker Companion")
# target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/libBuffer.a)
