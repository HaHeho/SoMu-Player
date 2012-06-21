# Install script for directory: /home/rico/Desktop/taglib-1.7.2/taglib

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/usr/local/lib/libtag.so.1.7.2")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/libtag.so.1.7.2"
         RPATH "")
  ENDIF(EXISTS "$ENV{DESTDIR}/usr/local/lib/libtag.so.1.7.2")
  FILE(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES
    "/home/rico/Desktop/taglib-1.7.2/taglib/libtag.so.1.7.2"
    "/home/rico/Desktop/taglib-1.7.2/taglib/libtag.so.1"
    "/home/rico/Desktop/taglib-1.7.2/taglib/libtag.so"
    )
  IF(EXISTS "$ENV{DESTDIR}/usr/local/lib/libtag.so.1.7.2")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/libtag.so.1.7.2")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF(EXISTS "$ENV{DESTDIR}/usr/local/lib/libtag.so.1.7.2")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "/home/rico/Desktop/taglib-1.7.2/taglib/tag.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/fileref.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/audioproperties.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/taglib_export.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/toolkit/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/asf/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/ogg/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/flac/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/ape/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/mpc/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/mp4/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/wavpack/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/trueaudio/cmake_install.cmake")
  INCLUDE("/home/rico/Desktop/taglib-1.7.2/taglib/riff/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

