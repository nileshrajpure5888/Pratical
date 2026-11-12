#include <iostream>
using namespace std;

#define N 4

// Print the chessboard
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

// Check whether a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col)
{
    // Check the same row on the left
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower-left diagonal
    for (int i = row, j = col;
         j >= 0 && i < N;
         i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// Solve N-Queens using backtracking
bool solveNQUtil(int board[N][N], int col)
{
    // All queens have been placed
    if (col >= N)
        return true;

    // Try every row in the current column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // Place queen
            board[i][col] = 1;

            // Recursively place queen in next column
            if (solveNQUtil(board, col + 1))
                return true;

            // Backtrack: remove queen
            board[i][col] = 0;
        }
    }

    // No valid position found
    return false;
}

int main()
{
    int board[N][N] = {0};

    if (solveNQUtil(board, 0))
    {
        cout << "N-Queens Solution:" << endl;
        printSolution(board);
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}
