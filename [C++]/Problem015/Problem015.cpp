#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

vector<long long> GetPascalTriangleNextLine(vector<long long>);

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Starting in the top left corner of a 2×2 grid, there are 6 routes (without backtracking) to the bottom right corner. \n"
        << "How many routes are there through a 20*20 grid?\n";
    cout << "-Standard--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    vector<long long> line; 
    line.push_back(1); line.push_back(2); line.push_back(1);

    for (int i=2; i<40; ++i)
    {
        line = GetPascalTriangleNextLine(line);
    }

    cout << "Answer: " <<  line.at(20) << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

vector<long long> GetPascalTriangleNextLine(vector<long long> line)
{
    vector<long long> nextLine;
    nextLine.push_back(1);
    for (int i=0; i<line.size()-1; i++)
    {
        nextLine.push_back(line.at(i) + line.at(i+1));    
    }
    nextLine.push_back(1);

    return nextLine;
}

