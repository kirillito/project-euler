// Problem006.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include "vector"
 
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "The sum of the squares of the first ten natural numbers is, \n"
        << "1^(2) + 2^(2) + ... + 10^(2) = 385 \n"
        << "The square of the sum of the first ten natural numbers is, \n"
        << "(1 + 2 + ... + 10)^(2) = 55^(2) = 3025 \n"
        << "Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.\n"
        << "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.";
    std::cout << "-Dumb--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    unsigned long diff = 0;
    int sum = 0;
    int i;

    for (int i = 1; i <= 100; i ++)
    {
        diff += i * i;
        sum +=i;
    }

    diff = sum*sum - diff;

    std::cout << "Difference = " <<  diff << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Smart--------------------------------\n";

    getchar();
	return 0;
}

