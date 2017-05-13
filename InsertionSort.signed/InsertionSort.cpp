/* Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "InsertionSort.h"

/**
 * Default constructor.
 */
InsertionSort::InsertionSort() : VectorSorter() {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string InsertionSort::name() const { return "Insertion sort"; }

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */

/*This algorithm is cited from-
 *  https://www.tutorialspoint.com/data_structures_algorithms/insertion_sort_program_in_c.htm
 * */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/

	   int valueToInsert;
	   int holePosition;
	   int i;
	   // loop through all numbers
	   for(i = 1;i <data.size(); i++)
	   {
		   compare_count++;
	      // select a value to be inserted.
	      valueToInsert =data.at(i);
	      // select the hole position where number is to be inserted
	      holePosition = i;
	      // check if previous no. is larger than value to be inserted
	      while (holePosition > 0 && data.at(holePosition-1)> valueToInsert)
	      {
	    	  swap(holePosition, (holePosition-1));
	    	//  data.at(holePosition) = data.at(holePosition-1);
	         holePosition--;
	      }
	      if(holePosition != i)
	      {
	         // insert the number at hole position
	    	  data.at(holePosition) = valueToInsert;
	      }
	   }
}
