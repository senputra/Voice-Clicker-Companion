# Install script for directory: /Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Encodings

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Encodings/include/Poco" REGEX "/\\.svn$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/lib/libPocoEncodings.62.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.62.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.62.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.62.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.62.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/lib/libPocoEncodings.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libPocoEncodings.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco/PocoEncodingsTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco/PocoEncodingsTargets.cmake"
         "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Encodings/CMakeFiles/Export/lib/cmake/Poco/PocoEncodingsTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco/PocoEncodingsTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco/PocoEncodingsTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco" TYPE FILE FILES "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Encodings/CMakeFiles/Export/lib/cmake/Poco/PocoEncodingsTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco" TYPE FILE FILES "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Encodings/CMakeFiles/Export/lib/cmake/Poco/PocoEncodingsTargets-relwithdebinfo.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Poco" TYPE FILE FILES
    "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Poco/PocoEncodingsConfig.cmake"
    "/Users/praxiumsg/Projects/Voice Clicker Companion/Voice-Clicker-Companion/ZeroConfigModule/Poco/Poco/PocoEncodingsConfigVersion.cmake"
    )
endif()

