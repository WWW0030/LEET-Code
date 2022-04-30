#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int islandPerimeterHelper(int** grid, int** BeenThere, int gridSize, int*gridColSize, int curCol, int curRow, int ans) {
    if(grid[curCol][curRow] == 0) return ans;
    if(BeenThere[curCol][curRow] == 1) return ans;
    BeenThere[curCol][curRow] = 1;
    if(curCol != 0) {
        if (grid[curCol-1][curRow] == 0) ++ans;
        else ans = islandPerimeterHelper(grid, BeenThere, gridSize, gridColSize, curCol - 1, curRow, ans);
    }
    else ++ans;
    if(curRow != 0) {
        if (grid[curCol][curRow - 1] == 0) ++ans;
        else ans = islandPerimeterHelper(grid, BeenThere, gridSize, gridColSize, curCol, curRow - 1, ans);
    }
    else ++ans;
    if(curCol != gridSize - 1) {
        if(grid[curCol + 1][curRow] == 0) ++ans;
        else ans = islandPerimeterHelper(grid, BeenThere, gridSize, gridColSize, curCol + 1, curRow, ans);
    }
    else ++ans;
    if(curRow != *gridColSize - 1) {
        if(grid[curCol][curRow + 1] == 0) ++ans;
        else ans = islandPerimeterHelper(grid, BeenThere, gridSize, gridColSize, curCol, curRow + 1, ans);
    }
    else ++ans;
    return ans;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int **BeenThere = malloc(sizeof(int*) * gridSize);
    int startRow = 0;
    int startCol = 0;
    for(int i = 0; i < gridSize; ++i) {
        int *row = malloc(sizeof(int) * *gridColSize);
        for (int m = 0; m < *gridColSize; ++m) {
            if(grid[i][m] == 1) {
                startCol = i;
                startRow = m;
            }
            row[m] = 0;
        }
        BeenThere[i] = row;
    };
    return islandPerimeterHelper(grid, BeenThere, gridSize, gridColSize, startCol, startRow, 0);
}