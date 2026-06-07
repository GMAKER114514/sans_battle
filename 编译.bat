@echo off
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build . --parallel

cd ..
if not exist .\out mkdir .\out
xcopy /E /I /Y ".\res" ".\out\res\"

.\out\SansBattle.exe