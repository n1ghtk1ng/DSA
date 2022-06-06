//For example, the above method fails when mod = 1011, a = 9223372036854775807 (largest long long int) and b = 9223372036854775807 (largest long long int).
// Note that there can be smaller values for which it may fail.
// There can be many more examples of smaller values.
// In fact any set of values for which multiplication can cause a value greater than maximum limit.

///How to avoid overflow?
//We can multiply recursively to overcome the difficulty of overflow. To multiply a*b, first calculate a*b/2 then add it twice.
// For calculating a*b/2 calculate a*b/4 and so on (similar to log n exponentiation algorithm).

// To compute (a * b) % mod
//multiply(a,  b, mod)
//1)  ll res = 0; // Initialize result
//2)  a = a % mod.
//3)  While (b > 0)
//        a) If b is odd, then add 'a' to result.
//               res = (res + a) % mod
//        b) Multiply 'a' with 2
//           a = (a * 2) % mod
//        c) Divide 'b' by 2
//           b = b/2
//4)  Return res
//Below is C++ implementation.

// C++ program for modular multiplication without
// any overflow
#include<iostream>
using namespace std;

typedef long long int ll;

// To compute (a * b) % mod
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}

// Driver program
int main()
{
   ll a = 9223372036854775807, b = 9223372036854775807;
   cout << mulmod(a, b, 100000000000);
   return 0;
}

