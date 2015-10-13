#include <iostream>
#include <vector>
#include <windows.h>
//#include <algorithm>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? \n";

    QueryPerformanceCounter(&lTime1);
    
    int fact[10]; vector<int> numbers; int permutation[10];
    fact[0] = 1; numbers.push_back(0);
    for (int i=1; i<10; ++i)
    {
        numbers.push_back(i);
        fact[i] = i * fact[i-1];
    }

    int number = 1000000-1;
    int d;

    for (int i=9; i>=0; --i)
    {
        d = number / fact[i];

        int j, n = 0;
        for (j=0; j<numbers.size(); ++j)
        {
            if (numbers[j] > 0)
                n++;
            if (n == d)
                break;
        }
        permutation[i] = numbers[j];
        numbers[j] = -1;

        number -= d * fact[i];
    }

    int answer;

    cout << "Answer: ";
    for (int i=9; i>=0;--i)
    {
        cout <<  permutation[i];
    }

    cout <<  "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

