/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "GettysburgAddress.txt";

int main()
{

	string line;
	int line_count = 0;
	int character_count = 0;
	int word_count = 0;
	int lower_count = 0;
	int upper_count = 0;
	int space_count = 0;
	int punctuation_count = 0;
	int i;
	ifstream input;

	input.open(INPUT_FILE_NAME);
	if (input.fail())
  	{
   		cout << "Failed to open " << INPUT_FILE_NAME << endl;
   		return -1;
 	 }

	while(getline(input,line))
	{
		for(i=0;line[i]!='\0';i++)
		{
			if( line[i]<=90 && line[i]>=65)
			{
				upper_count=upper_count+1;
			}
			if(line[i]<='z' && line[i]>='a')
			{
				lower_count=lower_count+1;
			}
			if(line[i]==32)
			{
				space_count=space_count+1;
			}
			if(line[i]=='-'|| line[i]=='.' || line[i]==',')
			{
				punctuation_count=punctuation_count+1;
			}

			if((line[i]<=90 && line[i]>=65)|| (line[i]<='z' && line[i]>='a'))
			{
				 if(line[i+1]=='-'|| line[i+1]=='.'||line[i+1]==',' || line[i+1]=='\0' || line[i+1]==' ')
				{
					word_count=word_count+1;
				}
			}

		}//for

		character_count=character_count+i;
		line_count=line_count+1;

	}//while

cout << "Statistics for file " << INPUT_FILE_NAME << ":" << endl;
cout << endl;

cout << "Lines: " << line_count << endl;
cout << "Characters: " << character_count << endl;
cout << "Words: " << word_count << endl;
cout << "Lower-case letters: " << lower_count << endl;
cout << "Upper-case letters: " << upper_count << endl;
cout << "Spaces: " << space_count << endl;
cout << "Punctuation marks: " << punctuation_count << endl;
}//main ends
