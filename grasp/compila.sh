#!/bin/sh

echo "Compilando..."

g++ -pedantic -g -o ./main.exe ./src/grasp.cpp ./main.cpp -lm

./main.exe