# Snake and Apple Game in C++

A simple console-based Snake game built using C++. This project recreates the classic Snake gameplay experience directly in the terminal.

## Game Features

- Snake controlled with `W`, `A`, `S`, `D` keys
- Random fruit spawning
- Snake grows when fruit is eaten
- Wall wrapping: exiting one side enters from the other
- Game ends on self-collision
- Score is displayed and increases as you collect fruit

## System Requirements

- Operating System: Windows
- Compiler: g++ or any standard C++ compiler
- Terminal: Must support Windows headers (`conio.h`, `windows.h`)

## How to Compile and Run

1. Copy the code into a file named `snake_game.cpp`
2. Open your terminal and navigate to the file directory
3. Compile using the following command:

   ```bash
   g++ snakegame.cpp -o snakegame
