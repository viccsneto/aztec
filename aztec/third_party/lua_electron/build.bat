@echo off
md build
rm -rf build/*
cd build
cmake ..
cmake --build .
cp -rf ..\USE .
cp  ..\run.bat .
cp  ..\rund.bat .
