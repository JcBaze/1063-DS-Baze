////////////////////////////////////////////////////////////////////////////////
//																			  //
// Title:            Survival of the Lucky                                    //
// Files:            animals.txt											  //
// Semester:         CMPS 1063 Spring 2018                                    //
//																			  //
// Author:           Jesse Baze												  //
// Email:            jessebaze29@gmail.com									  //
// Description:																  //
//				Based on "Flavius Josephus" problem he encounter, this        //
// program pursures to display the journey of the problem. His problem threw  //
// him into a circle where every 3rd spot that person would have to commit    //
// suicide, until there was a soul survivor. Now to what the program does.    //
//				Instead of a physical circle the program will use a circular  //
// linked list to store in this case the names of animals. Instead of every   //
// third animal being picked the user will be asked to give a number between  //
// 1 and 13 and the number will be multiplyed by the character length of      //
// the current animal's name. To make it even more random, if the number is   //
// even the program will traverse the list from left to right and visa versa  //
// for odd numbers. Furthermore, instead of the animals commiting suicide the //
// picked ones will be sent to Noah's Wonderful Ark, beside the winner        //
// the winner will go to the slaughterhouse! After each animal is picked it   //
// will be deleted from the list and will then start traversing from the one  //
// the right of it. Once completed it will display the order in which each    //
// animal was removed and display who was first out and the lucky winner...!  //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Struct Node
//Builds a node that will have a next and prev pointer to other nodes
//and holds a string data type
struct Node 
{
	string Data;

	Node *Prev;
	Node *Next;
	/*
	* Node
	* constructor
	* params:
	*     - string
	*/
	Node(string x) 
	{
		Data = x;
		Prev = NULL;
		Next = NULL;
	}
};

//Class DBList
//Used to display the classes used it DBList.cpp
class DBList
{
private:
	Node *Head;
	Node *Tail;
	Node *Current;
public:
	DBList();
	void LoadList(string);
	void LoadList(Node*&);
	void Multiplier(int);
	void getNumber();
	void FillList();
	void Delete_Display(string, int, ofstream&);
	void Traverse(int, int, ofstream &);
};
