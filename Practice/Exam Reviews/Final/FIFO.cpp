struct Node
{
	int Data;
	Node *Next;

	Node(int x)
	{
		Data = x;
		Next = NULL;
	}
};

class list
{
private:
	Node *Head;
	Node *Tail;

public:

	list()
	{
		Head = Tail = NULL;
	}

	void load(int x)
	{
		Node *temp = new Node(x);
		if (!Head)
		{
			Head = temp;
			Tail = temp;
		}

		else
		{
			Tail->Next = temp;
			Tail = temp;
		}
	}
