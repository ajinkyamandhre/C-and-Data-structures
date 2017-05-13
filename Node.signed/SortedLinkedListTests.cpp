
/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

/***** Modify this file to test both integers
 ***** and strings in the linked list.        */

#include "SortedLinkedList.h"

using namespace std;

template <class T>
void dump(SortedLinkedList<T> *list)
{
    Node<T> *p = list->get_head();

    if (p == nullptr)
    {
        cout << " <empty>" << endl;
        return;
    }

    while (p != nullptr)
    {
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
}

template <class T>
void test_integer()
{
    SortedLinkedList<T> *list = new SortedLinkedList<T>();
    cout << endl << "Integer test" << endl << endl;

    const int INSERT[] = {50, 20, 70, 10, 100, 80, 90, 30, 40, 60};
    const int INSERT_LENGTH = sizeof(INSERT)/sizeof(INSERT[0]);

    for (int i = 0; i < INSERT_LENGTH; i++) {
        int value = INSERT[i];
        cout << "Inserting " << setw(3) << value << ":";
        list->insert(value);
        dump(list);
    }

    const int SEARCH[] = {70, 15, 100, 80, 95, 110, 60};
    const int SEARCH_LENGTH = sizeof(SEARCH)/sizeof(SEARCH[0]);

    for (int i = 0; i < SEARCH_LENGTH; i++)
    {
        int value = SEARCH[i];
        cout << setw(3) << value << " ";

        Node<T> *p = list->find(value);
        if (p != nullptr) cout << "found";
        else              cout << "not found";
        cout << endl;
    }

    const int REMOVE[] = {40, 90, 10, 115, 20, 80, 50, 70, 50, 100, 30, 60, 20};
    const int REMOVE_LENGTH = sizeof(REMOVE)/sizeof(REMOVE[0]);

    for (int i = 0; i < REMOVE_LENGTH; i++)
    {
        int value = REMOVE[i];
        cout << "Removing " << setw(3) << value << ":";
        list->remove(value);
        dump(list);
    }

    delete list;
}

template <class T>
void test_string()
{


    SortedLinkedList<T> *list = new SortedLinkedList<T>();
    cout << endl << "String test" << endl << endl;

    const string INSERT[] = {"science", "math", "physics", "chemistry",
                             "english", "history", "tennis"};
    const int INSERT_LENGTH = sizeof(INSERT)/sizeof(INSERT[0]);

    for (int i = 0; i < INSERT_LENGTH; i++) {
        string value = INSERT[i];
        cout << "Inserting " << setw(9) << value << ":";
        list->insert(value);
        dump(list);
    }

    const string SEARCH[] = {"physics", "astronomy", "history", "math", "art"};
    const int SEARCH_LENGTH = sizeof(SEARCH)/sizeof(SEARCH[0]);

    for (int i = 0; i < SEARCH_LENGTH; i++)
    {
        string value = SEARCH[i];
        cout << setw(9) << value << " ";

        Node<T> *p = list->find(value);
        if (p != nullptr) cout << "found";
        else              cout << "not found";
        cout << endl;
    }

    const string REMOVE[] = {"science", "history", "tennis", "chemistry",
                             "math", "history", "physics", "art", "english"};
    const int REMOVE_LENGTH = sizeof(REMOVE)/sizeof(REMOVE[0]);

    for (int i = 0; i < REMOVE_LENGTH; i++)
    {
        string value = REMOVE[i];
        cout << "Removing " << setw(9) << value << ":";
        list->remove(value);
        dump(list);
    }

    delete list;
}

int main()
{
    test_integer<int>();
    test_string<string>();

    cout << endl << "Done!" << endl;
}
