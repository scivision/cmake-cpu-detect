cmake_minimum_required(VERSION 3.15)
project(cpu LANGUAGES C)

include(cpu_detect.cmake)

DetectHostArch()

if(HOST_ARCH)
  if(CMAKE_C_COMPILER_ID STREQUAL Intel)
    if(WIN32)
      message(STATUS "try compiling with: 'icl /arch:${HOST_ARCH}'")
    else()
      message(STATUS "try compiling with: 'icc -march=${HOST_ARCH}'")
    endif()
  else()
    message(STATUS "CPU detected: ${HOST_ARCH}")
  endif()
endif()