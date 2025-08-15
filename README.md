# Pong Recreation

This is just a recreation of [Pong Game](https://en.wikipedia.org/wiki/Pong) programmed in C using [raylib](https://www.raylib.com/).

# How to build

It assumes that you already have installed raylib and a C/C++ compiler (mingw64 gcc compiler or w64devkit containing in raylib). It also assumes that you're using Windows as an operating system. Other platforms were not tested yet, but it's probably easier.

1. Download and Install [CMake](https://cmake.org/).
2. Open a terminal/cmd.
3. Clone this repository.
4. type `$ cmake -G "MinGW Makefiles" -S . -B build`.
5. Then, type `$ cmake --build build`.
6. Inside the `build/game_bin/` folder you can execute the binaries of the program.

# How to generate an icon file

1. Place a .png file called `game_icon.png` (512×512 recommended size) in `assets/` folder.
2. In the root folder, execute `icon_generate.cmd`.