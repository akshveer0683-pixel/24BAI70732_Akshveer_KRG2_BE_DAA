#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int a, b, k;

    cout << "Enter value of a, b & k: ";
    cin >> a>>b>>k;

    double logval = log(a) / log(b);   

    cout << "\nlog_b(a) = " << logval << endl;

    if (logval > k) 
    {
        cout << "Case 1: \n";
        cout << "T(n) = O(n^" << logval << ")\n";
    }
    else if (logval == k) 
    {
        cout << "Case 2: \n";
        cout << "T(n) = O(n^" << k << " log n)\n";
    }
    else 
    {
        cout << "Case 3:\n";
        cout << "T(n) = O(n^" << k << ")\n";
    }
}
