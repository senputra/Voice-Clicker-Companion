set(PROJECT_NAME Buffer)

set(BUFFER_HEADERS
    Buffer.h)

set(BUFFER_SOURCES
    Buffer.cpp)

add_library(${PROJECT_NAME} STATIC
    ${BUFFER_SOURCES} 
    ${BUFFER_HEADERS})