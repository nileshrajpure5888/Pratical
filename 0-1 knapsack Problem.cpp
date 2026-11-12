#include <iostream>
using namespace std;

// Return the maximum of two values
int maxProfit(int a, int b)
{
    return (a > b) ? a : b;
}

// 0/1 Knapsack using recursion
int knapSack(int W, int wt[], int val[], int n)
{
    // Base case
    if (n == 0 || W == 0)
        return 0;

    // If current item is too heavy, exclude it
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Include current item
    int include = val[n - 1] +
                  knapSack(W - wt[n - 1],
                           wt,
                           val,
                           n - 1);

    // Exclude current item
    int exclude = knapSack(W,
                           wt,
                           val,
                           n - 1);

    // Return better choice
    return maxProfit(include, exclude);
}

int main()
{
    int profit[] = {60, 100, 120, 80};
    int weight[] = {10, 20, 30, 15};

    int W = 35;

    int n = sizeof(profit) / sizeof(profit[0]);

    cout << "Maximum Profit: "
         << knapSack(W, weight, profit, n)
         << endl;

    return 0;
}
