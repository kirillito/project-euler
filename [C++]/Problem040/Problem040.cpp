#include <iostream>
#include <windows.h>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "If d(n) represents the n-th digit of the fractional part, find the value of the following expression: \n"
        << "d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000) \n";

    QueryPerformanceCounter(&lTime1);

    vector<short> d;
    int result=1, counter, current, tmp;
    
    for (int i=1; d.size()<=1000000; i++)
    {
        if (i<10)
        {
            d.push_back(i);
        }
        else if (i<100)
        {
            d.push_back(i/10);
            d.push_back(i%10);
        }
        else if (i<1000)
        {
            d.push_back(i/100);
            d.push_back((i/10)%10);
            d.push_back(i%10);
        }
        else if (i<10000)
        {
            d.push_back(i/1000);
            d.push_back((i/100)%10);
            d.push_back((i/10)%10);
            d.push_back(i%10);
        }
        else if (i<100000)
        {
            d.push_back(i/10000);
            d.push_back((i/1000)%10);
            d.push_back((i/100)%10);
            d.push_back((i/10)%10);
            d.push_back(i%10);
        }
        else if (i<1000000)
        {
            d.push_back(i/100000);
            d.push_back((i/10000)%10);
            d.push_back((i/1000)%10);
            d.push_back((i/100)%10);
            d.push_back((i/10)%10);
            d.push_back(i%10);
        }
        else if (i<10000000)
        {
            d.push_back(i/1000000);
            d.push_back((i/100000)%10);
            d.push_back((i/10000)%10);
            d.push_back((i/1000)%10);
            d.push_back((i/100)%10);
            d.push_back((i/10)%10);
            d.push_back(i%10);
        }
    }

    result = d[0] * d[9] * d[99] * d[999] * d[9999] * d[99999] * d[999999];

    cout << "Answer: " <<  result << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}