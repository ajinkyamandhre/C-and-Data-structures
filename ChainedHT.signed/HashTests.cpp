#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include "LinearProbeHT.h"
#include "QuadraticProbeHT.h"
#include "ChainedHT.h"

using namespace std;

void process_input(ifstream& in, int& line_count, int& word_count,
                   map<string, int>& stl_map,
                   LinearProbeHT& linear_table, int& linear_probe_count,
                   QuadraticProbeHT& quadratic_table, int& quadratic_probe_count,
                   ChainedHT& chained_table, int& chained_probe_count);

void enter_map(map<string, int>& stl_map, const string& word);
void dump_map(map<string, int>& stl_map);

void print_stats(int word_count, int line_count, map<string, int>& stl_map,
                 LinearProbeHT& linear_table, int linear_probe_count,
                 QuadraticProbeHT& quadratic_table, int quadratic_probe_count,
                 ChainedHT& chained_table, int chained_probe_count);

void test_word(const string& word, map<string, int>& stl_map,
               LinearProbeHT& linear_table, QuadraticProbeHT& quadratic_table,
               ChainedHT& chained_table);
void print_entry(HashEntry *entry_ptr, int probe_count);

void dump_data(map<string, int>& stl_map,
               LinearProbeHT& linear_table,
               QuadraticProbeHT& quadratic_table,
               ChainedHT& chained_table);

const string INPUT_FILE_NAME = "USConstitution.txt";

const string WORDS_TO_TEST[] = {"amendment", "article", "ballot", "citizens",
                                "congress", "constitution", "democracy",
                                "electors", "government", "law", "legislature",
                                "people", "president", "representatives",
                                "right", "trust", "united", "states", "vice",
                                "vote"};

/**
 * Main.
 * @param argc the number of command-line arguments.
 * @param argv the array of pointers to the argument strings.
 */
int main(int argc, char *argv[])
{
    int line_count = 0;
    int word_count = 0;

    int linear_probe_count = 0;
    int quadratic_probe_count = 0;
    int chained_probe_count = 0;

    bool dump_flag = false;
    if (argc > 1) dump_flag = strcmp(argv[1], "--dump") == 0;

    ifstream in;
    in.open(INPUT_FILE_NAME);
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Map and hash tables.
    map<string, int> stl_map;
    LinearProbeHT    linear_table(1150);
    QuadraticProbeHT quadratic_table(2281);
    ChainedHT        chained_table(500);
 //  cout<<"a"<<endl;
    process_input(in, line_count, word_count, stl_map,
                  linear_table, linear_probe_count,
                  quadratic_table, quadratic_probe_count,
                  chained_table, chained_probe_count);
    in.close();
   //cout<<"b"<<endl;
    print_stats(word_count, line_count, stl_map,
                linear_table, linear_probe_count,
                quadratic_table, quadratic_probe_count,
                chained_table, chained_probe_count);
  // cout<<"c"<<endl;
    for (string word : WORDS_TO_TEST)
    {
        test_word(word, stl_map, linear_table, quadratic_table,
                 chained_table);
    }
 //   cout<<"d"<<endl;
    if (dump_flag)
    {
        dump_data(stl_map, linear_table, quadratic_table, chained_table);
    }

    cout << endl << "Done!" << endl;
    return 0;
}

/**
 * Read the input file and enter its words into the map and hash tables.
 * Each word is first converted to all lower case letters.
 * @param in the input stream.
 * @param stl_map an STL map data structure.
 * @param linear_table the hash table using linear probing.
 * @param quadratic_table the hash table using quadratic probing.
 * @param chained_table the hash table using collision chains.
 */
void process_input(ifstream& in, int& line_count, int& word_count,
                   map<string, int>& stl_map,
                   LinearProbeHT& linear_table, int& linear_probe_count,
                   QuadraticProbeHT& quadratic_table, int& quadratic_probe_count,
                   ChainedHT& chained_table, int& chained_probe_count)
{
	/***** Complete this function. *****/
	// cout<<"Pro Input"<<endl;

	string line = "";

	  while(getline(in,line))
		    {
		  	    string word = "";
		    	for(int i=0;i<line.size();i++)
		    	{
		    		if(isalpha(line.at(i)))
		    		{
		    			word+=tolower(line.at(i));
		    		}
		    		else
		    		{
		    			if(!word.empty())
		    			{
		    				//cout<<word<<endl;
		    				// Enter the word into the STL map and the hash tables.
		    					enter_map(stl_map, word);
		    					linear_table.enter(word, linear_probe_count);
		    					quadratic_table.enter(word, quadratic_probe_count);
		    					chained_table.enter(word, chained_probe_count);
		    					// cout<<" call done to EM,LT"<<endl;
		    				word = "";
		    				word_count++;
		    			}
		    		}
		    	}
		    	line_count++;
		    }

		//cout<<word<<endl;

	//	 cout<<"conv done to SL"<<endl;

}

/**
 * Enter a word into the STL map.
 * If the word is already in the map, update its count.
 * @param stl_map the map.
 * @param word the word.
 */
void enter_map(map<string, int>& stl_map, const string& word)
{
    /***** Complete this function. *****/
	// cout<<"inside enter map"<<endl;
	   map<string, int>::iterator pos=stl_map.find(word);

	       if(pos!=stl_map.end())
	       {
	          stl_map.insert(pos,pair<string, int>(pos->first,pos->second++));
	       }
	       else
	       {
	         stl_map.insert(pair<string, int>(word,1));
	       }
	   //    cout<<"done with enter map"<<endl;
}

/**
 * Dump the contents of the STL map.
 * @param stl_map the map.
 */
void dump_map(map<string, int>& stl_map)
{
    /***** Complete this function. *****/
	map<string,int>::const_iterator it;

	for (it = stl_map.begin(); it!= stl_map.end(); it++)
	{
	    cout<<"\t" << it->second<<"-"<< it->first<<endl;
	}

}

/**
 * Print statistics.
 * @param word_count the total count of words in the input file.
 * @param line_count the number of lines in the input file.
 * @param stl_map the map.
 * @param linear_table the hash table using linear probing.
 * @param linear_probe_count the total number of probes in the linear table.
 * @param quadratic_table the hash table using quadratic probing.
 * @param quadratic_probe_count the total number of probes in the quadratic table.
 * @param chained_table the hash table using collision chains.
 * @param chained_probe_count the total number of probes in the chained table.
 */
void print_stats(int word_count, int line_count, map<string, int>& stl_map,
                 LinearProbeHT& linear_table, int linear_probe_count,
                 QuadraticProbeHT& quadratic_table, int quadratic_probe_count,
                 ChainedHT& chained_table, int chained_probe_count)
{
    /***** Complete this function. *****/

    double dbl_word_count = word_count;
    double linear_probe_avg =( linear_probe_count/dbl_word_count);
    double quadratic_probe_avg =(quadratic_probe_count/dbl_word_count);

    double chained_length_avg  = chained_table.avg_chain_length();
    double chained_probe_avg = (chained_probe_count/dbl_word_count);

    cout << "Statistics for file " << INPUT_FILE_NAME << ":" << endl;
    cout << endl;

    cout << "                   Lines: " << line_count-1 << endl;
    cout << "             Total words: " << word_count << endl;
    cout << "          Distinct words: " <<stl_map.size()<<endl;
    cout << endl;
    cout << "       Linear table size: " << linear_table.get_size() << endl;
    cout << "     Total linear probes: " << linear_probe_count << endl;
    cout << "   Average linear probes: " << linear_probe_avg << endl;
    cout << endl;
    cout << "    Quadratic table size: " << quadratic_table.get_size() << endl;
    cout << "  Total quadratic probes: " << quadratic_probe_count << endl;
    cout << "Average quadratic probes: " << quadratic_probe_avg << endl;
    cout << endl;
    cout << "      Chained table size: " << chained_table.get_size() << endl;
    cout << "    Average chain length: " << chained_length_avg << endl;
    cout << "    Total chained probes: " << chained_probe_count << endl;
    cout << "  Average chained probes: " << chained_probe_avg << endl;

}

/**
 * Test a word by searching the STL map and the hash tables.
 * For the STL map and the hash tables, print each found word
 * in the form count-word. For the hash tables, also print the
 * count of probes to find the word.
 * @param word the word to search for.
 * @param stl_map an STL map data structure.
 * @param linear_table the hash table using linear probing.
 * @param quadratic_table the hash table using quadratic probing.
 * @param chained_table the hash table using collision chains.
 */
void test_word(const string& word, map<string, int>& stl_map,
               LinearProbeHT& linear_table, QuadraticProbeHT& quadratic_table,
               ChainedHT& chained_table)
{
	int linear_probe_count=0;
	int quadratic_probe_count=0;
	int chained_probe_count=0;
	int chained_count=0;
	int quadratic_count=0;
	int linear_count=0;
	int index=0;
	HashEntry *linearnode = nullptr;
	HashEntry *quadnode = nullptr;
	HashEntry *node = nullptr;

	index=linear_table.search(word,linear_probe_count);
	linearnode=linear_table.get_entry(index);
	if(linearnode!=nullptr)
	linear_count=linearnode->count;

	index=quadratic_table.search(word,quadratic_probe_count);
	quadnode=quadratic_table.get_entry(index);
	if(quadnode!=nullptr)
	quadratic_count=quadnode->count;

	node= chained_table.search(word,chained_probe_count);
	chained_count=node->count;

	if(stl_map[word])
	{
    cout<< setw(5)<<endl << "  Tests with the word '" << word << "':" << endl << endl;
    cout<<setw(28)<<"STL map: "<<stl_map[word]<<"-"<<word<<endl;//37
    cout<<setw(28)<<"Linear probe hashtable: "<<linear_count<<"-"<<word<<endl;//31
    cout<<setw(28)<<"Quadratic probe hashtable: "<<quadratic_count<<"-"<<word<<endl;//29
    cout<<setw(28)<<"Chained hashtable: "<<chained_count<<"-"<<word<<endl;

    /*cout<<setw(31)<<"Linear probe hashtable: "<<print_entry(linearnode,linear_count);
    cout<<setw(29)<<"Quadratic probe hashtable: "<<print_entry(quadnode,probe_count);
*/

	}
	else
	{
		  cout << setw(5)<<endl << "  Tests with the word '" << word << "':" << endl << endl;
		    cout<<setw(28)<<"STL map: "<<"*** Not found. ***"<<endl;
		    cout<<setw(28)<<"Linear probe hashtable: "<<"*** Not found. ***"<<endl;
		    cout<<setw(28)<<"Quadratic probe hashtable: "<<"*** Not found. ***"<<endl;
		    cout<<setw(28)<<"Chained hashtable: "<<"*** Not found. ***"<<endl;
	}

    /***** Complete this function. *****/
}

/**
 * Print a hash table entry if it exists.
 * Print each entry in the form count-word (n probes)
 * @param entry_ptr the pointer to the entry.
 * @param probe_count the probe count to find the entry.
 */
void print_entry(HashEntry *entry_ptr, int probe_count)
{
    /***** Complete this function. *****/
	cout<<entry_ptr->count<<"-"<<entry_ptr->word<<"("<<probe_count<<")"<<endl;
}

/**
 * Dump the data in the STL map and in the hash tables.
 * Print each entry in the form count-word
 * For the hash tables, also print the table slot index,
 * and skip empty table slots.
 * @param linear_table the hash table using linear probing.
 * @param quadratic_table the hash table using quadratic probing.
 * @param chained_table the hash table using collision chains.
 */
void dump_data(map<string, int>& stl_map,
               LinearProbeHT& linear_table,
               QuadraticProbeHT& quadratic_table,
               ChainedHT& chained_table)
{
    cout << endl << "Map dump:" << endl << endl;
    dump_map(stl_map);

    cout << endl << "Linear probe hash table dump:" << endl << endl;
    linear_table.dump();

    cout << endl << "Quadratic probe hash table dump:" << endl << endl;
    quadratic_table.dump();

    cout << endl << "Chained hash table dump:" << endl << endl;
    chained_table.dump();
}
