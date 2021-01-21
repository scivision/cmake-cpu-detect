cmake_minimum_required(VERSION 3.12)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Debug or Release")
endif()

project(CPU_AVX2
  LANGUAGES CXX
  DESCRIPTION "Demonstrates optimal compiler flags with AVX2, especially for Intel oneAPI")

include(CTest)

set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)

include(DetectHostArch.cmake)
detect_host_arch()
message(STATUS "${CMAKE_CXX_COMPILER_ID} flags: ${HOST_FLAGS}")

# -- example code

if(HAS_AVX2)
if(BUILD_TESTING)
  add_executable(avx2demo avx2.cpp)
  target_compile_options(avx2demo PRIVATE ${HOST_FLAGS})
  target_compile_features(avx2demo PRIVATE cxx_std_11)

  add_test(NAME AVX2 COMMAND $<TARGET_FILE:avx2demo>)
endif()
endif(HAS_AVX2)
