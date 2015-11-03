#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;


vector<short> convertLongToBin(long number)
{
    vector<short> res;

    for (int i=0; number != 0; ++i)
    {
        res.push_back(number % 2);
        number /= 2;
    }

    return res;
}

bool checkNumberForPalindromeDec(long straight_number)
{
    short digit;
    long number = straight_number, 
        reverse_number = 0;

    while (number > 0)
    {
        digit = number % 10;
        reverse_number = reverse_number * 10 + digit;
        number /= 10;
    }

    if (straight_number == reverse_number)
        return true;
    else
        return false;
}

bool checkNumberForPalindromeBin(long straight_number)
{
    vector<short> digits = convertLongToBin(straight_number);

    for (int i=0; i<digits.size(); ++i)
        if (digits[i] != digits[digits.size()-i-1])
            return false;

    return true;
}



int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2. \n";

    QueryPerformanceCounter(&lTime1);

    int64 answer = 0;


    for (int i=1; i<1000000; i+=2)
    {
        if (checkNumberForPalindromeDec(i) && checkNumberForPalindromeBin(i))
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

