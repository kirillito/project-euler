#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "In the 20*20 grid below, four numbers along a diagonal line have been marked in red.";
    cout << "The product of these numbers is 26 * 63 * 78 * 14 = 1788696. \n";
    cout << "What is the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) in the 20*20 grid? \n";

    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    int max = 0, current = 0;

    short grid[20][20] = {0};

    string line;
    ifstream ifs("input.txt"); 
    for (int i=0; (i<20) && (!ifs.eof()); i++)
    {
        getline(ifs, line);
        istringstream iss(line);

        for (int j=0; j<20; j++)
        {
            iss >> grid[i][j];
        }
    }
    ifs.close();

    for (int i=0; i<20; i++)
    {cout << "\n";
        for (int j=0; j<20; j++)
        {
            cout << grid[i][j] << " ";
        }
    }

    for (int j=0; j<20; j++)
        for (int i=0; i<20; i++)
        {
            if (i<17)
            {
                current = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
                if (current > max)
                    max = current;
            }

            if ((i<17) && (j<17))
            {
                current = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
                if (current > max)
                    max = current;
            }

            if (j<17)
            {
                current = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
                if (current > max)
                    max = current;
            }

            if ((i>2) && (j<17))
            {
                current = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
                if (current > max)
                    max = current;
            }
        }


    cout << "\nMax = " <<  max << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}
