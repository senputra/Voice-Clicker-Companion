cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME ServiceDiscovery_API)
project(${PROJECT_NAME} VERSION 0.1.0)

set(POCO_HEADERS ./Poco/DNSSD/include/
    ./Poco/DNSSD/Bonjour/include/
    ./Poco/DNSSD/Avahi/include/
    ./Poco/Net/include/
    ./Poco/Foundation/include/)

# set(POCO_HEADERS ${CMAKE_SOURCE_DIR}/Poco/DNSSD/include/
#     ${CMAKE_SOURCE_DIR}/Poco/DNSSD/Bonjour/include/
#     ${CMAKE_SOURCE_DIR}/Poco/DNSSD/Avahi/include/
#     ${CMAKE_SOURCE_DIR}/Poco/Net/include/
#     ${CMAKE_SOURCE_DIR}/Poco/Foundation/include/)

add_library(${PROJECT_NAME} ServiceDiscovery_API.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${POCO_HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Poco/lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

