/////////////////////////////////
// List Based Queue
// 
// First In First Out 
//
// Method:
//    void push()
//    string pop()
//    bool empty()
//    bool full() ?????

//info 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

//desc
class Queue
{
private:
	Node *Front;
	Node *Rear;
	string longest, shortest;
	ifstream infile;
	ofstream outfile;
public:
	//desc
	Queue()
	{
		Front = Rear = NULL;
	}

	//desc
	string pop(string w) 
	{
		if (Front != NULL) 
		{
			Node* temp = Front;   // temp pointer so we can delete node
			string w = temp->word; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return w;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return "";
		}
	}

	//desc
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

	//desc
	void print() 
	{
		//outfile.open("priority_out.txt");
		string wtemp;
		Node *temp = Front;
		Node *i, *j;

		//Bubblesort the linked list
		for (i = Front; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (i->word.length() > j->word.length())
				{
					Swap(i, j);
				}

				/*else if (i->word.length() == j->word.length())
				{
					int length = i->word.length();

					for (int k = 0; k < length; k++)
					{
						if ((int)i->word[k] > (int)j->word[k])
						{
							Swap(i, j);
						}
					}
				}*/
			}
		}

		while (temp)
		{
			cout << temp->word << endl;
			temp = temp->next;
		}
	}		

	//desc
	void ReadFile()
	{
		string animal;
		infile.open("animals.txt");

		while (!infile.eof())
		{
			infile >> animal;
			push(animal);
		}
	}

	//desc
	void Swap(Node *i, Node *j)
	{
		string wtemp;

		wtemp = i->word;
		i->word = j->word;
		j->word = wtemp;
	}
};


int main()
{
	Queue Q;

	Q.ReadFile();
	Q.print();

	system("pause");
	return 0;
}
