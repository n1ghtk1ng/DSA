
Integer Factorization
The most commonly used algorithm for the integer factorization is the Sieve of Eratosthenes . It is sufficient to scan primes upto
sqrt(N) while factorizing N. Also, if we need to factorize all numbers between 1 to N, this task can be done using a single run of this
algorithm - For every integer k between 1 to N, we can maintain a single pair - the smallest prime that divides k, and its highest power ,
say (p,a). The remaining prime factors of k are then same as that of k/(p a ).
//Pseudo Code for prime factorization assuming
//SPFs are computed :
//
//PrimeFactors[] // To store result
//
//i = 0  // Index in PrimeFactors
//
//while n != 1 :
//
//    // SPF : smallest prime factor
//    PrimeFactors[i] = SPF[n]
//    i++
//    n = n / SPF[n]
//The C++ implementation for the above method is given below :

// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN   100001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

// driver program for above function
int main(int argc, char const *argv[])
{
    // precalculating Smallest Prime Factor
    sieve();
    int x = 12246;
    cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    vector <int> p = getFactorization(x);

    for (int i=0; i<p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}
//The above code works well for n upto the order of 10^7. Beyond this we will face memory issues.
Time Complexity: The precomputation for smallest prime factor is done in O(n log log n) using sieve.
Where as in the calculation step we are dividing the number every time by the smallest prime number till it becomes 1.
So, let’s consider a worst case in which every time the SPF is 2 .
Therefore will have log n division steps.
Hence, We can say that our Time Complexity will be O(log n) in worst case.


///for printing the powers of primes
int curr = spf[N];  // Current prime factor of N
    int cnt = 1;   // Power of current prime factor

    // Printing prime factors and their powers
    while (N > 1)
    {
        N /= spf[N];

        // N is now N/s[N].  If new N als has smallest
        // prime factor as curr, increment power
        if (curr == spf[N])
        {
            cnt++;
            continue;
        }

        printf("%d\t%d\n", curr, cnt);

        // Update current prime factor as s[N] and
        // initializing count as 1.
        curr = spf[N];
        cnt = 1;
    }
