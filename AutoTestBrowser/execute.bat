@echo off
if exist ..\build\release\aztecapp.exe (
  ..\build\release\aztecapp.exe %1
  pause
  exit
)
if exist ..\build\debug\aztecapp.exe (
  ..\build\debug\aztecapp.exe %1
  pause
  exit
)

if exist .\release\aztecapp.exe %1 (
  .\release\aztecapp.exe %1
  pause
  exit
)
if exist .\debug\aztecapp.exe (
  .\debug\aztecapp.exe %1
  pause
  exit
)

echo Couldn't find aztecapp.exe under ..\build\release\ or ..\build\debug\
pause
