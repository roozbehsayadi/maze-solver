# Maze Solver

## Origin Story

I saw a tweet some time ago, That someone had shared a gigantic maze made by himself. I wanted to write a hobby project for some time, so I grabbed the opportunity and wrote a code to solve it for me.

The tweet: https://twitter.com/COOLSKELETON965/status/1757514471201783944

## What Can it Do

With latest changes, this project can solve the maze `maze_1.jpg` available in the `assets` folder. 
Run the program, click on two points to determine the start and the end point, and the watch it represent a path between these points.

Currently, it's a super-simple project with the most basic approach to the problem. It will get better in future (a near one, I hope).

## How to Compile and Run

You need to have these installed on your computer:
* `CMake`
* `OpenCV V4`
* `SDL2`
* `SDL2_Image`

It took me DAYS to configure these libraries to work with my CMake configuration.
Here's a couple of advices for you if you're trying to compile this code on your computer:
* Install the libraries with their CMake files, not their packages on `apt`. In my experience, installing with `apt` does not generate their CMake files correctly.
* Follow the installation steps thoroughly, or you may miss the `sudo make install` step like me.
* If you have any problem compiling the code, use `--trace-expand` command to see the details of CMake process. `cmake --trace-expand --build . >trace.txt 2>&1 `

After installing the requirements, compile the source codes and run the executable file:

```bash
# Compile
mkdir -p build && cd build
cmake ..
cmake --build .

# Run
./MazeSolver
```
