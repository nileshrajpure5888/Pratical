#include <iostream>
using namespace std;

// Recursive function
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    // Iterative Method
    cout << "Fibonacci Series Without Recursion\n";
    cout << "Enter the number of terms: ";
    cin >> n;

    int t1 = 0, t2 = 1, nextTerm;

    cout << "Fibonacci Series: ";

    for (int i = 0; i < n; i++)
    {
        cout << t1 << " ";

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    // Recursive Method
    int p;

    cout << "\n\nFibonacci Using Recursion\n";
    cout << "Enter the position (n): ";
    cin >> p;

    if (p < 0)
    {
        cout << "Please enter a non-negative number.\n";
    }
    else
    {
        cout << "Fibonacci number at position "
             << p << " is: " << fibonacci(p) << endl;
    }

    return 0;
}
