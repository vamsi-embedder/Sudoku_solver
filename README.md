# Sudoku_solver
3rd project 
# Sudoku Solver in C++

## Description
This project is a console-based Sudoku Solver developed using C++. The program automatically solves a 9×9 Sudoku puzzle using the Backtracking Algorithm and displays the completed Sudoku grid.

The project demonstrates important programming concepts such as:
- Recursion
- Backtracking
- 2D Arrays
- Conditional Logic
- Algorithm Design

---

## Features
- Sudoku Grid Representation using 2D Arrays
- Automatic Sudoku Solving
- Backtracking Algorithm
- Row Validation
- Column Validation
- 3×3 Subgrid Validation
- Recursive Problem Solving
- Console-Based Output

---

## Technologies Used
- C++
- Recursion
- Backtracking Algorithm
- Arrays
- Conditional Statements

---

## Sudoku Rules Implemented
The program checks:
- No repeated number in a row
- No repeated number in a column
- No repeated number in a 3×3 subgrid

---

## How the Solver Works

### Step 1
Find an empty cell (`0`).

### Step 2
Try numbers from `1` to `9`.

### Step 3
Check whether the number is valid:
- Row check
- Column check
- 3×3 box check

### Step 4
If valid:
- place number
- recursively solve remaining cells

### Step 5
If stuck:
- remove number
- try next possibility

This process continues until the puzzle is solved.

---

## Project Structure

```text
CodeAlpha_Sudoku_Solver/
│
├── sudoku.cpp
├── README.md
├── output.png
└── report.pdf
