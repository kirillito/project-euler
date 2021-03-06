// Problem016.cpp : Defines the entry point for the console application.
//


#include "iostream"
#include <windows.h>
#include <string>

using namespace std;

void show(short*);

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "n! means n * (n  − 1) * ... * 3 * 2 * 1 \n";
    cout << "Find the sum of the digits in the number 100! \n";
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

    for (int i=2; i<=100; i++)
    {
        buf = 0;
        for (int j=0; j<1000; j++)
        {
            number[j] = number[j] * i + buf;
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