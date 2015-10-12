#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <windows.h>
 
using namespace std;

void readCSV(ifstream& infile, list<string>& stringArray) 
{
	
	//	declare string buffer
	string buffer;
	
	//	get line from file
	getline(infile, buffer, '\n');

	//	read through buffer searching for commas or end of string. the start of 
	//	each entry is the first element of the string (first word), or the 
	//	position after the last comma encountered (all other words).  the end
	//	of the entry is the last element of the string (last word), or the 
	//	position before the next comma (all other words)
	string temp;
	unsigned long start=0;
	unsigned long end=0;
	while (end<=buffer.size()) 
    {
		//	increment end counter
		end++;
		
		//	check if position of 'end' in the string a comma, past the end of 
		//	the string, or just another character.  if at a non-comma character,
		//	skip to the start of the next loop
		if (end<buffer.size() && buffer[end]!=',') {
			continue;
		}
		
		//	assign comma-free token to a temporary string
		temp.assign(buffer,start+1,end-start-2);
		
		//	based on alphabetical/numerical content and the presence of period/
		//	decimals, determine whether the entry is an integer, floating-point
		//	number, or a string

        stringArray.push_back(temp);
		
		//	set the start and end to the proper next position
		end++;
		start=end;
    }
}

int getNameScore(string name, int number)
{
    int score = 0;
    
    for (int i=0; i<name.size(); i++)
    {
        score += (int)name[i] - 64;
    }

    return score * number;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "What is the total of all the name scores in the file? \n";

    QueryPerformanceCounter(&lTime1);

    list<string> namesList;
    ifstream ifs("names.txt"); 
    readCSV(ifs, namesList);

    namesList.sort();

    vector<string> names(namesList.size());
    copy(namesList.begin(), namesList.end(), names.begin());

    unsigned long long sum = 0;
    for (int i=0; i<names.size();i++)
    {
        sum += getNameScore(names[i], i+1);
    }

    cout << "Answer: " <<  sum << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

