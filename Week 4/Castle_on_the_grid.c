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
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(int n, char** grid, int startX, int startY, int goalX, int goalY) {
    // Direction vectors: up, down, left, right
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Queue for BFS
    int qx[n * n], qy[n * n], qd[n * n];
    int front = 0, back = 0;

    // Visited array
    int **visited = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        visited[i] = calloc(n, sizeof(int));
    }

    // Start BFS
    qx[back] = startX;
    qy[back] = startY;
    qd[back] = 0;
    visited[startX][startY] = 1;
    back++;

    while (front < back) {
        int x = qx[front];
        int y = qy[front];
        int d = qd[front];
        front++;

        // Reached goal
        if (x == goalX && y == goalY) {
            // Free memory
            for (int i = 0; i < n; i++) free(visited[i]);
            free(visited);
            return d;
        }

        // Explore 4 directions
        for (int dir = 0; dir < 4; dir++) {
            int nx = x, ny = y;

            // Keep moving in that direction until blocked
            while (1) {
                nx += dx[dir];
                ny += dy[dir];

                // Out of bounds or blocked
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 'X') {
                    break;
                }

                if (!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    qx[back] = nx;
                    qy[back] = ny;
                    qd[back] = d + 1;
                    back++;
                }
            }
        }
    }

    // If unreachable (should not happen per problem statement)
    for (int i = 0; i < n; i++) free(visited[i]);
    free(visited);
    return -1;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** grid = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    char** first_multiple_input = split_string(rtrim(readline()));

    int startX = parse_int(*(first_multiple_input + 0));

    int startY = parse_int(*(first_multiple_input + 1));

    int goalX = parse_int(*(first_multiple_input + 2));

    int goalY = parse_int(*(first_multiple_input + 3));

    int result = minimumMoves(n, grid, startX, startY, goalX, goalY);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
