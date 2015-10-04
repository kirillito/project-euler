// Problem009.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>
using namespace std;

bool checkTripletForPithagor(int, int, int);

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "A Pythagorean triplet is a set of three natural numbers, a < b  < c, for which, \n"
        << "a^(2) + b^(2) = c^(2 \n"
        << "For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2). \n"
        << "There exists exactly one Pythagorean triplet for which a + b + c = 1000. \n"
        << "Find the product abc. \n";
    std::cout << "-Dumb--------------------------------\n";

    QueryPerformanceCounter(&lTime1);

    int P = 1000;
    int a,b,c, product=1;

    for (a = 1; a < P/2; a++)
        for (b = 1; b < P/2; b++)
            if (checkTripletForPithagor(a,b,P-a-b))
                product = a*b*(P-a-b);

    std::cout << "answer is " <<  product << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Smart--------------------------------\n";

    getchar();
	return 0;
}

bool checkTripletForPithagor(int a, int b, int c)
{
    if (a*a + b*b == c*c)
        return true;
    else
        return false;
}


