#include <iostream>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

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

    cout << "What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ? \n";

    QueryPerformanceCounter(&lTime1);

	int64 answer = 0;

	int64 current;
	for (int i=9; i<=9876; ++i)
	{
		current=0;
		for (int j=2; current<987654321; ++j)
		{
			for (int k=1; k<=j; ++k)
			{
				int64 tens = 1, tmp=i*k;
				while (tmp/tens>0)
					tens*=10;

				current = current*tens + i*k;
			}
			if ((current>answer) && (current<987654321))
				if (checkIfPandigital(current))
					answer = current;
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

