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
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
     int gap,i;
     int n = data.size();
    // Start with a larger gap, then reduce the gap to 1
    // we take gap sequence in order of |N/2|, |N/4|, |N/8|...1
    for (gap = n/2; gap > 0; gap /= 2)
    {
        // we performe gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (i = gap; i < n; i += 1) {
            // store a[i] in temp and make a hole at position i
            int temp = data.at(i);
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && data.at(j - gap) > temp; j -= gap)
            {
                compare_count++;
                swap(j,j-gap);
            }


        }
    }
}
