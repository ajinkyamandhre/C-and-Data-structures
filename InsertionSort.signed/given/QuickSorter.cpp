/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSorter.h"

/**
 * Default constructor.
 */
QuickSorter::QuickSorter() : VectorSorter() {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{

      int i = left, j = right;
      int tmp;
      int pivot = choose_pivot_strategy(left, right);

      /* partition */
      while (i <= j) {
            while (data.at(i) < data.at(pivot))
            {
                compare_count++;
                i++;
            }

            while (data.at(j) > data.at(pivot))
            {
                compare_count++;
                j--;
            }

              compare_count++;
            if (i <= j) {
                    swap(i,j);
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            QuickSorter::quicksort( left, j);
      if (i < right)
            QuickSorter::quicksort(i, right);

}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
int QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const int pivot)
{
    /***** Complete this member function. *****/
}
