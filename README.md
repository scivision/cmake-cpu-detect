# CMake CPU detect

![ci](https://github.com/scivision/cmake-cpu-detect/workflows/ci/badge.svg)

These CMake functions detect the CPU arch for Intel CPUs on Linux, MacOS and Windows.
These can be useful for setting `-mtune` flag for Intel oneAPI.
GCC can simply use `-mtune=native` instead.

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

## Intel oneAPI

Intel oneAPI
[`-xHost` or `/QxHost`](https://software.intel.com/content/www/us/en/develop/documentation/fortran-compiler-oneapi-dev-guide-and-reference/top/compiler-reference/compiler-options/compiler-option-details/code-generation-options/xhost-qxhost.html)
is like `-march=native -mtune=native` on GCC or Clang.
Better runtime performance can come from enabling the features of the host CPU.

If you choose to not use `-xHost` or `/QxHost` then the
[mtune](https://software.intel.com/content/www/us/en/develop/documentation/fortran-compiler-oneapi-dev-guide-and-reference/top/compiler-reference/compiler-options/compiler-option-details/code-generation-options/mtune-tune.html)
option can be used.
There is currently no `-mtune=native` for oneAPI, so this CMake CPU arch detection can help.
