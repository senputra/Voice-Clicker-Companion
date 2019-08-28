# Install script for directory: /Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco" TYPE FILE FILES
    "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Poco/PocoConfig.cmake"
    "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Poco/PocoConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Foundation/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Encodings/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/XML/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/JSON/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Util/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Net/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
