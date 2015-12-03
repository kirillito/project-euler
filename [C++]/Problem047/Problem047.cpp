#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

vector<int> primes;

bool checkIfPrime(int64 n)
{
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0)
            return false;

    return true;
}

bool checkNumber(int64 n)
{
	short counter=0;
	int64 current = n;

	for (int i=1; i<primes.size() && primes[i]*primes[i]<current; ++i)
	{
		if (current%primes[i]==0)
		{
			counter++;
			current/=primes[i];

			while (current%primes[i]==0)
				current/=primes[i];
		}
		if ((counter == 3) && (checkIfPrime(current)))
			return true;
	}

	return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the first four consecutive integers to have four distinct primes factors. \n";

    QueryPerformanceCounter(&lTime1);

	int64 answer = 0;

	for (int i=1; i<60000; ++i)
	{
		if (checkIfPrime(i))
			primes.push_back(i);
	}

	for (answer = 647; answer<90000000; ++answer)
	{
		if (checkNumber(answer))
		{
			answer++;
			if (checkNumber(answer))
			{
				answer++;
				if (checkNumber(answer))
				{
					answer++;
					if (checkNumber(answer))
					{
						answer -= 3;
						break;
					}
				}
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

