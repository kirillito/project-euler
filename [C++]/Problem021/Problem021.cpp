#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

bool check[10001] = {false}; 
int sum = 0;

void checkNumberForAmicable(int n)
{
    int m = 1;

    for (int i=2; i*i<n; i++)
    {
        if (n%i==0)
        {
            m += i + n/i;
        }
    }

    if (n==m)
    {
        check[n] = true;
        return;
    }

    int k = 1;
    for (int i=2; i*i<m; i++)
    {
        if (m%i==0)
        {
            k += i + m/i;
        }
    }

    if (k==n)
    {
        check[n] = check[m] = true;
        sum += n + m;
    }

    return;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Evaluate the sum of all the amicable numbers under 10000. \n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    
    check[0] = check[1] = true;

    for (int i=2; i<=10000; i++)
    {
        if (!check[i])
            checkNumberForAmicable(i);
    }

    cout << "Answer: " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

