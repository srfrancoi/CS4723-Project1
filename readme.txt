Project 1: MTUHash Implementation
Author: Seth Francois

--- Compilation Instructions ---
This project was developed on Linux and can be compiled using gcc.

1. To compile the MTUHash program:
   gcc Source/MTUHash.c -o MTUHash

2. To compile the AECalculator program:
   gcc Source/AECalculator.c -o AECalculator

--- Running the Programs ---
The programs take an input file as a command-line argument.

1. To run MTUHash:
   ./MTUHash Hashin1.txt
   (Generates Out1.txt and OutFinal.txt)

2. To run AECalculator:
   ./AECalculator Hashin1.txt
   (Generates AFR.txt)

--- Project Structure ---
Proj1/
├── authors.txt
├── readme.txt
├── Results/
└── Source/
    ├── MTUHash.c
    └── AECalculator.c
