# Simplex-Tableau
NAME: AIYEPE HALIMAT OLUWADAMILOLA
MATRIC NUMBER: U22CS1019
DEPARTMENT: COMPUTER SCIENCE
USERNAME: U22CS1019

**SIMPLEX ALGORITHM IMPLEMENTATION IN C++**
**OVERVIEW**
This c++ program implements the Simplex Algorithm to solve Linear Programming Problems (LPPs). The program takes as inputs a set of constraints and an objective function, and outputs the optimal solution.
**FEATURES**
Implements the Simplex Algorithm for solving LPPs
Supports maximization and minimization problems
Handles constraints with equality and inequality relationships.
Outputs the optimal solution, including variable values and objective function values
**USAGE**
Compile the program using g++:g++ simplex.cpp -o simplex
Run the program: ./simplex
Enter the number of variables, constraints, and objective function coefficients when prompted
**EXAMPLE**
The program includes an example problem:
Maximize z=3x1+2x2
Subject to:
x1+x2<=4
2x1+x2<=5
x1,x2>=0

The program outputs the optimal solution:
Optimal solution:
x1=2.00
x2=2.00
Optimal value of the objective function: 10.00
**CODE STRUCTURE**
The program consists of the following files:
simplex.cpp: Main program file, containing the Simplex Algorithm implementation
Row.h: Header file defining the Row structure, used to represent each row in the simplex tableau
