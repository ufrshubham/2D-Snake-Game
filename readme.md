# 2D Snake Game

## A simple game created using C++ and SFML

---

### What it looks like?

![Demo](Demo.gif)

### This game has multiple states

- Main Menu State - Displays main menu
- Game Play State - The actual game play
- Pause Game State - Pause screen
- Game Over State - Displays game over screen

### Features

- Snake can be controlled with arrow keys
- Snake automatically advances 16px
- Food gets randomly placed
- Snake can eat food to grow in length
- Each food increase player score by 1 point

### Build Instructions

- Requirements
  - Git
  - CMake
  - C++ Compiler

- Steps

    ```bash
    # Clone this project
    $ git clone https://github.com/ufrshubham/2D-Snake-Game

    # Go to project root
    $ cd 2D-Snake-Game

    # Checkout cmake-build branch
    $ git checkout cmake-bulid

    # Pull SFML as submodule
    $ git submodule update --init

    # Create a folder for build
    $ mkdir build

    # Go to build folder
    $ cd build

    # Generate project files
    $ cmake ..
    ```

- This will generate project files using default cmake generator for your platform. For example:

  - on `Windows` with `Visual Studio` installed, it will generate a `.sln`
  - on `Linux` with `make` installed, it will generate a `Makefile`
  - on `Mac` with `xcode` installed, it will generate a `.xcodeproj`

### Audio assets

None of the audio assets are made by me. Here are links to their original source and authors:

- [Spinning out.ogg](https://joshuuu.itch.io/short-loopable-background-music) by [joshuuu](https://joshuuu.itch.io/)

- [Death 002.wav](https://edwardcufaude.itch.io/soundfxpack1) by [edwardcufaude](https://edwardcufaude.itch.io/)

- [Simple Coin 006.wav](https://edwardcufaude.itch.io/soundfxpack1) by [edwardcufaude](https://edwardcufaude.itch.io/)
