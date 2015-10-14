#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int placeInVector(int a, vector<int> v)
{
	if (v.size() == 0)
		return -1;

	for (int i=0; i<v.size(); ++i)
		if (v[i] == a)
			return i;

	return -1;
}

int getRecCycleLength(int d)
{ 
	int remainder = 1;

	vector<int> r;
	int place = placeInVector((10*remainder) % d, r);
	while ((remainder != 0) && (place < 0))
	{
		remainder = (10*remainder) % d;
		r.push_back(remainder);
		place = placeInVector((10*remainder) % d, r);
	}

	if (remainder == 0)
		return 0;
	else
		return r.size() - place;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part. \n";

    QueryPerformanceCounter(&lTime1);

    int answer = 0;

	int max = 0, current = 0;
	for (int d=1; d<=1000; ++d)
	{
		current = getRecCycleLength(d);
		if (current > max)
		{
			max = current;
			answer = d;
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

