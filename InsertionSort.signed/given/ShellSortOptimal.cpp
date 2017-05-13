/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortOptimal.h"

/**
 * Default constructor.
 */
ShellSortOptimal::ShellSortOptimal() {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortOptimal::name() const { return "Shellsort optimal"; }

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
}
