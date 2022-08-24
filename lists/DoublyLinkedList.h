#pragma once

template <class T>
struct ListItem
{
	T value; // Data Item
	ListItem<T>* previous; // Pointer to the previous item of the list
	ListItem<T>* next; // Pointer to the next item of the List

	T& getValue() { return value; }
};

template <class T>
class List
{
	ListItem<T>* head;
	ListItem<T>* tail;

public:

	// Default Constructor
	List()
	{
		head = tail = NULL;
	}

	// Copy Constructor
	List(const List<T>& other)
	{
		if (other.head == NULL)
			head = NULL;
		else
		{
			ListItem<T>* current1 = other.head;
			head = tail = new ListItem<T>;
			head->previous = NULL;
			head->value = current1->value;
			current1 = current1->next;

			if (current1 == NULL)
				head->previous = NULL;
			else
			{
				ListItem<T>* current2 = head;

				while (current1 == NULL)
				{
					current2->next = new ListItem<T>;
					current2->next->previous = current2;
					current2 = current2->next;

					current2->value = current1->value;
					current1 = current1->next;
				}

				current2->next = NULL;
				tail = current2;
			}
		}
	}

	// Overloaded Assignment Operator
	List<T> operator=(const List<T>& other)
	{
		if (&other != this)
		{
			if (head != NULL) // If list isn't empty then delete the whole list
			{
				ListItem<T> current = head;

				while (current != NULL)
				{
					List<T>* temp = current;
					current = current->next;

					delete temp;
				}

				head = tail = NULL;
			}

			if (head == NULL) // If the other list is empty then make the current list empty too
				head = NULL;
			else
			{
				ListItem<T>* current1 = other;
				head = tail = new ListItem<T>;
				head->previous = NULL;
				head->value = current1->value;
				current1 = current1->next;

				if (current1 == NULL)
					head->next = NULL;
				else
				{
					ListItem<T>* current2 = head;

					while (current1 != NULL)
					{
						current2->next = new ListItem<T>;
						current2->next->previous = current2;
						current2 = current2->next;

						current2->value = current1->value;
						current1 = current1->next;
					}

					current2->next = NULL;
					tail = current2;
				}
			}
		}

		return *this;
	}

	// Destructor
	~List()
	{
		if (head != NULL)
		{
			ListItem<T>* current = head;

			while (current != NULL)
			{
				ListItem<T>* temp = current;
				current = current->next;

				delete temp;
			}
		}
	}

	void insertAtHead(T item)
	{
		ListItem<T>* temp = new ListItem<T>;
		temp->value = item;

		temp->next = head;
		temp->previous = NULL;

		if (head != NULL)
			temp->next->previous = temp;
		else
			tail = temp;

		head = temp;
	}

	void insertAtTail(T item)
	{
		ListItem<T>* temp = new ListItem<T>;
		temp->value = item;

		temp->previous = tail;
		temp->next = NULL;

		if (tail != NULL)
			temp->previous->next = temp;
		else
			head = temp;

		tail = temp;
	}

	ListItem<T>* insertSorted(T& item)
	{

		ListItem<T>* temp = new ListItem<T>;
		temp->value = item;

		if (head == NULL)       // If the list is empty
		{
			temp->previous = temp->next = NULL;
			head = tail = temp;
		}
		else
		{
			ListItem<T>* current = head;

			while (current->next != NULL && current->value < item)
				current = current->next;

			if (current == head)
			{
				if (temp->value > current->value)
				{
					temp->previous = current;
					temp->next = current->next;

					if (current->next = NULL)
						tail = temp;

					current->next = temp;
				}

				else
				{
					temp->previous = NULL;
					temp->next = current;
					current->previous = temp;
					head = temp;
				}
			}
			else
			{
				if (temp->value > current->value)
				{
					temp->next = NULL;
					temp->previous = current;
					current->next = temp;
					tail = temp;
				}

				else
				{
					temp->previous = current->previous;
					temp->next = current;
					current->previous->next = temp;
					current->previous = temp;
				}
			}
		}

		return temp;
	}

	ListItem<T>* getHead() { return head; }
	ListItem<T>* getTail() { return tail; }

	ListItem<T>* searchForL(T item)
	{
		if (head == NULL)                // If the list is empty
			return NULL;
		else if (item > tail->value)
			return NULL;
		else
		{
			ListItem<T>* current = head;

			while (current != NULL && current->value <= item)
			{
				if (current->value == item)
					return current;

				current = current->next;
			}

			return NULL;
		}
	}

	void deleteElement(T& item)
	{
		if (head != NULL)
		{
			ListItem<T>* current = head;

			while (current->next != NULL && current->value < item)
				current = current->next;

			//If the element is found
			if (current->value == item)
			{
				if (current == head)
				{
					head = head->next;

					if (head == NULL)
						tail = NULL;
					else
						head->previous = NULL;
				}

				else
				{
					current->previous->next = current->next;

					if (current->next != NULL)
						current->next->previous = current->previous;
					else
						tail = current->previous;
				}

				delete current;
			}
		}
	}

	void deleteHead()
	{
		if (head != NULL)
		{
			ListItem<T>* temp = head->next;
			delete head;
			head = temp;

			if (head == NULL)
				tail = NULL;
			else
				head->previous = NULL;
		}
	}

	void deleteTail()
	{
		if (head != NULL)
		{
			ListItem<T>* temp = tail->previous;
			delete tail;
			tail = temp;

			if (tail == NULL)
				head = NULL;
			else
				tail->next = NULL;
		}
	}

	void deleteNode(ListItem<T>* node)
	{
		if (node == head)
			head = head->next;
		else if (node == tail)
			tail = tail->previous;
		else
		{
			node->previous->next = node->next;
			node->next->previous = node->previous;
		}

		if (head != NULL)
		{
			head->previous = NULL;
			tail->next = NULL;
		}
		else
			tail = NULL;

		delete node;
	}

	int length()
	{
		int length = 0;
		ListItem<T>* current = head;

		while (current != NULL)
		{
			length++;
			current = current->next;
		}

		return length;
	}

	void Print()
	{
		if (head != NULL)
		{
			ListItem<T>* current = head;

			while (current != NULL)
			{
				cout << current->value << endl;
				current = current->next;
			}
		}
		else
			cout << "\nList is empty !" << endl;
	}

	void printRange(ListItem<T>* startingNode, ListItem<T>* endingNode)
	{
		while (startingNode != endingNode)
		{
			cout << startingNode->value;

			startingNode = startingNode->next;
		}

		cout << endingNode->value;
	}

	void displayFunctions()
	{
		cout << "\n1)insertAtHead\n2)insertAtTail\n3)insertSorted\n4)getHead\n5)getTail"
			<< "\n6)searchFor\n7)deleteElement\n8)deleteHead\n9)deleteTail\n10)Print List\n11)Length of List";

		cout << "\nEXIT -> -1\nOption Number : ";
	}
};