# CMake CPU detect

![ci](https://github.com/scivision/cmake-cpu-detect/workflows/ci/badge.svg)

These CMake functions detect the CPU arch for Intel CPUs on Linux, MacOS and Windows.
Intel oneAPI `-xHost` or `/QxHost` is like `-march=native` on GCC or Clang.
Better runtime performance can come from enabling the features of the Host CPU.
However, compiler bugs can lead to runtime errors, so using `-march=native` everywhere can make problems.
`-mtune=` hasn't made this problem for us.

## Result variables

The variable `HOST_ARCH` is set in the parent scope.
`HOST_ARCH` is empty if CPU arch is not known.

## Usage

```sh
cmake -B build
cmake --build build
cd build
ctest
```

To use in an actual project, copy DetectHostArch.cmake to your project directory.
Then do like the part in `if(BUILD_TESTING)` in this project's CMakeLists.txt.
