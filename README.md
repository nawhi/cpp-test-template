# Test Project Template

A template C++ project using CMake and the Doctest framework.
Tested on MacOS and Ubuntu Linux, and should also work in VC++.

## Compilation instructions (Linux)
From project root:
```sh
# Create and cd into build folder
mkdir -p build
cd build
# Run CMake to boostrap Makefiles
cmake ..

# Compile and execute tests 
make check
```
