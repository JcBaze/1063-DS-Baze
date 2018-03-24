/*
* Homework ??????????
* @Author: Jesse Baze
* @Description: Changes the string to uppercase or lowercase.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 3-23-2018
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Lower cases the string 
string tolower(string w) 
{
	for (int i = 0; i < w.length(); i++) 
	{
		//Changes the value of the character with the correct ASCII Value
		if ((int)w[i] >= 65 && (int)w[i] <= 90) 
		{
			w[i] = w[i] + 32;
		}
	}
	return w;
}

//Upper cases the string, "THE HOMEWORK ASSIGNMENT"
string toupper(string w)
{
	for (int i = 0; i < w.length(); i++)
	{

		if ((int)w[i] >= 97 && (int)w[i] <= 122)
		{
			w[i] = w[i] - 32;
		}
	}
	return w;
}


int main()
{
	string x = "d A m N  tHiS sHit c O o L";

	cout << tolower(x) << endl;
	cout << toupper(x) << endl;

	system("pause");
	return 0;
}
