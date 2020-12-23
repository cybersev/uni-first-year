// Week 5 challenge Lewis Burrows

#include <iostream>
using namespace std;

int numbers[3] = { 11,2,4 };	//set an array with three integers
int minimum = numbers[0];	//assign the first value as minimum
int maximum = numbers[3];	//assign the last value as maximum

int main()
{
	for (int i = 1; i < 3; i++)	//loop the array values
								//changed i<4 to i<3
	{
		if (minimum > numbers[i])	//check if it is smallest
			minimum = numbers[i];		//update the value
										// changed number[i] to numbers[i];
	}
	for (int i = 0; i < 3; i++)	//loop the array values
	{
		if (maximum < numbers[i])	//check if it is largest
			maximum = numbers[i];		//update the value
	}
	cout << "Minimum is " << minimum << "\n";	//print the value
	cout << "Maximum is " << maximum << "\n";	//print the value
	return 0;
}