/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/


/*
 * Person.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: ajinkya
 */

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

/***** Write the constructors. *****/

Person::Person()
{
}
Person::Person(int level, string name):level(level),name(name)
{
}

Person::Person(int level, string name, string spouse):level(level),name(name),spouse_name(spouse)
{

}
/**
 * Destructor
 */
Person::~Person()
{
	/***** Complete this destructor: Recursively delete all the nodes. *****/
	if(!children.empty())
	{
		for(int i=0;i<children.size();i++)
		{
			delete children.at(i);
		}
	}
}

/**
 * Have a child.
 * @param child pointer to the new child.
 */
void Person::have_child(Person *child)
{
	/***** Complete this member function. *****/
	children.push_back(child);
	child->parent=this;
}
/**
 * Print a person.
 */
void Person::print() const
{
	int i=0;
	/***** Complete this member function: Recursively print the nodes. *****/

	/*
	 * Special case consideration not to print for level 0
	 * */
	if(!spouse_name.empty())
	{
		if(level>=1)
		{
			print_bar();
			cout<<endl;
			for(int i=0;i<((level-1)*4);i++)
			{
				cout<<" ";
			}
			cout<<"+---"<<name<<" ("<<spouse_name<<")"<<endl;
		}
		else
		{
			print_bar();
			cout<<name<<" ("<<spouse_name<<")"<<endl;
		}
	}
	else
	{
		print_bar();
		cout<<endl;
		for(int i=0;i<((level-1)*4);i++)
		{
			cout<<" ";
		}
		cout<<"+---"<<name<<endl;
	}
/*
 * Recursion
 * */
	while(i<children.size())
	{
		children.at(i)->print();
		i++;
	}
}

void Person::print_bar() const
{

	if(level>=2)
	{
		if(this->parent!=(this->parent->parent->children.at(this->parent->parent->children.size()-1)))
		this->parent->print_bar();
	}
	if(level>=1)
		{
			for(int i=0;i<((level-1)*4);i++)
			{
				cout<<" ";
			}
			cout<<"|";
		}
}




