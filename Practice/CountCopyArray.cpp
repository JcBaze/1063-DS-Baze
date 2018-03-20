#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class ArrayManip
{
private:
	ifstream infile;
	int Temp_Array[200];
	int *Array = new int[ArraySize_Load()];

public:
	int ArraySize_Load()
	{
		infile.open("arraynumbers.txt");
		int size = 0;

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
			cout << Temp_Array[i] << endl;
		}
	}

	void output()
	{
		cout << Array[2];
	}
};

int main()
{
	ArrayManip Arrayinfo;

	Arrayinfo.CopyArray();
	cout << "The Array has " << Arrayinfo.ArraySize_Load() << " elements\n";
	Arrayinfo.output();


	system("Pause");
	return 0;
}
