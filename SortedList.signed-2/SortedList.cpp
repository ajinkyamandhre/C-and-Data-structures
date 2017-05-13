/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/


#include <iostream>
#include <iterator>
#include <algorithm>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

/***** Complete this file. *****/

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}

void SortedList::prepend(int value)
{
	list<int>::iterator it = data.begin();
	data.insert(it,value);
}

void SortedList::append(int value)
{
	list<int>::iterator it = data.begin();
	data.push_back(value);
}

bool SortedList::find(int value) const
{
	list<int>::const_iterator it = data.begin();

	it= std::find(data.begin(),data.end(),value);
	if(it!=data.end())
	return true;
	else
	return false;

}

int SortedList::get_value(int i) const
{
	list<int>::const_iterator itf= data.begin();
	list<int>::const_reverse_iterator itr= data.rbegin();
	int size=data.size();
	int half=(size/2);
	int count=0;
	if(i<half)
	{
		for(count=0;count<i;count++)
		{
			itf++;
		}
		return *itf;
	}
	else
	{
		for(count=(size-1);count>i;count--)
		{
			itr++;
		}
		return *itr;
	}

}

void SortedList::clear()
{
	list<int>::iterator it= data.begin();

	for(it=data.begin();it!=data.end();)
	{
		it=data.erase(it);
	}
}
