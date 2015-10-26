#include <iostream>
#include <windows.h>

using namespace std;

bool checkOneOnFour(int i1, int i2, int i3, int i4)
{
	int product = i1*1000 + i2*100 + i3*10 + i4;

	int first=0, second=0;

	for (int j1=1; j1<=9; ++j1)
	{
		if (j1!=i1 && j1!=i2 && j1!=i3 && j1!=i4)
		{
			first = j1;

			for (int k1=1; k1<=9; ++k1)
			{
				if (k1!=i1 && k1!=i2 && k1!=i3 && k1!=i4 && k1!=j1)
				{
					for (int k2=1; k2<=9; ++k2)
					{
						if (k2!=i1 && k2!=i2 && k2!=i3 && k2!=i4 && k2!=j1 && k2!=k1)
						{
							for (int k3=1; k3<=9; ++k3)
							{
								if (k3!=i1 && k3!=i2 && k3!=i3 && k3!=i4 && k3!=j1 && k3!=k1 && k3!=k2)
								{
									for (int k4=1; k4<=9; ++k4)
									{
										if (k4!=i1 && k4!=i2 && k4!=i3 && k4!=i4 && k4!=j1 && k4!=k1 && k4!=k2 && k4!=k3)
										{
											second = k1*1000 + k2*100 + k3*10 + k4;
											if (first * second == product)
												return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}

bool checkTwoOnThree(int i1, int i2, int i3, int i4)
{
	int product = i1*1000 + i2*100 + i3*10 + i4;

	int first=0, second=0;

	for (int j1=1; j1<=9; ++j1)
	{
		if (j1!=i1 && j1!=i2 && j1!=i3 && j1!=i4)
		{
			for (int j2=1; j2<=9; ++j2)
			{
				if (j2!=i1 && j2!=i2 && j2!=i3 && j2!=i4 && j2!=j1)
				{
					first = j1*10 + j2;

					for (int k1=1; k1<=9; ++k1)
					{
						if (k1!=i1 && k1!=i2 && k1!=i3 && k1!=i4 && k1!=j1 && k1!=j2)
						{
							for (int k2=1; k2<=9; ++k2)
							{
								if (k2!=i1 && k2!=i2 && k2!=i3 && k2!=i4 && k2!=j1 && k2!=j2 && k2!=k1)
								{
									for (int k3=1; k3<=9; ++k3)
									{
										if (k3!=i1 && k3!=i2 && k3!=i3 && k3!=i4 && k3!=j1 && k3!=j2 && k3!=k1 && k3!=k2)
										{
											second = k1*100 + k2*10 + k3;
											if (first * second == product)
												return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital. \n";

    QueryPerformanceCounter(&lTime1);

    int answer = 0;

	for (int i=1; i<=9; ++i)
	{
		for (int j=1; j<=9; ++j)
		{
			if (i!=j)
				for (int k=1; k<=9; ++k)
				{
					if (i!=k && j!=k)
						for (int l=1; l<=9; ++l)
						{
							if (i!=l && j!=l && k!=l)
							{
								if (checkOneOnFour(i,j,k,l) || checkTwoOnThree(i,j,k,l))
									answer += i*1000 + j*100 + k*10 + l;
							}
						}
				}
		}
	}

        
    cout << "Answer: " <<  answer << "\n";

    //function
    QueryPerformanceCounter(&lTime2);
    diffTicks=lTime2.QuadPart-lTime1.QuadPart;  // ticks passed

    cout << "Execution Time : " << diffTicks << " ticks.\n";
    getchar();
	return 0;
}

