/* 
This program will get input from the user asking them how many numbers they want printed,
and ask the user for a range of numbers from the highest and lowest number they would like.
The program will do both positive and negative numbers.
*/

#include <iostream>
#include <ctime> 
#include <cstdlib> 
using namespace std;

int main()
{
	int Rnum, low, high, size;
	srand(time(0)); 

	cout << "How many numbers would you like generated?\n";
	cin >> size;

	cout << "Enter the lowest number. \n";
	cin >> low;

	if (low < 0)
	{
		cout << "Enter the highest number. \n";
		cin >> high;

		high = (-1 * low) + high + 1;
		cout << endl;
	}

	else
	{
		cout << "Enter the highest number. \n";
		cin >> high;
		cout << endl;
	}


	for (int i = 0; i < size; i++)
	{
		Rnum = ( rand () % high) + (low); 
		cout << Rnum << endl;
	}

	system("pause");
	return 0;
}
