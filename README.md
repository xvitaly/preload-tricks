# preload-tricks

[![GCC CI status](https://github.com/xvitaly/preload-tricks/actions/workflows/gcc.yml/badge.svg)](https://github.com/xvitaly/preload-tricks/actions/workflows/gcc.yml)
[![Clang CI status](https://github.com/xvitaly/preload-tricks/actions/workflows/clang.yml/badge.svg)](https://github.com/xvitaly/preload-tricks/actions/workflows/clang.yml)

## About

Example repository for [our article](https://www.easycoding.org/2021/08/31/obxodim-proverku-na-nalichie-prav-superpolzovatelya.html). Contains a sample program with superuser privileges checking (using the `getuid()` function) and a special example of a shim library that can be used to bypass these checks.

## Build

```
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo -DENABLE_TESTS:BOOL=ON
cmake --build build
```

## Test application (nornal run)

```
cd build
./example-root
```

## Test application (with LD_PRELOAD)

```
cd build
LD_PRELOAD="./libtricks.so" ./example-root
```

## Unit tests

```
cd build
ctest --output-on-failure
```
