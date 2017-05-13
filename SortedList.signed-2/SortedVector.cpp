#include <iostream>
/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/


#include <iterator>
#include <algorithm>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

/***** Complete this file. *****/

bool SortedVector::check()
{
    if (data.size() == 0) return true;

    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}

void SortedVector::prepend(int value)
{
	vector<int>::iterator it = data.begin();
	data.insert(it,value);
}

void SortedVector::append(int value)
{
	vector<int>::iterator it = data.begin();
	data.push_back(value);
}

bool SortedVector::find(int value) const
{
	vector<int>::const_iterator it = data.begin();

	it=std::find(data.begin(),data.end(),value);
		if(it!=data.end())
		return true;
		else
		return false;

}


int SortedVector::get_value(int i) const
{
	vector<int>::const_iterator itf= data.begin();
	return itf[i];
}

void SortedVector::clear()
{
	vector<int>::iterator it;

	for(it=data.begin();it!=data.end();)
	{
		it=data.erase(it);
	}
}
