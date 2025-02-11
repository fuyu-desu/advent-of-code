# Advent of Code

This repository contains my solutions for [Advent of Code](https://adventofcode.com/), implemented in C++.

## How to Use

Each solution is a standalone C++ source file that needs to be compiled before execution. The input for each problem should be stored in a separate file.

### Compilation

Compile the C++ file using a C++ compiler (e.g., `g++`):

```sh
# Example for day-1.cpp
g++ day-1.cpp -o a # Generates an executable named 'a'
```

If the program runs slowly, you can enable optimizations using the `-O2` flag:

```sh
g++ day-1.cpp -o a -O2  # Optimized compilation for better performance
```

### Running the Solution

Store the problem input in a file (e.g., `q`) **in the same folder as the executable**, then run the compiled executable while redirecting the input:
Note that filenames must be exact, and `q` is different from `q.txt` or `Q` due to case sensitivity.

#### On Windows:
```sh
a < q
```

#### On Linux/macOS:
```sh
./a < q
```

If the input file is in a different directory, provide the relative or absolute path:

```sh
./a < path/to/q
```

## Repository Structure

```
/advent-of-code
  ├── .gitignore
  ├── README.md
  ├── 2024/
  │   ├── day-1.cpp
  │   ├── day-1-p2.cpp
  │   ├── day-2.cpp
  │   ├── day-2-p2.cpp
  │   ├── ...
  ├── 2023/
  ├── 2022/
  ├── ...

```

- `day-X.cpp`: Solution for Day X, Part 1.
- `day-X-p2.cpp`: Solution for Day X, Part 2.
- `README.md`: This documentation.

## Notes

- Ensure you have a C++ compiler installed (e.g., `g++` for GCC, `clang++`, or MSVC).
- You can change the executable name by modifying the `-o` flag in the compilation command.

Happy coding! 🎄

