cmake_minimum_required(VERSION 3.12...3.20)

project(CPUflags
  LANGUAGES C CXX
  DESCRIPTION "Demonstrates optimal compiler flags.")

include(CTest)

set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)

include(DetectHostArch.cmake)
detect_host_arch()
message(STATUS "${CMAKE_CXX_COMPILER_ID} flags: ${HOST_FLAGS}")

# -- example code

if(BUILD_TESTING)
if(HAS_AVX2)
  add_executable(avx2demo avx2.cpp)
  target_compile_options(avx2demo PRIVATE ${HOST_FLAGS})
  target_compile_features(avx2demo PRIVATE cxx_std_11)

  add_test(NAME AVX2 COMMAND $<TARGET_FILE:avx2demo>)
endif(HAS_AVX2)

if(HAS_NEON)
  add_executable(neon neon.c)
  target_compile_options(neon PRIVATE ${HOST_FLAGS})

  add_test(NAME NEON COMMAND $<TARGET_FILE:neon>)
endif(HAS_NEON)

endif(BUILD_TESTING)
