// Problem003.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include "vector"
using namespace std;

int getMinPrimeFactor(long long, int);

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "The prime factors of 13195 are 5, 7, 13 and 29. \n"
        << "What is the largest prime factor of the number 600851475143? \n";
    std::cout << "-Dumb--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    vector<int> result;
    long long number = 600851475143;

    if (number % 2 == 0)
    {
        result.push_back(2);
        number /= 2;
    }

    int prime = getMinPrimeFactor(number, 3);
    result.push_back(prime);

    while (number != prime)
    {
        number /= prime;
        prime = getMinPrimeFactor(number, prime);
        result.push_back(prime);
    }

    std::cout << "largest prime factor is " <<  result.back() << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Smart--------------------------------\n";

    getchar();
	return 0;
}

int getMinPrimeFactor(long long number, int fromPrime)
{
    for (int i=fromPrime; i< number/2; i+=2)
    {
        if (number % i == 0)
            return i;
    }
    return number;
}
