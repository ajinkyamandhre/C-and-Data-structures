
//SAMPLE

/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>
#include "DataRandom.h"
#include "DataSorted.h"
#include "DataReverseSorted.h"
#include "DataAllZeros.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSortSuboptimal.h"
#include "ShellSortOptimal.h"
#include "QuickSortSuboptimal.h"
#include "QuickSortOptimal.h"
#include "MergeSort.h"
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

bool do_sort(Sorter *sorter, int n, DataGenerator *generator);
void output_sort_stats(bool sorted, const Sorter *sorter);
string commafy(long n);

/**
 * Main.
 */
int main()
{
    bool sorted;

    // Number of data items to test.
    int N[] = {100, 1000, /* 10000, 100000 */};

    // Sorting algorithms.
    Sorter *sorters[] =
    {
        new SelectionSort(),
        new InsertionSort(),
        new ShellSortSuboptimal(),
        new ShellSortOptimal(),
        new QuickSortSuboptimal(),
        new QuickSortOptimal(),
        new MergeSort(),
    };

    // Data generators.
    DataGenerator *generators[] =
    {
        new DataRandom(),
        new DataSorted(),
        new DataReverseSorted(),
        new DataAllZeros(),
    };

    steady_clock::time_point start_time = steady_clock::now();

    // Loop for each data generator.
    for (DataGenerator *generator : generators)
    {
        string generator_name = generator->name();

        cout << endl;
        for (int i = 0; i < generator_name.length(); i++) cout << "=";
        cout << endl << generator_name << endl;
        for (int i = 0; i < generator_name.length(); i++) cout << "=";
        cout << endl;

        // Loop for each data size.
        for (int n : N)
        {
            cout << endl << "N = " << commafy(n) << endl << endl;
            cout << setw(25) << "ALGORITHM" << setw(15) << "MOVES"
                 << setw(15) << "COMPARES"  << setw(15) << "MILLISECONDS"
                 << endl;

            // Loop for each sorting algorithm.
            for (Sorter *sorter : sorters)
            {
                cout << setw(25) << sorter->name();
                sorted = do_sort(sorter, n, generator);
                output_sort_stats(sorted, sorter);

                // Clean up after a sort.
                sorter->clear_data();
            }
        }
    }

    // Pick up the garbage.
    for (Sorter *sorter : sorters) delete sorter;
    for (DataGenerator *generator : generators) delete generator;

    steady_clock::time_point end_time = steady_clock::now();
    long elapsed_time = duration_cast<seconds>(end_time - start_time).count();
    cout << endl << "Done! " << elapsed_time << " seconds." << endl;
    cin.get();
    return 0;
}

/**
 * Perform a sort with a given algorithm and data generator.
 * @param sorter the sorting algorithm.
 * @param n the number of data elements to sort.
 * @param generator the data generator.
 */
bool do_sort(Sorter *sorter, int n, DataGenerator *generator)
{
    // Generate data for the algoritnm to sort.
    sorter->generate_data(generator, n);

    try
    {
        return sorter->sort();  // do a sort
    }
    catch (string& message)
    {
        cout << endl << message << endl;
        return false;
    }
}

/**
 * Output a sort algorithm's move and compare counts and elapsed time.
 * @param sorted true if correctly sorted, else false.
 * @param sorter the sorting algorithm.
 */
void output_sort_stats(bool sorted, const Sorter *sorter)
{
    if (sorted)
    {
        cout << setw(15) << commafy(sorter->get_move_count());
        cout << setw(15) << commafy(sorter->get_compare_count());
        cout << setw(15) << commafy(sorter->get_elapsed_ms());
        cout << endl;
    }
    else
    {
        cout << "***** Sort error! *****" << endl;
    }
}

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(long n)
{
        std::ostringstream stm ;
        stm << n ;
        string str = stm.str() ;




    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
