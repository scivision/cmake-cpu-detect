# CMake CPU detect

![ci](https://github.com/scivision/cmake-cpu-detect/workflows/ci/badge.svg)

These CMake functions detect the CPU arch for Intel CPUs on Linux, MacOS and Windows.
We focused on Intel CPUs since the Intel compilers (including oneAPI) don't currently have automatic CPU detection.
To use `-march=` features of Intel compilers, `-march=native` is undocumented and does not actually detect the CPU arch.
For CMake with Intel compilers these functions help yield better runtime performance by enabling the features of the Host CPU.
The same technique could be used for AMD, ARM, CUDA, etc. in the future.

## Demo

```sh
cmake -B build
```

will print the CPU family e.g. "icelake-client".
