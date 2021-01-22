# CMake CPU detect

![ci](https://github.com/scivision/cmake-cpu-detect/workflows/ci/badge.svg)

These CMake functions detect the CPU arch for Intel CPUs on Linux, MacOS and Windows.
Intel oneAPI `-xHost` or `/QxHost` is like `-march=native` on GCC or Clang.
Better runtime performance can come from enabling the features of the Host CPU.

However, compiler bugs can lead to runtime errors, so using `-march=native` everywhere can make problems.
`-mtune=` hasn't made this problem for us.

Related: [CMake project](https://github.com/miurahr/cmake-optimize-architecture-flag)
that reveals numerous flags for fine-grained CPU capabilities

## Result variables

* `HOST_ARCH` for Intel CPUs, the generation name e.g. kabylake suitable for `-mtune=`
* `HOST_FLAGS` more optimal tuning flags for host system. Sacrifices portability for performance.
* `HAS_AVX`
* `HAS_AVX2`
* `HAS_NEON`

## Usage

```sh
cmake -B build
cmake --build build
```

If AVX2 is available, the example can be checked:

```sh
cd build
ctest
```

To use in an actual project, copy DetectHostArch.cmake to your project directory.
Then do like the part in `if(BUILD_TESTING)` in this project's CMakeLists.txt.
