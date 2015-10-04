// Problem007.cpp : Defines the entry point for the console application.
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

    std::cout << "By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6^(th) prime is 13. \n"
        << "What is the 10001^(st) prime number? \n";
    std::cout << "-Dumb--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    vector<int> result;
    result.push_back(2);
    int number = 1;

    for (int i = 3; number < 10001; i += 2)
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
            number ++;
        }
    }


    std::cout << "10001st prime number is " <<  result.at(10000) << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Smart--------------------------------\n";

    getchar();
	return 0;
}

