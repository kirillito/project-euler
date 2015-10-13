#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

bool isAbundant(int n)
{
    int s = 1;

    for (int i=2; i*i<=n; ++i)
    {
        if (i*i == n)
        {
            s += i;
            break;
        }

        if (n%i==0)
        {
            s += i;
            s += n/i;
        }
    }

    if (s > n)
        return true;
    else 
        return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers. \n";

    QueryPerformanceCounter(&lTime1);

    int64 answer = 0;

    vector<int> abundant;
    vector<bool> numbers;

    for (int i=0; i<=28123; ++i)
    {
        numbers.push_back(true);
    }

    for (int i=12; i<=28111; ++i)
    {
        if (isAbundant(i))
            abundant.push_back(i);
    }

    for (int i=0; i<abundant.size(); ++i)
    {
        for (int j=i; j<abundant.size(); ++j)
        {
            if (abundant[i] + abundant[j] > 28123)
                break;

            numbers[abundant[i] + abundant[j]] = false;
        }
    }

    for (int i=1; i<=28123; ++i)
    {
        if (numbers[i])
            answer += i;
    }
        
    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

