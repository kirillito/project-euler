#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool primes[1000000] = {false};

bool checkIfPrime(int n)
{
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0)
            return false;

    return true;
}

bool checkLeftTruncations(int n)
{
	int divider = 10;
	while (n/divider > 10)
		divider *= 10;

	if (divider > 10)
	{
		if (primes[n % divider])
			return checkLeftTruncations(n % divider);
		else
			return false;
	}
	else
	{
		if (primes[n % divider])
			return true;
		else 
			return false;
	}
}

bool checkRightTruncations(int n)
{
	if (n / 10 > 0)
	{
		if (primes[n / 10])
			return checkRightTruncations(n/10);
		else
			return false;
	}
	else
	{
		if (primes[n % 10])
			return true;
		else 
			return false;
	}
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of the only eleven primes that are both truncatable from left to right and right to left. \n";

    QueryPerformanceCounter(&lTime1);

    int answer = 0, counter = 0;

	primes[2] = primes[3] = primes[5] = primes[7] = primes[11] = primes[13] = primes[17] = primes[19] = true;

	for (int i=23; i<=740000/*counter <= 11*/; i+=2)
	{
		if (checkIfPrime(i))
		{
			primes[i] = true;

			if ((checkLeftTruncations(i)) && (checkRightTruncations(i)))
			{
				counter++;
				answer += i;
			}
		}
	}
        
    cout << "Answer: " <<  answer << " (sum of " << counter << " numbers)\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

