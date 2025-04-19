#include <iostream>
using namespace std;
const int N = 9;
int grid[N][N] = 
{
    {3, 0, 6, 5, 7, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 8, 6, 3, 0, 0}
};
bool isSafe(int row, int col, int num) 
{
    for (int x = 0; x < N; x++) 
	{
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}
bool solveSudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku())
                            return true;
                        grid[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true;
}
void printGrid() 
{
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
int main() 
{
    if (solveSudoku()) 
	{
        printGrid();
    } 
	else 
	{
        cout << "No solution exists\n";
    }
    return 0;
}

