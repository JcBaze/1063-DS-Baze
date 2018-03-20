//Just playing around with classes an arrays 

/*Program finds the most accuring number in an array.
Reads numbers from a file under 2000 numbers.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class ArrayManip
{
private:
	ifstream infile;
	int Temp_Array[2000]; //temp array that is bigger than the file.
	int *Array = new int[ArraySize_Load()];
	int size;

public:
	int ArraySize_Load()
	{
		infile.open("arraynumbers.txt");
		size = 0;

		while (infile >> Temp_Array[size])
		{
			size++;
		}
		infile.close();							//must close the file so it will read from the start if called again
		return size;
	}


	void CopyArray()
	{
		int testsize = ArraySize_Load();

		for (int i = 0; i < testsize; i++)
		{
			Array[i] = Temp_Array[i];
			//cout << Temp_Array[i] << endl;
		}
	}

	//Finds and prints the most common number
	void output()
	{
		int common = 0;
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			int temp_com = Array[i];
			int tempcounter = 0;

			for (int j = 0; j < size; j++)
			{
				if (Array[j] == temp_com)
					tempcounter++;

				if (tempcounter > counter)
				{
					common = temp_com;
					counter = tempcounter;
				}
			}
		}
		cout << "The most frequent number in the array is " << common << " and the number is in the array " << counter << " times." << endl;
	}
};

int main()
{
	ArrayManip Arrayinfo;

	Arrayinfo.CopyArray();
	cout << "The Array has " << Arrayinfo.ArraySize_Load() << " elements.\n\n";
	Arrayinfo.output();


	system("Pause");
	return 0;
}
