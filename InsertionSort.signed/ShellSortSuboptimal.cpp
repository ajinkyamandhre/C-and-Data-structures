/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortSuboptimal.h"

/**
 * Default constructor.
 */
ShellSortSuboptimal::ShellSortSuboptimal() {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortSuboptimal::name() const { return "Shellsort suboptimal"; }

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */

/*
 * This algorithm is taken from
 * http://www.cplusplus.com/forum/general/123961/
 * */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/

	int gap, i, j, temp;
	int n=size;

	    for (gap = n/2; gap > 0; gap /= 2)

	        for (i = gap; i < n; i++)

	            for (j=i-gap; j>=0 && data[j]>data[j+gap]; j-=gap)
	            {
	            	 compare_count++;
	            	 swap(j,j+gap);
	            }
}

