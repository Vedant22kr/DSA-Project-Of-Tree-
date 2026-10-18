
# BST Height Analysis

## Project Overview
This project analyzes the height of Binary Search Trees (BSTs) constructed using ascending, descending, and randomly ordered sequences containing the same elements.

## Problem Statement
Write a C++ program to construct BSTs using ascending, descending, and randomly ordered sequences containing the same elements and compare their heights.

## Objectives
- Construct BSTs using insertion.
- Generate ascending, descending, and random sequences.
- Calculate the height of each BST.
- Compare the effect of insertion order on tree height.
- Understand the worst-case performance of an unbalanced BST.

## Technologies Used
- C++
- Data Structures
- Binary Search Tree
- Visual Studio Code / Dev-C++

## Project Structure
```text
BST-Height-Analysis/
├── README.md
├── src/
│   └── main.cpp
└── documentation/
    ├── algorithm.md
    ├── sample-output.txt
    └── project-report.pdf
```

## How to Compile
```bash
g++ -std=c++11 src/main.cpp -o bst_height
```

## How to Run
```bash
./bst_height
```

On Windows, run:
```bash
bst_height.exe
```

## Expected Results
- Ascending sequence: height = n.
- Descending sequence: height = n.
- Random sequence: height depends on insertion order.

## Conclusion
The height of a normal BST depends on the order in which elements are inserted. Ascending and descending sequences create skewed trees, whereas random insertion often creates a shorter tree.

## Author
Add your name, class, roll number, and college here.
