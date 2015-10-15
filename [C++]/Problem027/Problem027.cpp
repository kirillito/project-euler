#include <iostream>
#include <windows.h>

using namespace std;

bool checkIfPrime(int n)
{
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0)
            return false;

    return true;
}

int countPrimeNumbers(short a, short b)
{
    int n = 0;

    while ((n*n + a*n + b > 0) && (checkIfPrime(n*n + a*n + b)))
        n++;

    return n;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0. \n";

    QueryPerformanceCounter(&lTime1);

    int answer = 0;
    int maxPrimeNumbers = 0, currentPrimeNumbers = 0;

    for (int a=-999; a<=999; a+=2)
        for (int b=-999; b<=999; b+=2)
        {
            if (checkIfPrime(b) )
            {
                currentPrimeNumbers = countPrimeNumbers(a, b);
                if (maxPrimeNumbers < currentPrimeNumbers)
                {
                    maxPrimeNumbers = currentPrimeNumbers;
                    answer = a*b;
                }
            }
        }

        
    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

