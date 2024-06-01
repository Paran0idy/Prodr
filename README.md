# Prodr
A language and compiler for ML


## Example
```mlir
%0 = prodr.constant dense<[1.0, 2.0]> : tensor<2xf64>
```


## Build

### 1. build custom llvm-project
We need to build our own MLIR in the local machine in advance. Please follow the build instruction for [MLIR](https://mlir.llvm.org/getting_started/) here.

### 2. build Prodr
```bash
mkdir build && cd build
cmake -G Ninja ..
ninja
```


## Prerequisites
+ LLVM
+ MLIR
+ CMake
+ Ninja