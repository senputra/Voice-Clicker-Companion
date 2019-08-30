set(PROJECT_NAME ServiceDiscovery)
project(${PROJECT_NAME} VERSION 0.1.0)
set(POCO_BASE /Users/praxiumsg/Projects/poco)

set(POCO_HEADERS 
    ${POCO_BASE}/Poco/DNSSD/include/
    ${POCO_BASE}/Poco/DNSSD/Bonjour/include/
    ${POCO_BASE}/Poco/DNSSD/Avahi/include/
    ${POCO_BASE}/Poco/Net/include/
    ${POCO_BASE}/Poco/Foundation/include/
    PARENT_SCOPE)

set(POCO_LINK_LIBRARIES
    ${CMAKE_CURRENT_SOURCE_DIR}/Poco/lib
    PARENT_SCOPE)

set(SERVICEDISCOVERY_HEADERS
    ServiceDiscovery.h)

set(SERVICEDISCOVERY_SOURCES
    ServiceDiscovery.cpp)

add_library(${PROJECT_NAME} STATIC 
    ${SERVICEDISCOVERY_SOURCES} 
    ${SERVICEDISCOVERY_HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${POCO_BASE}/Poco/DNSSD/include/)
target_include_directories(${PROJECT_NAME} PRIVATE ${POCO_BASE}/Poco/DNSSD/Bonjour/include/)
target_link_libraries(${PROJECT_NAME} PRIVATE ${POCO_BASE}/Poco/lib/Darwin/x86_64/)


