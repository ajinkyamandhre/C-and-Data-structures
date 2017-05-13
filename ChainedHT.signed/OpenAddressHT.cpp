/*
 * OpenAddressHT.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: ajinkya
 */

#include <iostream>
#include <iomanip>
#include "OpenAddressHT.h"
#include "HashEntry.h"

using namespace std;

/**
 * Default constructor
 */
OpenAddressHT::OpenAddressHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
OpenAddressHT::OpenAddressHT(int size) : HashTable(size)
{

//	cout<<"Inside open address contructor"<<endl;

    /***** Complete this member function. *****/
	int i=0;
	HashEntry *node = nullptr;
	for(i=0;i<size;i++)
	{
		 table.push_back(node);
	}
}

/**
 * Destructor. Delete all the entries in the table.
 */
OpenAddressHT::~OpenAddressHT()
{
    /***** Complete this member function. *****/
}

/**
 * Return an entry at a given index of the hash table.
 * @param index the index.
 * @return the entry.
 */
HashEntry *OpenAddressHT::get_entry(const int index) const
{
	//cout<<"Inside open address get entry"<<endl;
    /***** Complete this member function. *****/
	return table.at(index);
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return the hash table index of the entry if found, else of an empty slot.
 */
int OpenAddressHT::search(const string& key, int& probe_count)
{
    /***** Complete this member function. *****/
	//cout<<"Inside open address search"<<endl;
    // Initial probe index.
//	cout<<key<<endl;
    int index = hash(key);
//cout<<key<<":index:"<<index<<endl;
    for(int i=0; i<table.size();i++)
      {
          if(table.at(index)==nullptr)
          {
               return index;
          }

          else if(table.at(index)->word == key)
          {
       			return index;
          }

          else
          {
        	  //cout<<"call to next_index open address"<<endl;
        	  index = next_index(index);// probe the next slot
        	  probe_count++;
          }

      }
   // cout<<"open address search over"<<endl;
          return index;  // of the found entry or of an empty slot
}

/**
 * If an entry isn't already in the table, enter it with a
 * frequency count of 1. If the entry already exists,
 * update it by incrementing its frequency count by 1.
 * Count the number of probes from the initial search.
 * @param key the key of the entry to enter or update.
 * @return the index of the newly entered or updated entry.
 */
int OpenAddressHT::enter(const string& key, int& probe_count)
{
	//cout<<"inside enter open address"<<endl;
    // Search for the entry key.

    int index = search(key, probe_count);

    /***** Complete this member function. *****/
       if(table.at(index) == nullptr)
       {
    	 //  cout<<"create new node in open address"<<endl;
           HashEntry* newEntry=new HashEntry(key);

           table.at(index)=newEntry;
       }
       else if(table.at(index)->word == key)
       {
    	//   cout<<"increase count in open address"<<endl;
           table.at(index)->count = table.at(index)->count +1;
       }
  /***** Complete this member function. *****/
    return index;
}

/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void OpenAddressHT::dump() const
{
    /***** Complete this member function. *****/
	for(int i=0; i<table.size();i++)
	{
		if(table.at(i)==nullptr)
		{
			continue;
		}

		cout<<setw(6)<<"\t"<<i<<":\t "<<table.at(i)->count<<"-"<<table.at(i)->word<<endl;
	}

}



