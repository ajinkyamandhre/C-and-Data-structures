/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSortOptimal.h"
#include<iostream>

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */

int flag=0;

QuickSortOptimal::QuickSortOptimal() {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string QuickSortOptimal::name() const { return "Quicksort optimal"; }

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */


int QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this member function. *****/
	//cout<<"left "<<left<<"right "<<right<<endl;
	int center = (left + right) / 2;
	//cout<<"center "<<center<<endl;
	int arr[3]={data[left],data[center],data[right]};

    for (int i = 0; i<3; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (arr[i] > arr[j])
            {
               int  a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
  //  cout<<"data"<<data[1]<<endl;
    /*if(data[1]==data[left])
    {
    	flag = left;
    }
    else   if(data[1]==data[center])
    {
    	flag = center;
    }
    else   if(data[1]==data[right])
    {
    	flag = right;
    }*/

	return arr[1];

	//data[left] data[right] data[center];)
	/*if(data[left]>data[center] && data[left]>data[right])
	{
		//left is large
		large=data[left];
	}
	if(data[center]>data[left] && data[center]>data[right])
	{
		//center is large
		large=data[center];
	}
	if(data[right]>data[center] && data[right]>data[left])
	{
		//right is large
		large=data[right];
	}

	if( (data[left] <data[center]) && (data[left]< data[right]) )
	{
		small=data[left];
	}
	else if(data[center]< data[right])
	{
			small=data[center];
	}
	else
		small=data[right];
	*/
}
