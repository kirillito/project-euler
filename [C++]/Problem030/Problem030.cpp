#include <iostream>
#include <math.h>
#include <vector>
#include <windows.h>

using namespace std;

int getValue(int first, int second, int third, int fourth, int fifth, int six)
{
    int res = 0;
    
    res += (int)pow((double)first, 5.0);
    res += (int)pow((double)second, 5.0);
    res += (int)pow((double)third, 5.0);
    res += (int)pow((double)fourth, 5.0);
    res += (int)pow((double)fifth, 5.0);
    res += (int)pow((double)six, 5.0);

    return res;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of all the numbers that can be written as the sum of fifth powers of their digits. \n";

    QueryPerformanceCounter(&lTime1);

    int first = 0, second =0, third = 0, fourth = 0, fifth = 0, six = 0;
    int sum = 0;

    for (int i=10; i < 354294; i++)
    {
        first = (i / 100000) % 10;
        second = (i /10000) % 10;
        third = (i / 1000) % 10;
        fourth = (i / 100) % 10;
        fifth = (i / 10) % 10;
        six = i % 10;

        if (i == getValue(first, second, third, fourth, fifth, six))
            sum += i;
    }

    cout << "Answer: " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

