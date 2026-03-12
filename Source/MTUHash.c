#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global or Defined Tables
// Expansion Table (E) - Maps 32 bits to 48 bits
int E_TABLE[48] = {
    32,  1,  2,  3,  4,  5,   // Row 1 [cite: 59-64]
     4,  5,  6,  7,  8,  9,   // Row 2 [cite: 65-70]
     8,  9, 10, 11, 12, 13,   // Row 3 [cite: 71-76]
    12, 13, 14, 15, 16, 17,   // Row 4 [cite: 76-78]
    16, 17, 18, 19, 20, 21,   // Row 5 [cite: 78-81]
    20, 21, 22, 23, 24, 25,   // Row 6 [cite: 81-83]
    24, 25, 26, 27, 28, 29,   // Row 7 [cite: 83-84]
    28, 29, 30, 31, 32,  1    // Row 8 [cite: 85]
};

// S-Box (S1) - 4 rows x 16 columns
int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},      // Row 0 [cite: 96-107]
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},     // Row 1 [cite: 108-118]
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},     // Row 2 [cite: 119-128]
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}      // Row 3 [cite: 129-141]
};

// Core Hash Function
void mtu_hash(const char *input_bits, char *output_bits, int rounds) {
    // 1. Convert input string to bit array
    // 2. Loop for 'rounds' (1 to 16)
    // 3. Perform Expansion (32 -> 48 bits) 
    // 4. Perform S-Box Substitution (48 -> 32 bits) 
    // 5. Store intermediate result if rounds == 1 [cite: 156]
}

int main(int argc, char *argv[]) {
    // Read from Hashin.txt [cite: 154]
    // Call mtu_hash for 1 round -> Save to Out1.txt [cite: 156]
    // Call mtu_hash for 16 rounds -> Save to OutFinal.txt [cite: 157]
    return 0;
}
