#pragma once

template <class T>
struct SListItem
{
	T value; // Data Item
	SListItem<T>* next; // Pointer to the next item of the List

	T& getValue() { return value; }
};

template <class T>
class SList
{
	SListItem<T>* head;

public:

	// Default Constructor
	SList()
	{
		head = NULL;
	}

	// Copy Constructor
	SList(const SList<T>& other)
	{
		if (other.head == NULL)
			head = NULL;
		else
		{
			SListItem<T>* current1 = other.head;
			head = new SListItem<T>;
			head->value = current1->value;
			current1 = current1->next;

			if (current1 == NULL)
				head->next = NULL;
			else
			{
				SListItem<T>* current2 = head;

				while (current1 != NULL)
				{
					current2->next = new SListItem<T>;
					current2 = current2->next;

					current2->value = current1->value;
					current1 = current1->next;
				}

				current2->next = NULL;
			}
		}

	}

	// Overloaded Assignment Operator
	SList<T> operator = (const SList<T>& other)
	{
		if (&other != this)
		{
			if (head != NULL)                   // If list isn't empty then delete the whole list
			{
				SListItem<T>* current = head;

				while (current != NULL)
				{
					SListItem<T>* temp = current;
					current = current->next;
					delete temp;
				}

				head = NULL;
			}

			if (other.head == NULL)
				head = NULL;
			else
			{
				SListItem<T>* current1 = other.head;
				head = new SListItem<T>;
				head->value = current1->value;

				current1 = current1->next;

				if (current1 == NULL)
					head->next = NULL;
				else
				{
					SListItem<T>* current2 = head;

					while (current1 != NULL)
					{
						current2->next = new SListItem<T>;
						current2 = current2->next;

						current2->value = current1->value;
						current1 = current1->next;
					}

					current2->next = NULL;
				}
			}

		}

		return *this;
	}

	// Destructor
	~SList()
	{
		if (head != NULL)
		{
			SListItem<T>* current = head;

			while (current != NULL)
			{
				SListItem<T>* temp = current;
				current = current->next;

				delete temp;
			}
		}
	}

	void insertAtHead(T item)
	{
		SListItem<T>* temp = new SListItem<T>;
		temp->value = item;

		temp->next = head;
		head = temp;
	}

	void insertAtTail(T item)
	{
		SListItem<T>* temp = new SListItem<T>;
		temp->value = item;

		SListItem<T>* current = head;

		if (current == NULL)  // If the list is empty
			head = temp;
		else
		{
			while (current->next != NULL)  // Reach the end of the list
				current = current->next;

			current->next = temp;
		}

		temp->next = NULL;   // The end item of the list always points to null
	}

	void insertSorted(T item)
	{
		SListItem<T>* temp = new SListItem<T>;
		temp->value = item;

		SListItem<T>* current = head;
		SListItem<T>* previous = NULL;

		while (current != NULL && current->value > item)
		{
			previous = current;
			current = current->next;
		}

		temp->next = current;

		if (current == head)
			head = temp;
		else
			previous->next = temp;
	}

	SListItem<T>* getHead() { return head; }

	SListItem<T>* getTail()
	{
		if (head == NULL)
			return NULL;
		else
		{
			SListItem<T>* current = head;

			while (current->next != NULL)  // Traverses the whole list till the end is reached
				current = current->next;

			return current;
		}
	}

	SListItem<T>* searchFor(T item)
	{
		if (head == NULL)
			return NULL;
		else
		{
			SListItem<T>* current = head;

			while (current != NULL && current->value >= item)
			{
				if (current->value == item)
					return current;

				current = current->next;
			}

			return NULL;
		}
	}

	void deleteElement(T item)
	{
		if (head != NULL) //If the list isn't empty
		{
			SListItem<T>* current = head;
			SListItem<T>* previous = head;

			while (current->next != NULL && current->value > item)
			{
				previous = current;
				current = current->next;
			}

			//If the element is found.
			if (current->value == item)
			{
				if (current == head)
					head = head->next;
				else
					previous->next = current->next;

				delete current;
			}
		}
	}

	void deleteHead()
	{
		if (head != NULL)
		{
			SListItem<T>* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void deleteTail()
	{
		if (head != NULL)
		{
			SListItem<T>* current = head;
			SListItem<T>* previous = NULL;

			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}

			if (current == head)
				head = NULL;
			else
				previous->next = NULL;

			delete current;
		}
	}

	int length()
	{
		int length = 0;
		SListItem<T>* current = head;

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
			SListItem<T>* current = head;

			while (current != NULL)
			{
				cout << current->value << endl;
				current = current->next;
			}
		}

		else
			cout << "\nList is empty !" << endl;
	}

	void displayFunctions()
	{
		cout << "\n1)insertAtHead\n2)insertAtTail\n3)insertSorted\n4)getHead\n5)getTail"
			<< "\n6)searchFor\n7)deleteElement\n8)deleteHead\n9)deleteTail\n10)Print List\n11)Length of List";

		cout << "\nEXIT -> -1\nOption Number : ";
	}

	//Adds the duplicate values in a list and de-allocates the space consumed by the duplicate
	void addDuplicates()
	{
		SListItem<T>* current = head;
		SListItem<T>* previous = NULL;

		if (current != NULL && current->next != NULL)
		{
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;

				if (previous->value == current->value)
				{
					current->value = current->value + previous->value;

					deleteElement(previous->value);
				}
			}
		}
	}
};