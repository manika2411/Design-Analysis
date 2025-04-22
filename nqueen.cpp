#include <iostream>
using namespace std;

const int MAX = 20;
int board[MAX]; // board[i] = column number where queen is placed in row i
int n;
bool found = false;

bool isSafe(int row, int col) 
{
    for (int i = 1; i < row; i++) 
	{
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) 
		{
            return false;
        }
    }
    return true;
}
void printSolution() 
{
    cout << "[";
    for (int i = 1; i <= n; i++) 
	{
        cout << board[i];
        if (i != n) cout << ", ";
    }
    cout<<"]\n";
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= n; j++) 
		{
            if (board[i] == j) 
			{
                cout << "1 ";
            } 
			else 
			{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void solve(int row) 
{
    if (row > n) 
	{
        printSolution();
        found = true;
        return;
    }
    for (int col = 1; col <= n; col++) 
	{
        if (isSafe(row, col)) 
		{
            board[row] = col;
            solve(row + 1);
            if (found) 
				return;
        }
    }
}
int main() 
{
	cout<<"enter size of chess board:";
    cin >> n;
    solve(1);
    if (!found) 
	{
        cout << "No solution exists\n";
    }
    return 0;
}
