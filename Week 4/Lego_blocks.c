#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

#define MOD 1000000007

long long mod_pow(long long base, int exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int legoBlocks(int n, int m) {
    long long row[m+1];
    long long total[m+1];
    long long valid[m+1];

    // ways to build a row of length i
    row[0] = 1;
    for (int i = 1; i <= m; i++) {
        row[i] = 0;
        for (int k = 1; k <= 4; k++) {
            if (i - k >= 0)
                row[i] = (row[i] + row[i-k]) % MOD;
        }
    }

    // total ways (ignoring cracks)
    for (int i = 1; i <= m; i++) {
        total[i] = mod_pow(row[i], n);
    }

    // compute valid walls using inclusion-exclusion
    valid[0] = 0;
    for (int i = 1; i <= m; i++) {
        valid[i] = total[i];
        for (int k = 1; k < i; k++) {
            valid[i] = (valid[i] - (valid[k] * total[i-k]) % MOD + MOD) % MOD;
        }
    }

    return (int) valid[m];
}