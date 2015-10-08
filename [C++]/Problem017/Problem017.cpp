#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?  \n";

    QueryPerformanceCounter(&lTime1);
    
    int answer = 0;

    int one=3, two=3, three=5, four=4, five=4, six=3, seven=5, eight=5, nine=4, ten=3, eleven=6, twelve=6, thirteen=8, fourteen=8, fifteen=7,
        sixteen=7, seventeen=9, eighteen=8, nineteen=8, twenty=6, thirty=6, forty=5, fifty=5, sixty=5, seventy=7, eighty=6, ninety=6, 
        hundred=7, thousand=8, and=3;

    // <10
    int numbers = (one + two + three + four + five + six + seven + eight + nine);
    // 10<= ? <20
    int tens1 = (ten + eleven + twelve + thirteen + fourteen + fifteen + sixteen + seventeen + eighteen + nineteen);
    // 20 <= ? <100
    int tens = (twenty + thirty + forty + fifty + sixty + seventy + eighty + ninety) * 10 + numbers * 8;
    // 100<= ? <1000
    int hundreds = 100 * (9 * hundred + numbers) + 99 * 9 * and + 9 * numbers + 9 * tens1 + 9 * tens;

    answer = numbers + tens1 + tens + hundreds + one + thousand;

    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

