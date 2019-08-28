cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD_REQUIRED 11)
project(RemoteInput_API VERSION 0.1.0)

add_library(RemoteInput_API RemoteInput_API.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})