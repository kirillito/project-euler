#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

int fact(int n)
{
    if (n<=1) return 1;
    else return n*fact(n-1);
}

bool checkNumber(int n)
{
    vector<short> d;
    int t = n;

    while (t >= 1)
    {
        d.push_back(t%10);
        t /= 10;
    }

    int s = 0;

    for (int i=0; i<d.size(); ++i)
    {
        s += fact(d[i]);
    }

    if (s == n)
        return true;
    else
        return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of all numbers which are equal to the sum of the factorial of their digits. \n";

    QueryPerformanceCounter(&lTime1);

    int64 answer = 0;

    for (int i=145; i<=799988; ++i)
    {
        if (checkNumber(i))
            answer += i;
    }
         
    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

