void swapNeighbors() 
	{
		node* prev = Head;
		node* temp = Head->next;
		int tempvar;

		//changed temp->next to just temp
		//so it will check the most traversed node
		//and since temp->next will now be the break
		while (temp) 
		{
			tempvar = temp->data;
			temp->data = prev->data;
			prev->data = tempvar;

			//breaks from the while loop so the
			//list doesn't traverse into the NULL ZONE
			if (temp->next == NULL)
			{
				break;
			}

			prev = prev->next->next;
			temp = temp->next->next;
		}
	}
