# MetaCall NodeJS C/C++ Example
An example of using C and C++ libraries from NodeJS by using MetaCall.

This example shows few capabilities:
    1) Loading C code from a `.c` file directly into NodeJS.
    2) Loading C++ code from a `.h` file and a compiled library `.so`. At the time of writting, MetaCall does not support loading `.cpp` files so your library must be compiled with a C/C++ compiler and the functions must be exported with C ABI, then it can be loaded into MetaCall. We support custom Rust ABI and we plan to support C++ ABI in the future, but it's not yet implemented.

For demonstrating the lastest feature implemented on MetaCall[[1]](https://github.com/metacall/core/pull/533)[[2]](https://github.com/metacall/core/pull/557), we will run the examples with `node` binary instead of `metacall`. This will provide full portability and removing the need of using MetaCall CLI for launching the scripts.

The idea is showing different ways to achieve the same objective, interop MetaCall with C/C++. The example is implemented by using Docker so it is fully reproducible, and CMake for building the C++ library.
