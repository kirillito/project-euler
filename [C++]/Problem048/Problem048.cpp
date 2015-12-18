#include <iostream>
#include <windows.h>

using namespace std;

int *getPoweredNumberCut(int);

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the last ten digits of the series, 1^(1) + 2^(2) + 3^(3) + ... + 1000^(1000). \n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    int *plus; 
    int sum[10] = {0};

    for (int i=1; i<=1000; i++)
    {
        plus = getPoweredNumberCut(i);

        int buf = 0;
        for (int i=0; i<10; i++)
        {
            sum[i] = sum[i] + plus[i] + buf;
            buf = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }

    }

    cout << "Answer: ";

    for (int i=9; i>=0; i--)
    {
        cout << sum[i];
    }

    cout << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

int *getPoweredNumberCut(int n)
{
    int res[10] = {0};
    int mul[10] = {0};

    res[0] = mul[0] = n % 10;
    res[1] = mul[1] = (n / 10) % 10;
    res[2] = mul[2] = (n / 100) % 10;
    res[3] = mul[3] = (n / 1000) % 10;

    int tmp[20] = {0};

    for (int i=1; i<n; ++i)
    {
        for (int i=0; i<20; i++)
            tmp[i] = 0;

        for (int j=0; j<10; j++)
        {
            int buf = 0;
            for (int k=0; k<10; k++)
            {
                tmp[k+j] = tmp[k+j] + res[k] * mul[j] + buf;
                buf = tmp[k+j] / 10;
                tmp[k+j] = tmp[k+j] % 10;
            }
        }

        for (int i=0; i<10; i++)
        {
            res[i] = tmp[i];
        }
    }

    return res;
}