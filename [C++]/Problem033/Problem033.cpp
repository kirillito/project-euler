#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "If the product of these four fractions is given in its lowest common terms, find the value of the denominator. \n";

    QueryPerformanceCounter(&lTime1);

    int numerator = 1, denominator = 1;

	for (int i=11; i<=99; i++)
		for (int j=i+1; j<=99; j++)
		{
			if (i!=j && i%10!=0 && j%10!=0)
			{
				double d1, d2=0;
				if (i/10==j%10)
					d2 = (double)(i%10)/(j/10);
				else if (j/10==i%10)
					d2 = (double)(i/10)/(j%10);

				if ((d2!=0) && ((double)i / j == d2))
				{
					numerator *= i;
					denominator *= j;
				}
			}
		}
        
	for (int i=2; i*i<denominator; i++)
	{
		while (numerator%i == 0)
		{
			if (numerator%i==0 && denominator%i==0)
			{
				numerator /= i;
				denominator /= i;
			}
		}
	}
	
	cout << "Answer: " << denominator << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

