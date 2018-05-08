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
	Node *Top;

public:
	list()
	{
		Top = NULL;
	}

	void Push(int x)
	{
		Node *temp = new Node(x);

		if (Top == NULL)
			Top = temp;

		else
		{
			temp->Next = Top;
			Top = temp;
		}
	}

	int Pop()
	{
		if (Top == NULL)
			return -9999;

		Node *temp = Top;
		Top = Top->Next;
		int data = temp->Data;
		delete temp;
		return data;
	}
};
