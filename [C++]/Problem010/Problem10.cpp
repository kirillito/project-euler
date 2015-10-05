// Problem10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include "vector"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int N=2000000;

    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. \n"
        << "Find the sum of all the primes below two million.\n";
    std::cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    unsigned long long sum = 0;
    int i;

    vector<int> result;
    result.push_back(2);
    sum += 2;

    for (int i = 3; i < N; i += 2)
    {
        bool b = true;
        for (int j = 0; (j < result.size()) && (result[j]* result[j] <= i); ++j)
        {
            if (i % result[j] == 0)
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            result.push_back(i);
            sum += i;
        }
    }

    std::cout << "Sum = " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}
/*
long sum_prime(int from, int to)
{
    return 0;
}

vector<int> primes(int max_size)
{
    vector<int> result;
    result.push_back(2);

    for (int i = 3; i < 20000000; i += 2)
    {
        bool b = true;
        for (int j = 0; (j < result.size()) && (result[j]* result[j] <= i); ++j)
        {
            if (i % result[j] == 0)
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            result.push_back(i);
        }
    }
    return result;
}

*/