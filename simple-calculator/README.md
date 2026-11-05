# Simple Calculator

A simple calculator program written in C.

## Description

The program prints a welcome line, displays a menu, and allows quitting with option 0.

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Usage

./calculator

## Number handling

- A and B are read as integers.
- Add, subtract and multiply give integer results.
- Divide gives a decimal result (10 / 4 = 2.5, 10 / 2 = 5).
- Division by zero prints: Error: division by zero
