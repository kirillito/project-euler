#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

typedef unsigned long long int64;

template <class T>
T gcd(T a, T b) 
{
 T c;
 while (b) {
    c = a % b;
    a = b;
    b = c;
 }
 if (a < 0)
    a *= -1;
 return a;
}
 

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "For which value of p <= 1000, is the number of solutions maximised? \n";

    QueryPerformanceCounter(&lTime1);

    //(m^2 + n^2) + (m^2 - n^2) + 2mn = p
    // 2m^2 + 2mn - p = 0,  m>n => max: 2m^2 + 2m^2 -> p
    // n = (p - 2m^2) / 2m
    // m < p / 2

    int max=0, maxperimeter = 3;

    for (int perimeter = 3; perimeter <= 1000; perimeter++)
    {
        int64 upBound = (int)sqrtl((long double) perimeter / 2);

        int answer=0;

        for (int64 m = 1; m <= upBound; m++)
        {
            for (int64 n = (m % 2) + 1; n < m; n += 2)
                if (gcd(m,n) == 1)
                {
                    if (perimeter % (2*(m*m + m*n)) == 0)
                        ++answer;
                    else if (perimeter < 2*(m*m + m*n))
                        break;
                }
        }
        if (max<answer)
        {
            max = answer;
            maxperimeter = perimeter;
        }
    }
    cout << "Answer: " <<  maxperimeter << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

