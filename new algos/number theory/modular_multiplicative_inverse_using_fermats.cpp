If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.

am-1 ≡ 1 (mod m)
If we multiply both sides with a-1, we get

 a-1 ≡ a m-2 (mod m)
Below is C++ implementation of above idea.

// C++ program to find modular inverse of a under modulo m
// This program works only if m is prime.
#include<iostream>
using namespace std;

// To find GCD of a and b
int gcd(int a, int b);

// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m);
    }
}

// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Driver Program
int main()
{
    int a = 3, m = 11;
    modInverse(a, m);
    return 0;
}
Run on IDE
Output:

Modular multiplicative inverse is 4
Time Complexity of this method is O(Log m)

We have discussed three methods to find multiplicative inverse modulo m.
1) Naive Method, O(m)
2) Extended Euler’s GCD algorithm, O(Log m) [Works when a and m are coprime]
3) Fermat’s Little theorem, O(Log m) [Works when ‘m’ is prime]
