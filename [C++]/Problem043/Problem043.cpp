#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef unsigned long long int64;

int main()
{
    LARGE_INTEGER lTime1;
    LARGE_INTEGER lTime2;
    long diffTicks;

    cout << "Find the sum of all pandigital numbers with an unusual sub-string divisibility property. \n";

    QueryPerformanceCounter(&lTime1);

	int64 answer = 0;

	short number[10] = {0};

	for (number[0]=1; number[0]<10; ++number[0])
	{
		for (number[1]=0; number[1]<10; ++number[1])
		{
			if (number[1]!=number[0])
				for (number[2]=0; number[2]<10; ++number[2])
				{
					if (number[2]!=number[0] && number[2]!=number[1])
						for (number[3]=0; number[3]<10; number[3]+=2)
						{
							if (number[3]!=number[0] && number[3]!=number[1] && number[3]!=number[2] && ((number[1]*100+number[2]*10+number[3])%2==0))
								for (number[4]=0; number[4]<10; ++number[4])
								{
									if (number[4]!=number[0] && number[4]!=number[1] && number[4]!=number[2] && number[4]!=number[3] && ((number[2]*100+number[3]*10+number[4])%3==0))
										for (number[5]=0; number[5]<10; number[5]+=5)
										{
											if (number[5]!=number[0] && number[5]!=number[1] && number[5]!=number[2] && number[5]!=number[3] && number[5]!=number[4] && ((number[3]*100+number[4]*10+number[5])%5==0))
												for (number[6]=0; number[6]<10; ++number[6])
												{
													if (number[6]!=number[0] && number[6]!=number[1] && number[6]!=number[2] && number[6]!=number[3] && number[6]!=number[4] && number[6]!=number[5] && ((number[4]*100+number[5]*10+number[6])%7==0))
														for (number[7]=0; number[7]<10; ++number[7])
														{
															if (number[7]!=number[0] && number[7]!=number[1] && number[7]!=number[2] && number[7]!=number[3] && number[7]!=number[4] && number[7]!=number[5] && number[7]!=number[6] && ((number[5]*100+number[6]*10+number[7])%11==0))
																for (number[8]=0; number[8]<10; ++number[8])
																{
																	if (number[8]!=number[0] && number[8]!=number[1] && number[8]!=number[2] && number[8]!=number[3] && number[8]!=number[4] && number[8]!=number[5] && number[8]!=number[6] && number[8]!=number[7] && ((number[6]*100+number[7]*10+number[8])%13==0))
																		for (number[9]=0; number[9]<10; ++number[9])
																		{
																			if (number[9]!=number[0] && number[9]!=number[1] && number[9]!=number[2] && number[9]!=number[3] && number[9]!=number[4] && number[9]!=number[5] && number[9]!=number[6] && number[9]!=number[7] && number[9]!=number[8] && ((number[7]*100+number[8]*10+number[9])%17==0))
																			{
																				int64 mul=1000000000;
																				for (int j=0; j<10; ++j)
																				{
																					answer+=number[j]*mul;
																					mul /= 10;
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

