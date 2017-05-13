/*
 * ChainedHT.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: ajinkya
 */

#include <iostream>
#include <iomanip>
#include "ChainedHT.h"
using namespace std;

int flag=0;
/**
 * Default constructor.
 */
ChainedHT::ChainedHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
ChainedHT::ChainedHT(int size) : HashTable(size)
{
    /***** Complete this member function. *****/
	//cout<<"Inside chained contructor"<<endl;
	HashNode *node = nullptr;
		for(int i=0;i<size;i++)
		{
			 table.push_back(node);
		}
		//cout<<"done chained contructor"<<endl;
}

/**
 * Destructor. Delete all the entries in the collision chains.
 */
ChainedHT::~ChainedHT()
{
    /***** Complete this member function. *****/
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return a pointer to the entry if found, else return nullptr.
 */
HashEntry *ChainedHT::search(const string& word, int& probe_count)
{
	//cout<<"inside chained search"<<endl;
	int index = hash(word);
	//cout<<"got the key"<<endl;
	/***** Complete this member function. *****/

	HashNode  *travel= new HashNode();
	travel=table.at(index);
	flag=0;
	if(travel== nullptr)
	{
		//cout<<"1st if chained search"<<endl;
			return nullptr;
	}
	else
	{
		//cout<<"1st else chained search"<<endl;
		while(travel != nullptr)
		{
			probe_count++;
			flag++;
			//cout<<"probe increase"<<endl;
			//cout<<probe_count<<endl;

			if((travel->entry->word!=word)&&(travel->next==nullptr))
			{
				//cout<<"return empty node chained search"<<endl;
				return travel->entry;
			}
			else if(travel->entry->word==word)
			{
				//cout<<"matched travel entry chained search"<<endl;
				return travel->entry;
			}
			else if((travel->entry->word!=word)&&(travel->next!=nullptr))
			{
				//cout<<"traverse chained search"<<endl;
				travel=travel->next;
			}

		}

	}

}

/**
 * If an entry isn't already in the table, enter it with a
 * frequency count of 1. If the entry already exists,
 * update it by incrementing its frequency count by 1.
 * Count the number of probes from the initial search.
 * @param key the key of the entry to enter or update.
 * @return a pointer to the newly entered or updated entry.
 */
HashEntry *ChainedHT::enter(const string& word, int& probe_count)
{
	//cout<<"inside chained enter"<<endl;
    HashEntry *entry_ptr = search(word, probe_count);

    /***** Complete this member function. *****/
    if(entry_ptr==nullptr )
    {
    	//cout<<"creating new node for nullptr chained enter"<<endl;
    	//enter the word
    	int index = hash(word);
    	HashNode *newnode = new HashNode;
    	table.at(index)=newnode;
    	table.at(index)->entry=new HashEntry(word);
    /*	cout<<"done  linking  chained node"<<endl;
    	HashNode *nextnode = new HashNode();
    	newnode->next=nextnode;*/

    	//cout<<"done  if chained enter"<<endl;
    }
    else if(entry_ptr->word==word)
    {
    	entry_ptr->count++;
    }
    else if(entry_ptr->word!=word)//entry_ptr->word!=word
    {
    	//cout<<"create new node at end"<<endl;
    	int index = hash(word);
    	HashNode  *travel= new HashNode;
    	travel=table.at(index);
    	//cout<<"new new"<<endl;
    	//cout<<"probecount: "<<probe_count<<endl;
    	for(int i=1;i<flag;i++)
    	{
    		//cout<<"i: "<<i<<endl;
    		travel=travel->next;
    	}
    	//cout<<"done traversing"<<endl;
    	HashNode *newnode = new HashNode;
    	travel->next=newnode;
    	newnode->entry=new HashEntry(word);
    	flag=0;
    }
    	//if word matches increase the count

    return entry_ptr;
}

/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void ChainedHT::dump() const
{
    /***** Complete this member function. *****/
	for(int i=0; i<table.size();i++)
		{

			if(table.at(i)==nullptr)
			{
				continue;
			}
			else
			{
				HashNode  *travel=table.at(i);
				cout<<"\t"<<i<<":"<<endl;
				while(travel!=nullptr)
				{
					cout<<"\t\t"<<travel->entry->count<<"-"<<travel->entry->word<<endl;
					travel=travel->next;
				}
			}
		}

}

/**
 * Compute the average chain length.
 */
double ChainedHT::avg_chain_length() const
{
    /***** Complete this member function. *****/
	double chain_avg=0;
	int newct=0;
	for(int i=0; i<table.size();i++)
		{

				if(table.at(i)==nullptr)
				{
					continue;
				}
				else
				{
					HashNode  *travel=table.at(i);

					while(travel!=nullptr)
					{
						travel=travel->next;
						newct++;
					}
				}
			}
	chain_avg=(newct/table.size());

	return chain_avg;
}




