# Pong Recreation (Linux Support)

This is just a recreation of [Pong Game](https://en.wikipedia.org/wiki/Pong) programmed in C using [raylib](https://www.raylib.com/).

# How to build

It assumes that you already have installed `build-essential`.

1. Download and Install [CMake 4.0.2](https://cmake.org/).
2. Open a terminal/cmd.
3. Clone this repository.
4. type `$ cmake -S . -B build`.
5. Then, type `$ cmake --build build`.
6. Inside the `build/game_bin/` folder you can execute the binaries of the program.

# How to generate an icon file

1. Install xxd (if not installed).
2. Place a .png file called `game_icon.png` (512×512 recommended size) in `assets/` folder.
3. In the root folder, execute, in a terminal, `$ bash icon_generate.sh`.