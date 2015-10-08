#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

typedef unsigned long long int64;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the maximum total from top to bottom of the given triangle. \n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    const int HEIGHT = 15;

    int triangle[HEIGHT][HEIGHT+1] = {0};
    int64 sumtriangle[HEIGHT][HEIGHT+1] = {0};
    string line;

    //read data
    ifstream ifs("input.txt"); 
    for (int i=0; (i<HEIGHT) && (!ifs.eof()); i++)
    {
        getline(ifs, line);
        istringstream iss(line);

        int j=0;
        while (iss >> triangle[i][j])
            j++;
    }
    ifs.close();

    sumtriangle[0][0] = triangle[0][0];
    for (int i=1; i<HEIGHT; i++)
    {
        for (int j=0; j<HEIGHT; j++)
        {
            if (sumtriangle[i][j] < sumtriangle[i-1][j] + triangle[i][j])
                sumtriangle[i][j] = sumtriangle[i-1][j] + triangle[i][j];

            if (sumtriangle[i][j+1] < sumtriangle[i-1][j] + triangle[i][j+1])
                sumtriangle[i][j+1] = sumtriangle[i-1][j] + triangle[i][j+1];
        }
    }

    int64 max = 0;
    for (int j=0; j<HEIGHT+1; j++)
        if (max < sumtriangle[HEIGHT-1][j])
            max = sumtriangle[HEIGHT-1][j];

    cout << "Answer: " <<  max << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

