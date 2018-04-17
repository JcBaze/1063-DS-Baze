#include <iostream>
#include <ctime>

using namespace std;

struct node 
{
	int data;
	node* next;

	node(int n)
	{
		data = n;
		next = NULL;
	}
	node()
	{

	}
};

class intLinkedList 
{
private:
	node *Head;
public:
	intLinkedList() 
	{
		Head = NULL;
	}
	void insert(int x) 
	{
		//empty list case
		if (!Head) {
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		else {//not empty list
			node* T = new node;
			T->data = x;
			T->next = Head;
			Head = T;
		}
	}

	void print() 
	{
		node* p = Head;
		if (p == NULL)
			cout << "List is empty" << endl;

		else
		{
			while (p)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	int Count(int SearchFor)
	{
		node *temp = Head;
		int counter = 0;

		while (temp)
		{
			if (temp->data == SearchFor)
				counter++;

			temp = temp->next;
		}
		return counter;
	}

	int GetNth(int index)
	{
		node *temp = Head;
		int count = 0;

		while (temp)
		{
			if (count != index)
			{
				count++;
				temp = temp->next;
			}
			else 
				return temp->data;
		}
		cout << "ERROR" << endl;
		return -999;
	}

	void DeleteList()
	{
		node *prev = Head;

		while (Head)
		{
			prev = Head;
			Head = Head -> next;
			delete prev;
		}
	}

	int Pop()
	{
		node *prev = Head;
		Head = Head->next;
		int data = prev->data;
		delete prev;
		return data;
	}

	void insertNth(int index, int data)
	{
		node *newn = new node(data);
		node *temp = Head;
		int i = 1;

		while (temp && i < index)
		{
			temp = temp->next;
			i++;
		}
		if (temp)
		{
			newn->next = temp->next;
			temp->next = newn;
		}
		else
			cout << "index out of bounds" << endl;
	}

	double Average()
	{
		double sum = 0.0;
		int count = 0;

		while (Head)
		{
			sum += Head->data;
			Head = Head->next;
			count++;
		}
		double avg = sum / count;
		return avg;
	}

};

int main() 
{

	intLinkedList mylist;

	mylist.insert(10);
	mylist.insert(8);
	mylist.insert(8);
	
	cout << mylist.Average() << endl;
	

	system("pause");
	return 0;
}
