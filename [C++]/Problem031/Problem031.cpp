#include <iostream>
//#include <vector>
#include <windows.h>

using namespace std;

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int MAX = 200;

int getNumberOfCombinations(int sum, int from, int to)
{
	if (sum == MAX)
		return 1;

	int res = 0;

	for (int i=from; i<=to; ++i)
	{
		if (sum + coins[i] < MAX)
			res += getNumberOfCombinations(sum + coins[i], i, to);
		else if (sum + coins[i] == MAX)
			res += 1;	//return 1;
	}

	return res;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "How many different ways can 2 pounds be made using any number of coins? \n";

    QueryPerformanceCounter(&lTime1);

	int sum = 200;
    int answer = 0;

	for (int i=7; i>=0; --i)
	{
		answer += getNumberOfCombinations(coins[i], 0, i);
	}

       
    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

