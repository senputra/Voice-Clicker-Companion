cmake_minimum_required(VERSION 3.0.0)

project(Voice_Clicker_Companion VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_library(Buffer STATIC ${CMAKE_SOURCE_DIR}/Buffer/Buffer.cpp)
target_link_directories(Buffer PRIVATE ${CMAKE_SOURCE_DIR}/Buffer)


add_executable(${PROJECT_NAME} main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Voice Clicker Companion")
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/libBuffer.a)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# include(CPack)
