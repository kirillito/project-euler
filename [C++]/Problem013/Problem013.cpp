#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Work out the first ten digits of the sum of the following one-hundred 50-digit numbers (see file). \n";

    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
//    unsigned long sum = 0;

    short* number = new short[50];
    short* sum = new short[5000];

    //init
    for (int i=0; i<5000; i++)
    {
        sum[i] = 0;
    }

    short buf;
    string line;
    int j = 0;
    ifstream ifs("input.txt"); 
    while (getline(ifs, line))
    {
        istringstream iss(line);
        char numberchar;
        j = 49;
        while ((iss >> numberchar) && (j>=0))
        {
            number[j] = atoi(&numberchar);
            j--;
        }

        buf = 0;
        for (int i=0; i<50; i++)
        {
            sum[i] = sum[i] + number[i] + buf;
            buf = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }

        for (int i=50; i<5000; i++)
        {
            sum[i] = sum[i] + buf;
            buf = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }

    }
    ifs.close();

    cout << "\nResult: \n";

    bool isPrint = false;
    int printTimes = 0;
    for (int i=4999; i>=0; i--)
    {
        if (sum[i] != 0)
            isPrint = true;

        if (isPrint)
        {
            cout << sum[i];
            printTimes++;
        }

        if (printTimes >= 10)
            break;
    }

    cout << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

