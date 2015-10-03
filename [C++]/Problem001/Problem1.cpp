// Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    int sum = 0;
    for (int i=1; i<1000; i++)
    {
        if (i%3 == 0)
            sum += i;
        else if (i%5==0)
            sum +=i;
    }

    std::cout << "Sum = " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Fast------------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    sum = 0;
    int i=3; int j=5;
    for (; (i<1000) || (j<1000);i+=3 )
    {
        sum+=i;
        if ((j<1000) && (j%3!=0))
            sum += j;
        j+=5;
    }

    std::cout << "Sum = " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    getchar();
	return 0;
}

