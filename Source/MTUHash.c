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

void es_operation(const char *input, char *output) {
    char expanded[49]; // 48 bits + null terminator [cite: 32]
    char final_32[33]; // 32 bits + null terminator [cite: 148]
    final_32[0] = '\0';

    // Step 1: Expansion (32-bit -> 48-bit) [cite: 145]
    for (int i = 0; i < 48; i++) {
        expanded[i] = input[E_TABLE[i] - 1]; // E_TABLE is 1-indexed [cite: 59]
    }
    expanded[48] = '\0';

    // Step 2: Substitution (8 chunks of 6-bit -> 4-bit) [cite: 146, 147]
    for (int i = 0; i < 8; i++) {
        char chunk[7];
        strncpy(chunk, &expanded[i * 6], 6);
        chunk[6] = '\0';

        // Get S-Box indices [cite: 150]
        int row = ((chunk[0] - '0') << 1) | (chunk[5] - '0');
        int col = ((chunk[1] - '0') << 3) | ((chunk[2] - '0') << 2) | 
                  ((chunk[3] - '0') << 1) | (chunk[4] - '0');

        int val = S1[row][col]; // [cite: 150]

        // Convert decimal val to 4 bits [cite: 147]
        for (int j = 3; j >= 0; j--) {
            final_32[(i * 4) + j] = (val % 2) + '0';
            val /= 2;
        }
    }
    final_32[32] = '\0';
    strcpy(output, final_32);
}

int main(int argc, char *argv[]) {
    // 1. Read input from Hashin.txt (or argv[1] as per grader instructions) [cite: 154, 207]
    char current_hash[33];
    FILE *fin = fopen(argv[1], "r");
    fscanf(fin, "%s", current_hash);
    fclose(fin);

    char next_hash[33];
    for (int round = 1; round <= 16; round++) {
        es_operation(current_hash, next_hash);
        strcpy(current_hash, next_hash);

        // Task 1: Save Round 1 output [cite: 156]
        if (round == 1) {
            FILE *f1 = fopen("Out1.txt", "w");
            fprintf(f1, "%s", current_hash);
            fclose(f1);
        }
    }

    // Task 1: Save Final output [cite: 157, 160]
    FILE *fout = fopen("OutFinal.txt", "w");
    fprintf(fout, "%s", current_hash);
    fclose(fout);

    return 0;
}