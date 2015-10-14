#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the first term in the Fibonacci sequence to contain 1000 digits? \n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);

    int first[1000] = {0};
    int second[1000] = {0};
    int sum[1000] = {0};

    first[0] = 1; second[0] = 1;
    int counter = 2;

    while (second[999] == 0)
    {
        int buf = 0;
        for (int i=0; i<1000; i++)
        {
            sum[i] = first[i] + second[i] + buf;
            buf = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }

        for (int i=0; i<1000; i++)
        {
            first[i] = second[i];
            second[i] = sum[i];
        }
        counter++;
    }

    cout << "Answer: " <<  counter << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

