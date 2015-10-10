#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)? \n";

    QueryPerformanceCounter(&lTime1);

    int year=1900, month=1, day;
    int jan=31, feb=28, mar=31, apr=30, may=31, jun=30, jul=31, aug=31, sep=30, oct=31, nov=30, dec=31;

    int answer = 0;

    day = 365%7 + 1; year++;
    while ( !(year > 2000) )
    {
        day = (day + jan) % 7;
        if (day == 0)
            answer++;

        day = (day + feb + (( year % 4 == 0 ) ? 1 : 0 )) % 7;
        if (day == 0)
            answer++;

        day = (day + mar) % 7;
        if (day == 0)
            answer++;

        day = (day + apr) % 7;
        if (day == 0)
            answer++;

        day = (day + may) % 7;
        if (day == 0)
            answer++;

        day = (day + jun) % 7;
        if (day == 0)
            answer++;

        day = (day + jul) % 7;
        if (day == 0)
            answer++;

        day = (day + aug) % 7;
        if (day == 0)
            answer++;

        day = (day + sep) % 7;
        if (day == 0)
            answer++;

        day = (day + oct) % 7;
        if (day == 0)
            answer++;

        day = (day + nov) % 7;
        if (day == 0)
            answer++;

        day = (day + dec) % 7;
        if (day == 0)
            answer++;

        year++;
    }

    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

