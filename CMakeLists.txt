cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

project(Voice_Clicker_Companion VERSION 0.1.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
        message("Build system is change to ${CMAKE_SYSTEM_NAME}")
        add_compile_definitions(__MACOS__)
    endif()    
elseif(WIN32)
    message("This is a Windows System")
    message("Build system is change to ${CMAKE_SYSTEM_NAME}")
    add_compile_definitions(__WINDOWS__)
endif()

message("Setting up library: [buffer]")
add_subdirectory(buffer)
message("Setting up library: [microphone]")
add_subdirectory(microphone)
message("Setting up library: [remote_input]")
add_subdirectory(remote_input)
message("Setting up library: [zero config]")
add_subdirectory(zero_config)
message("Setting up library: [control panel]")
add_subdirectory(control_panel)
message("Setting up library: [gui]")
add_subdirectory(gui)



# add_executable(${PROJECT_NAME} main.cpp)
# set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Voice Clicker Companion")
# target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/libBuffer.a)
