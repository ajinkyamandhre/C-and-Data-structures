/*
 * LinearProbeHT.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: ajinkya
 */

#include <iostream>
#include "LinearProbeHT.h"
using namespace std;

LinearProbeHT::LinearProbeHT() : OpenAddressHT() {}
LinearProbeHT::LinearProbeHT(int size) : OpenAddressHT(size) {}

LinearProbeHT::~LinearProbeHT() {}

/**
 * Compute the index of the next hash table slot away from
 * the current slot to check. For linear probing, the next
 * slot to check is one away from the current one.
 * @param index the index of the current slot.
 * @return the index of the next slot.
 */
int LinearProbeHT::next_index(int index)
{
	//cout<<"Inside linear probe"<<endl;
    /***** Complete this member function. *****/
	index++;
	index=index%size;
//	cout<<"done with linear probe"<<endl;
	return index;
}



