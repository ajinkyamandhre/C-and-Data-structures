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

/*This code is cited from
 * https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_program_in_c.htm
 * */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{

    /***** Complete this member function. *****/
	int inner, outer;
	   int valueToInsert;
	   int interval = 1;
	   int elements = size;
	   int i = 0;

	   while (interval <= elements / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{

		for (outer = interval; outer < elements; outer++)
		{
			valueToInsert = data[outer];
			inner = outer;

			while (inner > interval - 1 && data[inner - interval] >= valueToInsert)
			{
				compare_count++;
				data[inner] = data[inner - interval];
				move_count=move_count+1;
				inner -= interval;
			}
			data[inner] = valueToInsert;
			move_count += 1;
		}
		interval = (interval - 1) / 3;
		i++;
	}
}
