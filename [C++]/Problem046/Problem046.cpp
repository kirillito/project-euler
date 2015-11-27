#include <iostream>
#include <vector>
#include <math.h>
#include <windows.h>

using namespace std;

vector<int> primes;

bool checkIfPrime(int n)
{
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0)
            return false;

    return true;
}

bool checkNumber(int n)
{
	int current = n;
	double sroot = 0.0;

	for (int i=1; i<primes.size() && primes[i]<n; ++i)
	{
		if ((n-primes[i])%2 == 0)
		{
			current=(n-primes[i])/2;
			sroot = sqrt((double)current);
			if ((sroot - (double)((int)sroot))==0)
				return true;
		}
	}

	return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the smallest odd composite that cannot be written as the sum of a prime and twice a square? \n";

    QueryPerformanceCounter(&lTime1);

	int answer = 0;

	for (int i=1; i<60000; ++i)
	{
		if (checkIfPrime(i))
			primes.push_back(i);
	}

	for (answer=37; answer<=1000000; answer+=2)
	{
		if (!checkIfPrime(answer))
			if (!checkNumber(answer))
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

