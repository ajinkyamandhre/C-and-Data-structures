/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSortSuboptimal.h"
#include<iostream>
/**
 * Default constructor.
 */

//int flag=0;
QuickSortSuboptimal::QuickSortSuboptimal() {}

/**
 * Destructor.
 */
QuickSortSuboptimal::~QuickSortSuboptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string QuickSortSuboptimal::name() const { return "Quicksort suboptimal"; }

/**
 * Choose a bad pivot, always the leftmost element of the subrange.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
int QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this member function. *****/
	//flag=left;
	return data[left];
}
