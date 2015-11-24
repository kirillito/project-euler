#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

bool checkTriangular(int64 t)
{
	int64 n = (int64)(sqrt((double)(t * 2)));

	while ( (n * (n+1) / 2) < t)
		n++;
	
	if ((n * (n+1) / 2) == t)
		return true;
	else
		return false;
}

bool checkPentagonal(int64 t)
{
	int64 n = (int64)(sqrt((double)(t * 6)) / 3);

	while ( (n * (3*n - 1) / 2) < t)
		n++;
	
	if ((n * (3*n - 1) / 2) == t)
		return true;
	else
		return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the next triangle number that is also pentagonal and hexagonal. \n";

    QueryPerformanceCounter(&lTime1);

    int64 answer = 0;

	for (int64 n=144; ; ++n)
	{
		answer = n * (2*n - 1);
		if (checkTriangular(answer) && checkPentagonal(answer))
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

