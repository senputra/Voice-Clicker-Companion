# Install script for directory: /Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include(BundleUtilities)
    fixup_bundle("${CMAKE_INSTALL_PREFIX}/Voice_Clicker_Companion.app" "" "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1/microphone/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1/remote_input/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1/zero_config/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1/control_panel/cmake_install.cmake")
  include("/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1/gui/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/build1/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
