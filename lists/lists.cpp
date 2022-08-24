#include <iostream>

using namespace std;

#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"

int main()
{
    // Doubly Linked List
    List<int> list1;

    int userInput = 0;
    int data;

    while (userInput != -1)
    {
        list1.displayFunctions();
        cin >> userInput;

        if (userInput == 1)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertAtHead(data);
        }
        else if (userInput == 2)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertAtTail(data);
        }
        else if (userInput == 3)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertSorted(data);
        }
        else if (userInput == 4)
        {
            if (list1.getHead() != NULL)
                cout << "\nThe value at the head of the list is " << list1.getHead()->value;
            else
                cout << "\nThe list is empty !";
        }
        else if (userInput == 5)
        {
            if (list1.getTail() != NULL)
                cout << "\nThe value at the tail of the list is " << list1.getTail()->value;
            else
                cout << "\nThe list is empty !";
        }
        else if (userInput == 6)
        {
            cout << "\nEnter the data element which is to be searched : ";
            cin >> data;

            if (list1.searchForL(data) != NULL)
                cout << "\nThe element is found !";
            else
                cout << "\nThe element is not found !";
        }
        else if (userInput == 7)
        {
            cout << "\nEnter the data to be deleted from the List : ";
            cin >> data;

            list1.deleteElement(data);
        }
        else if (userInput == 8)
            list1.deleteHead();
        else if (userInput == 9)
            list1.deleteTail();
        else if (userInput == 10)
            list1.Print();
        else if (userInput == 11)
            cout << "\n\nThe length of the list is : " << list1.length();
    }

    cout << "\nTesting the copy constructor : ";
    List<int> list2 = list1;

    cout << "\nList 2 is a copy of List 1 constructed through Copy Constructor !";

    cout << "\nList 1 : ";
    list1.Print();

    cout << "\nList 2 : ";
    list2.Print();


    //////////////////////////////////////////////////////////////////////////////////////

    // Singly Linked List
    /*SList<int> list1;

    int userInput = 0;
    int data;

    while (userInput != -1)
    {
        list1.displayFunctions();
        cin >> userInput;

        if (userInput == 1)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertAtHead(data);
        }
        else if (userInput == 2)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertAtTail(data);
        }
        else if (userInput == 3)
        {
            cout << "\nEnter the data to be inserted into the List : ";
            cin >> data;

            list1.insertSorted(data);
        }
        else if (userInput == 4)
        {
            if (list1.getHead() != NULL)
                cout << "\nThe value at the head of the list is " << list1.getHead()->value;
            else
                cout << "\nThe list is empty !";
        }
        else if (userInput == 5)
        {
            if (list1.getTail() != NULL)
                cout << "\nThe value at the tail of the list is " << list1.getTail()->value;
            else
                cout << "\nThe list is empty !";
        }
        else if (userInput == 6)
        {
            cout << "\nEnter the data element which is to be searched : ";
            cin >> data;

            if (list1.searchFor(data) != NULL)
                cout << "\nThe element is found !";
            else
                cout << "\nThe element is not found !";
        }
        else if (userInput == 7)
        {
            cout << "\nEnter the data to be deleted from the List : ";
            cin >> data;

            list1.deleteElement(data);
        }
        else if (userInput == 8)
            list1.deleteHead();
        else if (userInput == 9)
            list1.deleteTail();
        else if (userInput == 10)
            list1.Print();
        else if (userInput == 11)
            cout << "\n\nThe length of the list is : " << list1.length();
    }

    cout << "\nTesting the copy constructor : ";
    SList<int> list2 = list1;

    cout << "\nList 2 is a copy of List 1 constructed through Copy Constructor !";

    cout << "\nList 1 : ";
    list1.Print();

    cout << "\nList 2 : ";
    list2.Print();*/
}