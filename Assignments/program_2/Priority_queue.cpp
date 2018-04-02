////////////////////////////////////////////////////////////////////////////////
//																			  //
// Title:            Priority Queue											  //
// Files:            input_data.txt											  //
// Semester:         CMPS 1063 Spring 2018                                    //
//																			  //
// Author:           Jesse Baze												  //
// Email:            jessebaze29@gmail.com									  //
// Description:																  //
//       This program will read the one of the instructions "push" or "pop"	  //
//	if the instruction is push it will read the name of an animal on push it  //
//  into the list. If the instruction is pop it will pop off the next animal  // 
//	that is in line from the queue.											  //
//		 The file "priority_out.txt" is organized where the pops			  //
//  are at the top of the file, they are numbered and displayed in the	      //
//	ordered they were popped. The bottom of the file displays the animals     //
//  that are left in the queue, these animals are organized by one, shorter   //
//  names have higher priority, and two, if two or more animals names are the //
//  same length it will then alphabetically order those animals.              //
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//desc
struct Node
{
	string word;
	Node *next;
	Node()
	{
		word = " ";
		next = NULL;
	}
	Node(string w)
	{
		word = w;
		next = NULL;
	}
};

// class Queue
// Creates a priorty queue using the node struct
// in a linked list, where the shroter lengthed strings
// have higher priorty.

// Methods:
// string pop()
// void push()
// void sort()
// void Read_pop()
// void print_q()
// void Swap
class Queue
{
private:
	Node *Front;
	Node *Rear;
	ifstream infile;
	ofstream outfile;
public:

	/*
	* Queue
	* constructor
	* params:
	*     - none
	*/
	Queue()
	{
		Front = Rear = NULL;
	}

	/*
	* Function pop:
	*      Pops an item off the queue.
	* Params:
	*      none
	* Returns
	*      string
	*/
	string pop()
	{
		if (Front != NULL)
		{
			Node* temp = Front; // temp pointer so we can delete node
			string w = temp->word; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;		// give mem back to system
			return w;
		}
		else
			return "error: cannot pop off an empty queue.";

	}

	/*
	* Function push:
	*      Pushes the string into the queue
	* Params:
	*      a string
	* Returns
	*      string
	*/
	void push(string w)
	{
		Node *temp = new Node(w);

		if (Front == NULL)
		{
			Front = temp;
			Rear = temp;
		}
		else
		{
			Rear->next = temp;
			Rear = temp;
		}
	}

	/*
	* Function sort:
	*      Sorts the queue based on the rules set
	* Params:
	*      none
	* Returns
	*      none
	*/
	void sort()
	{
		//sets temp to the front of the queue
		Node *temp = Front;

		//makes sure the list isn't empty
		if (Front == NULL)
		{
			return;
		}

		//Bubblesorts the linked list
		while (temp->next != NULL)
		{

			//checks the higher priorty string if it's longer in length
			if (temp->word.length() > temp->next->word.length())
			{
				swap(temp->next->word, temp->word);
			}

			//checks if both strings are the same length
			else if (temp->word.length() == temp->next->word.length())
			{
				//Will alphabetically the two strings in the queue
				if (temp->word > temp->next->word)
				{
					swap(temp->next->word, temp->word);
				}
			}
			temp = temp->next;
		}
	}

	/*
	* Function Read_pop:
	*      Reads the infile and will print out the
		popped animals
	* Params:
	*      none
	* Returns
	*      none
	*/
	void Read_pop()
	{
		infile.open("input_data.txt");
		outfile.open("priority_out.txt");

		string animal, instruc;
		int num = 0;
		int items = 1;

		outfile << "Animals Popped off the Queue:\n\n";
		while (!infile.eof())
		{
			infile >> instruc >> animal;

			//will push the animal to the list
			if (instruc == "push")
			{
				push(animal);
				items++;
			}

			//prints the pops 
			else if (instruc == "pop")
			{
				outfile << setw(3) << ++num << " " << pop() << endl;
				items--;

			}

			//will sort depending on the number of animals pushed
			if (items > 0)
			{
				for (int i = 0; i < items - i; i++)
				{
					sort();
				}
			}
		}
		outfile << endl;
	}

	/*
	* Function print_q:
	*      Prints the animals remaining in the queue
		in their correct order
	* Params:
	*      none
	* Returns
	*      none
	*/
	void print_q()
	{
		Node *temp = Front;
		int num = 0;
		outfile << "Animals Remaining on the Queue (in order of priorty):\n\n";
		while (temp)
		{
			outfile <<setw(2) << ++num << " " << temp->word << endl;
			temp = temp->next;
		}
	}

	/*
	* Function print_q:
	*      easy function call used to just swap the two
		animals/strings that need to be swapped
	* Params:
	*      two strings
	* Returns
	*      none
	*/
	void Swap(string i, string j)
	{
		string swapper;

		swapper = i;
		i = j;
		j = swapper;
	}
};


int main()
{
	Queue Q;

	Q.Read_pop();
	Q.print_q();

	return 0;
}
