#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "The following iterative sequence is defined for the set of positive integers: \n"
        << "n ->  n/2 (n is even) \n"
        << "n ->  3n + 1 (n is odd) \n"
        << "Using the rule above and starting with 13, we generate the following sequence: \n"
        << "13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1 \n"
        << "It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1. \n"
        << "Which starting number, under one million, produces the longest chain? \n"
        << "NOTE: Once the chain starts the terms are allowed to go above one million.\n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    int* length = new int[1000000];

    //init
    for (int i=1; i<=1000000; i++)
    {
        length[i]=0;
    }

    length[1] = 1;

    int counter; 
    long long current;
    for (int i=2; i<=1000000; i++)
    {
        current = i;
        counter = 1;
        while (current != 1)
        {
            if (current % 2 == 0)
                current /= 2;
            else
                current = 3*current + 1;

            if ((current < 1000000) && (length[current] != 0))
            {
                counter += length[current];
                current = 1;
            }
            else
            {
                counter++;
            }
        }
        length[i] = counter;
    }

    int longestStart = 1, longestLength = 1;
    for (int i=2; i<=1000000; i++)
    {
        if (longestLength < length[i])
        {
            longestLength = length[i];
            longestStart = i;
        }
    }

    cout << "Answer: " <<  longestStart << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

