#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit;
    int weight;

    // Constructor
    Item(int p, int w)
    {
        profit = p;
        weight = w;
    }
};

// Comparator: sort according to profit/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;

    return r1 > r2;
}

// Function to solve Fractional Knapsack
double fractionalKnapsack(int W, Item arr[], int N)
{
    // Sort items by decreasing profit/weight ratio
    sort(arr, arr + N, cmp);

    double finalValue = 0.0;

    for (int i = 0; i < N; i++)
    {
        // If complete item can fit
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalValue += arr[i].profit;
        }
        else
        {
            // Take the fraction that fits
            finalValue += arr[i].profit *
                          ((double)W / arr[i].weight);

            break;
        }
    }

    return finalValue;
}

int main()
{
    // Capacity of knapsack
    int W = 20;

    // Items: {profit, weight}
    Item arr[] =
    {
        {20, 30},
        {10, 30},
        {10, 10}
    };

    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum profit in Knapsack = "
         << fractionalKnapsack(W, arr, N)
         << endl;

    return 0;
}
