#!/bin/sh

# Required additional stuff (on Ubuntu)
# apt-get install libsdl1.2-dev libsdl-gfx1.2-dev build-essential

# Remove old binary
rm miniduel2

# Compile main.cpp into bin.out
g++ -Wall -o miniduel2 main.cpp -lSDL -lSDL_gfx

# Run the resulting program
./miniduel2
