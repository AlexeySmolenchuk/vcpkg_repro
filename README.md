Repro for vcpkg issue
https://github.com/microsoft/vcpkg/issues/38153

Clone, checkout **main** branch, configure cmake.
```
git clone git@github.com:AlexeySmolenchuk/vcpkg_repro_38153.git --recursive
cd vcpkg_repro_38153
git checkout main
mkdir build
cd build
cmake ..
```
After bootstrapping I'm getting this error:
```
[cmake] CMake Error at vcpkg/scripts/buildsystems/vcpkg.cmake:859 (_find_package):
[cmake]   Could not find a package configuration file provided by "lcms2" with any of
[cmake]   the following names:
[cmake] 
[cmake]     lcms2Config.cmake
[cmake]     lcms2-config.cmake
...
-- Configuring incomplete, errors occurred!
```

Checkout to **workaround** branch, which explicitly set [lcms] as dependency. https://github.com/AlexeySmolenchuk/vcpkg_repro_38153/blob/workaround/vcpkg.json#L3 \
Configure cmake.
```
git checkout workaround
cmake ..
```
Now it's working.

Details:
OS Windows 10\
cmake-3.27
