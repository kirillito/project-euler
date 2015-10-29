#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

bool checkIfPrime(int n)
{
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0)
            return false;

    return true;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "How many circular primes are there below one million? \n";

    QueryPerformanceCounter(&lTime1);

    int answer = 13;
    vector<int64> primes;

    int counter = 100;
    for (int i=101; i<1000000; i+=2)
    {
        if (i/counter > 10)
            counter *= 10;

        if (i % 5 != 0)
            if (checkIfPrime(i))
            {
                int pr1 = i;
                pr1 = (pr1 % counter) * 10 + (pr1 / counter);

                bool isFound = true;
                while (pr1 != i)
                {
                    if (!checkIfPrime(pr1))
                    {
                        isFound = false;
                        pr1 = i;
                    }
                    else
                        pr1 = (pr1 % counter) * 10 + (pr1 / counter);
                }

                if (isFound)
                    answer++;
//                primes.push_back(i);
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

//there can be only digits 1, 3, 7, 9