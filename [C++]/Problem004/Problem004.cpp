// Problem004.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"
#include <windows.h>
using namespace std;

bool checkNumberForPalindrome(long);

int _tmain(int argc, _TCHAR* argv[])
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    std::cout << "A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99. \n"
        << "Find the largest palindrome made from the product of two 3-digit numbers. \n";
    std::cout << "-Dumb--------------------------------\n";

    QueryPerformanceCounter(&lTime1);
    
    int number1, number2;
    long max_palindrome_number = 0;

    for (number1 = 999; number1 >= 100; --number1)
        for (number2 = 999; number2 >= number1; --number2)
            if(checkNumberForPalindrome(number1 * number2))
                if (max_palindrome_number < number1 * number2)
                    max_palindrome_number = number1 * number2;

    std::cout << "largest palindrome  made from the product of two 3-digit numbers is " <<  max_palindrome_number << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    std::cout << "Execution Time : " << diffTicks << " ticks.\n";

    std::cout << "-Smart--------------------------------\n";

    getchar();
	return 0;
}

bool checkNumberForPalindrome(long straight_number)
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


