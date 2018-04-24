#include <iostream>
#include <string>
#include "DBHeader.h"

using namespace std;

DBList::DBList()
{
	Head = NULL;
	Tail = NULL;
}

/**
* InsertFront -
*     Inserts a value at the front of the list by calling
*     actual insert with a node.
* Params:
*     string : data element to be inserted
*/
void DBList::LoadList(string Data)
{
	Node* Temp = new Node(Data);
	LoadList(Temp);
}

/**
* InsertFront -
*     Inserts a value at the front of the list
* Params:
*     Node*& : node to be appended to front
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

void DBList::getNumber()
{
	double m;
	cout << "Please enter a number between 0 and 32767.\n";
	cin >> m;

	while (m < 1 || m > 32767)
	{
	cout << "I SAID, PLEASE ENTER A NUMBER BETWEEN 0 AND 32767.\n";
	cin >> m;
	}

	Multiplier(m);
}

void DBList::FillList()
{
	string a;
	ifstream infile("animals.txt");

	while (!infile.eof())
	{
		infile >> a;
		LoadList(a);
	}

	infile.clear();
	infile.seekg(0);
}

void DBList::Multiplier(int m)
{
	ifstream infile("animals.txt");
	string a;

	cout << "First: ";
	int times_thru = 0;
	while (!infile.eof())
	{
		infile >> a;
		int jumps = a.length();

		jumps = jumps * m;

		Traverse(jumps, times_thru++);
	}
}

void DBList::Traverse(int j, int i)
{
	if (j % 2 == 0)
	{
		for (int i = j; i > 0; i--)
		{
			Current = Current->Next;
		}
	}

	else
	{
		for (int i = j; i > 0; i--)
		{
			Current = Current->Prev;
		}
	}
	Delete(Current->Data,i);
}

void DBList::Delete(string x, int i)
{
	if (x == Head->Data && x == Tail->Data)
	{
		cout << "WINNER: " << Current->Data << " !!" << endl;
	}
	else if (x == Head->Data)
	{
		if (i == 0)
			cout << Current->Data << endl;
		else
			cout << "- " << Current->Data << endl;

		Node *temp = Head;
		Head = Head->Next;
		Head->Prev = temp->Prev;
		delete temp;
		Current = Head;
		Tail->Next = Head;
	}
	else if (x == Tail->Data)
	{
		if (i == 0)
			cout << Current->Data << endl;
		else
			cout << "- " << Current->Data << endl;

		Node *temp = Tail;
		Tail = Tail->Prev;
		Tail->Next = temp->Next;
		delete temp;
		Current = Tail;
		Head->Prev = Tail;
	}
	else
	{
		if (i == 0)
			cout << Current->Data << endl;
		else
			cout << "- " << Current->Data << endl;

		Node *temp = Head;
		while (temp != Current)
		{
			temp = temp->Next;
		}
		Node *middle = temp;
		middle->Prev->Next = middle->Next;
		middle->Next->Prev = middle->Prev;
		Current = Current->Next;
		delete middle;
	}
}
