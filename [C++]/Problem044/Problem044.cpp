#include <iostream>
#include <math.h>

#include <windows.h>

using namespace std;

typedef unsigned long long int64;

const int MAX = 5000;

int64 pentagonal[MAX] = {0};

int64 getPentagonalNumber(int n)
{
	return n*(3*n-1)/2;
}

bool checkIfPentagonal(int64 n)
{
	for (int i=0; i<MAX; ++i)
		if (n==pentagonal[i])
			return true;

	return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the smallest pair of pentagonal numbers whose sum and difference is pentagonal. \n";

    QueryPerformanceCounter(&lTime1);

	int64 answer = 200000000;

	for (int i=0; i<MAX; ++i)
	{
		pentagonal[i] = getPentagonalNumber(i);
	}

	for (int d=1; d<MAX; ++d)
	{
		answer = pentagonal[d];

		bool flag = false;

		for (int n=1; n<MAX; ++n)
		{
			for (int k=n+1; k<MAX; ++k)
			{
				if (pentagonal[k]-pentagonal[n] == answer)
				{
					if (checkIfPentagonal(pentagonal[k]+pentagonal[n]))
					{
						flag = true;
						n = MAX; k = MAX;
					}
				}
				else if (pentagonal[k]-pentagonal[n] > answer)
				{
					k = MAX;
				}
			}
		}

		if(flag)
			break;
	}

	cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

