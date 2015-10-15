#include <iostream>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? \n";

    QueryPerformanceCounter(&lTime1);
    
    int answer;

    int64 s = 1;

    for (int i=3; i<=1001; i+=2)
    {
        s = s + 4 * i * i - 6 * i + 6;
    }

    cout << "Answer: " <<  s << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

