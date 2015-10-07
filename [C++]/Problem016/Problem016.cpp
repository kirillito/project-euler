// Problem016.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include <string>

using namespace std;

void show(short*);

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "2^(15) = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. \n"
        << "What is the sum of the digits of the number 2^(1000)?\n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    unsigned long sum = 0;

    short* number = new short[1000];

    //init
    for (int i=1; i<1000; i++)
    {
        number[i] = 0;
    }
    number[0] = 1;

    short buf;

    for (int i=1; i<=1000; i++)
    {
        buf = 0;
        for (int j=0; j<1000; j++)
        {
            number[j] = number[j] + number[j] + buf;
            buf = number[j] / 10;
            number[j] = number[j] % 10;
        }
        
   //     show(number);

    }

    for (int i=0; i<1000; i++)
    {
        sum += number[i];
    }

    cout << "Sum = " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}


void show(short* number)
{
    for (int i = 0; i < 1000; i++)
    {
//        if (number[i] )
        cout << number[i];
    }
    cout << "\n";
}