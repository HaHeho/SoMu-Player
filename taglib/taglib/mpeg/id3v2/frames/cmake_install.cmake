# Install script for directory: /home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames

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
  FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/privateframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/home/rico/Desktop/taglib-1.7.2/taglib/mpeg/id3v2/frames/urllinkframe.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

