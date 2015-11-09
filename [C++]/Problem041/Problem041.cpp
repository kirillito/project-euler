#include <iostream>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

bool checkIfPrime(int64 n)
{
    for (int64 i=2; i*i<=n; ++i)
        if (n%i == 0)
            return false;

    return true;
}

bool checkIfPandigital(int64 n)
{
	int max = 1;
	int tens;
	for (tens=10; max<10; tens*=10)
	{
		if (n/tens > 0)
			max++;
		else
			break;
	}
	tens /= 10;

	for (int i=1; i<=max; i++)
	{
		int j; int tmp=n;
		for (j=tens; j>=1; j/=10)
		{
			if (tmp/j == i)
				break;
			tmp = tmp - (tmp/j)*j;
		}
		if (j<1)
			return false;
	}

	return true;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the largest n-digit pandigital prime that exists? \n";

    QueryPerformanceCounter(&lTime1);

    int answer = 7654321;

	for (int64 i=9; i<=999999; i+=9) //+9 +90 +99 +900 +909...
	{
		if (checkIfPrime(answer - i))
		{
			if (checkIfPandigital(answer - i))
			{
				answer = answer - i;
				break;
			}
		}	
	}

        
    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

