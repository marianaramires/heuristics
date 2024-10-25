@echo off

echo Compilando...
g++ -pedantic -g -o main.exe ./src/grasp.cpp ./main.cpp

START main.exe