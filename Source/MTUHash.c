#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating an array with the expansion table values 
int E_TABLE[48] = {
    32,  1,  2,  3,  4,  5,   
     4,  5,  6,  7,  8,  9,   
     8,  9, 10, 11, 12, 13,   
    12, 13, 14, 15, 16, 17,   
    16, 17, 18, 19, 20, 21,   
    20, 21, 22, 23, 24, 25,   
    24, 25, 26, 27, 28, 29,   
    28, 29, 30, 31, 32,  1    
};

// Creating the S-Box as a 2D array with the given values
int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},     
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},     
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},     
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}      
};

void es_operation(const char *input, char *output) {
    char expanded[49]; // 48 bits + null terminator 
    char final_32[33]; // 32 bits + null terminator 
    final_32[0] = '\0';

    // Step 1: Expansion 
    for (int i = 0; i < 48; i++) {
        expanded[i] = input[E_TABLE[i] - 1]; // E_TABLE is 1-indexed
    }
    expanded[48] = '\0';

    // Step 2: Substitution 
    for (int i = 0; i < 8; i++) {
        char chunk[7];
        strncpy(chunk, &expanded[i * 6], 6);
        chunk[6] = '\0';

        // Get S-Box indices 
        int row = ((chunk[0] - '0') << 1) | (chunk[5] - '0');
        int col = ((chunk[1] - '0') << 3) | ((chunk[2] - '0') << 2) | 
                  ((chunk[3] - '0') << 1) | (chunk[4] - '0');

        int val = S1[row][col]; // 

        // Convert decimal val to 4 bits
        for (int j = 3; j >= 0; j--) {
            final_32[(i * 4) + j] = (val % 2) + '0';
            val /= 2;
        }
    }
    final_32[32] = '\0';
    strcpy(output, final_32);
}

int main(int argc, char *argv[]) {
    // 1. Read input from Hashin.txt
    char current_hash[33];
    FILE *fin = fopen(argv[1], "r");
    fscanf(fin, "%s", current_hash);
    fclose(fin);

    char next_hash[33];
    for (int round = 1; round <= 16; round++) {
        es_operation(current_hash, next_hash);
        strcpy(current_hash, next_hash);

        // Save first round output to Out1.txt
        if (round == 1) {
            FILE *f1 = fopen("Out1.txt", "w");
            fprintf(f1, "%s", current_hash);
            fclose(f1);
        }
    }

    // Save final output to OutFinal.txt
    FILE *fout = fopen("OutFinal.txt", "w");
    fprintf(fout, "%s", current_hash);
    fclose(fout);

    return 0;
}