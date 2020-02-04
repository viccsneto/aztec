@echo off
rm -rf build
mkdir build
cd build
cmake -DCMAKE_GENERATOR_PLATFORM=x64 ..
mkdir Debug
copy ..\aztec\third_party\SFML\extlibs\bin\x64\*.* Debug
mkdir Release
copy ..\aztec\third_party\SFML\extlibs\bin\x64\*.* Release
