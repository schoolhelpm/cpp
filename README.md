# C++ Tutorial

This repository is a beginner-friendly introduction to C++. It starts with the
fundamentals and uses small, practical exercises to help new programmers build
confidence one concept at a time.

## What you can find here

- **`hello_world.cpp`** - An annotated first program that demonstrates:
  - including the input/output library with `#include <iostream>`
  - the `main()` function and return values
  - displaying text with `cout`
  - reading user input with `cin`
  - declaring variables and adding two integers
- **`practice_1.txt`** - Ten practice problems arranged from introductory to
  slightly more challenging:
  - greetings and formatted text
  - variables and integer arithmetic
  - division and the modulus operator
  - `float` and `double` values
  - characters and ASCII values
  - Boolean values and the `!` operator
  - a complete restaurant bill calculator

The repository also includes compiled example files created while practicing.
The source files, especially `hello_world.cpp`, are the recommended place to
read and experiment.

## Getting started

### 1. Install a C++ compiler

You need a compiler such as `g++`. On Ubuntu or Debian, you can install one
with:

```bash
sudo apt update
sudo apt install g++
```

### 2. Compile the example

From the repository directory, run:

```bash
g++ hello_world.cpp -o hello_world
```

### 3. Run the program

On Linux and macOS:

```bash
./hello_world
```

On Windows with MinGW:

```bash
hello_world.exe
```

The program asks for two numbers and prints their sum.

## Suggested learning path

1. Read the comments in `hello_world.cpp`.
2. Compile and run the program yourself.
3. Change the prompts and output messages.
4. Add another calculation, such as subtraction or multiplication.
5. Work through the questions in `practice_1.txt` in order.
6. Compare your solutions with the concepts used in the example.

Try to solve each exercise before looking for a solution. Experimenting with
different inputs is an important part of learning programming.

## Prerequisites

No previous C++ experience is required. Basic familiarity with running commands
in a terminal is helpful, but the examples are intended to explain the
fundamentals from the beginning.

## Goal

The goal of this repository is to provide a simple starting point for learning
C++ syntax, input and output, variables, data types, operators, and problem
solving through practice.
