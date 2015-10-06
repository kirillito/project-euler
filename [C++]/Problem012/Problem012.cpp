#include <iostream>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

int64 getTriangularNumber(int);
int getNumberOfDivisors(int64);
int64 phi(int64);

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the value of the first triangle number to have over five hundred divisors? \n";

    QueryPerformanceCounter(&lTime1);
    
    const int START = 500;

    int64 answer = getTriangularNumber(START - 1);

    for (int i=START; i<1000000; i++)
    {
        answer += i;
        if (getNumberOfDivisors(answer) >= 500)
            break;
    }

    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

int64 getTriangularNumber(int n)
{
    return n*(n+1)/2;
}

int getNumberOfDivisors(int64 n)
{
    int res = 1;

    for (int64 j=2; j*j<=n; j++)
        if (n%j == 0)
            res+=2;

    return res + 1;
}
