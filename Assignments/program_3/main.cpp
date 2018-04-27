#include <iostream>
#include <fstream>
#include <string>
#include "DBHeader.h"

using namespace std;

int main() 
{
	DBList List;

	//Reads from the infile filling the list
	List.FillList();

	//starts from reading the users number and end with printing the results
	List.getNumber();

	return 0;
}
