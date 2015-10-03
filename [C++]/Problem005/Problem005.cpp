// Problem005.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include "vector"
using namespace std;

vector<int> checkFactorsForNumber(int, vector<int>);

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. \n"
        << "What is the smallest number that is evenly divisible by all of the numbers from 1 to 20? \n";
    std::cout << "-Dumb--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    int N = 20;
    unsigned long long number = 1;
    vector<int> factors;

    factors.push_back(1);

    for (int i=2; i<=N; i++)
        factors = checkFactorsForNumber(i, factors);

    for (int i = 0; i< factors.size(); i++)
{
        number *= factors.at(i);
//std::cout << "Number : " << factors.at(i);
}
    std::cout << "answer is " <<  number << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Smart--------------------------------\n";

    getchar();
	return 0;
}

vector<int> checkFactorsForNumber(int checkNumber, vector<int> factors)
{
    for (int i = 0; i< factors.size(); i++)
    {
        if (checkNumber % factors.at(i) == 0)
            checkNumber /= factors.at(i);
    }

    if (checkNumber != 1)
        factors.push_back(checkNumber);

    return factors;
}


