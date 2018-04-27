#include <iostream>
#include <string>
#include "DBHeader.h"

using namespace std;


DBList::DBList()
{
	Head = NULL;
	Tail = NULL;
}

/*
* Function LoadList -
*     Will insert the string into a new temp node
* which will then send to LoadList(Node) to be placed into the list
* Params:
*     string : data element to be inserted
*/
void DBList::LoadList(string Data)
{
	Node* Temp = new Node(Data);
	LoadList(Temp);
}

/*
* Function LoadList -
*     Inserts the temp node into the linked list
* Params:
*     Node: The temp node from the LoadList(String)
*/
void DBList::LoadList(Node* &Temp)
{
	if (!Tail)
	{
		Tail = Temp;
		Head = Temp;
		Head->Prev = Tail;
		Current = Temp;
		Tail->Next = Temp->Next;
	}
	else
	{
		Temp->Prev = Tail;
		Temp->Next = Head;
		Tail->Next = Temp;
		Head->Prev = Temp;
		Tail = Temp;
		Current = Head;
	}
}

/*
* Function getNumber -
*     Askes the user for a multiplyer number and checks
* if its the correct range
* Params:
*     None
*/
void DBList::getNumber()
{
	int m;
	cout << "Please enter a number between 1 and 13.\n";
	cin >> m;

	//check the range of m
	while (m < 1 || m > 13)
	{
	cout << "I SAID, PLEASE ENTER A NUMBER BETWEEN 1 AND 13.\n";
	cin >> m;
	}

	//function to multiply m
	Multiplier(m);
}

/*
* Function FillList -
*     Reads the animals name from the file and will send the data
* to LoadList with the string
* Params:
*     None
*/
void DBList::FillList()
{
	string a;
	ifstream infile("animals.txt");

	while (!infile.eof())
	{
		infile >> a;
		LoadList(a);
	}

	//resets the infile to the beginning of the file for more use later
	infile.clear();
	infile.seekg(0);
}

/*
* Function Multiplier -
*     This fucntion will multiply the users number by the current character
* length of the animal that is being read. Also well as keep track of how many
* timese the loop is running so the first animal will be displayed correctly.
* Params:
*     int m - users input value
*/
void DBList::Multiplier(int m)
{
	ifstream infile("animals.txt");
	ofstream outfile("eliminated.txt");
	string a;
	int times_thru = 0;
	while (!infile.eof())
	{
		infile >> a;
		int jumps = a.length();		//Gets and stores the string length

		jumps = jumps * m;

		Traverse(jumps, times_thru++,outfile); /*increments times_thru and sends the amount of 
											   jumps to Traverse*/
	}
}

/*
* Function Traverse - 
*	Depending if j (jumps) is even or odd it will traverse the 
* the list in the correct way to land on the next animal.    
* Params:
*     int j - the amount of jumps
*	  int t - number of animals that have been read
*	  ofstream outfile - where the result will be printed
*/
void DBList::Traverse(int j, int t, ofstream &outfile)
{
	//even number traversal
	if (j % 2 == 0)
	{
		for (int i = j; i > 0; i--)
		{
			Current = Current->Next;
		}
	}

	//odd number traversal
	else
	{
		for (int i = j; i > 0; i--)
		{
			Current = Current->Prev;
		}
	}
	Delete_Display(Current->Data,t,outfile); //will remove the Current node
}

/*
* Function Delete_Display -
*		Will display the node currents location and delete it from the list, while
*			reorganizing the list correctly.
*
* Params:
*     string x - name of the animal being deleted from list
*	  int t - if it == zero it indicates that animal is the first one out
*					for correct format of the outfile
*     ofstream outfile - where the result will be printed
*/
void DBList::Delete_Display(string x, int t, ofstream &outfile)
{
	//displays the winner
	if (x == Head->Data && x == Tail->Data)
	{
		outfile << "WINNER: " << Current->Data << " !!" << endl;
	}
	//if current is == to the head node
	else if (x == Head->Data)
	{
		if (t == 0)
			outfile << "First: " << Current->Data << endl;
		else
			outfile << "- " << Current->Data << endl;

		//deletes currents/heads location and readjust the list
		Node *temp = Head;
		Head = Head->Next;
		Head->Prev = temp->Prev;
		delete temp;
		Current = Head;
		Tail->Next = Head;
	}
	//if current == to tail node
	else if (x == Tail->Data)
	{
		if (t == 0)
			outfile << "First: " << Current->Data << endl;
		else
			outfile << "- " << Current->Data << endl;

		//deletes currents/tails location and readjust the list
		Node *temp = Tail;
		Tail = Tail->Prev;
		Tail->Next = temp->Next;
		delete temp;
		Current = Tail;
		Head->Prev = Tail;
	}
	
	//if head & tail != currents location
	else
	{
		if (t == 0)
			outfile << "First: " << Current->Data << endl;
		else
			outfile << "- " << Current->Data << endl;

		//searches for currents location from head
		Node *temp = Head;
		while (temp != Current)
		{
			temp = temp->Next;
		}
		//deletes currents location and readjust the list
		Node *middle = temp;
		middle->Prev->Next = middle->Next;
		middle->Next->Prev = middle->Prev;
		Current = Current->Next;
		delete middle;
	}
}
