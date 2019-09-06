set(PROJECT_NAME "ControlPanel")

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED OFF)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.70.0) 
if(Boost_FOUND)
    include_directories(
        ${Boost_INCLUDE_DIRS}
        ${POCO_HEADERS}
        ) 

    set(CONTROLPANEL_HEADERS
        ControlPanel.h
        SocketHelper.h)

    set(CONTROLPANEL_SOURCES
        ControlPanel.cpp
        SocketHelper.cpp)

    add_library(${PROJECT_NAME} STATIC
        ${CONTROLPANEL_SOURCES} 
        ${CONTROLPANEL_HEADERS}
        )

    target_include_directories(${PROJECT_NAME} PUBLIC ${POCO_HEADERS})

    target_link_libraries(${PROJECT_NAME} 
        ${Boost_LIBRARIES}
        ${POCO_LINK_LIBRAIES}
        )
        target_link_libraries(${PROJECT_NAME} PUBLIC
            Microphone
            RemoteInput
            ServiceDiscovery)
endif()
set(CONTROLPANEL_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
