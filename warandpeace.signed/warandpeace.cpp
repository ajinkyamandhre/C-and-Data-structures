/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string MAKAR  = "Makar Alexeevich";
const string JOSEPH = "Joseph Bazdeev";
const string BORIS  = "Boris Drubetskoy";

const char* INPUT_FILE_NAME = "WarAndPeace.txt";

void Printheader();

void Split_name_check(string line,vector<int>& First_name_position,int line_number,vector<int>& indicator);

void Display(vector<int>& Full_name_postion,int line_number,vector<int>& last_name_postion,vector<int>& indicator);

int main()
{
	string line;
	vector<int> First_name_position;
	vector<int> Last_name_position;
	vector<int> Full_name_position;
	vector<int> indicator;

	int line_number= 0;
	int flag=0;
	int matched_line=0;
	int matched_position=0;

	int Makar_Alexeevich_position=0;
	int Joseph_Bazdeev_position=0;
	int Boris_Drubetskoy_position=0;

	int Makar_position=0;
	int Joseph_position=0;
	int Boris_position=0;

	int Alexeevich_position=0;
	int Bazdeev_position=0;
	int Drubetskoy_position=0;

	First_name_position.push_back(Makar_position);
	First_name_position.push_back(Joseph_position);
	First_name_position.push_back(Boris_position);

	Last_name_position.push_back(Alexeevich_position);
	Last_name_position.push_back(Bazdeev_position);
	Last_name_position.push_back(Drubetskoy_position);

	Full_name_position.push_back(Makar_Alexeevich_position);
	Full_name_position.push_back(Joseph_Bazdeev_position);
	Full_name_position.push_back(Boris_Drubetskoy_position);

	indicator.push_back(matched_line);
	indicator.push_back(matched_position);
	indicator.push_back(flag);

	ifstream input;

	Printheader();// used to print the header of table
	input.open(INPUT_FILE_NAME);

	if (input.fail())
  	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
   		return -1;
 	}

	while(getline(input,line))
	{
	 	line_number++;

	 	Full_name_position[0]=line.find(MAKAR);
	 	Full_name_position[1]=line.find(JOSEPH);
	 	Full_name_position[2]=line.find(BORIS);

		First_name_position[0]=line.find("Makar");
		First_name_position[1]=line.find("Joseph");
		First_name_position[2]=line.find("Boris");

		Last_name_position[0]=line.find("Alexeevich");
		Last_name_position[1]=line.find("Bazdeev");
		Last_name_position[2]=line.find("Drubetskoy");

		Split_name_check(line,First_name_position,line_number,indicator);

		Display(Full_name_position,line_number,Last_name_position,indicator);

	}//while ends
}//main ends

void Split_name_check(string line,vector<int>& First_name_position,int line_number,vector<int>& indicator)
{
/*---------------------conditions to find out name split on two consecutive line--------------------------------*/
	if(line[First_name_position[1]+6]=='\0')
	{
		indicator[2]=1;
		indicator[0]=line_number;
		indicator[1]=First_name_position[1]+1;
	}

	else if(line[First_name_position[0]+5]=='\0')
	{
		indicator[2]=2;
		indicator[0]=line_number;
		indicator[1]=First_name_position[0]+1;
	}

	else if(line[First_name_position[2]+5]=='\0')
	{
		indicator[2]=3;
		indicator[0]=line_number;
		indicator[1]=First_name_position[2]+1;
	}

}


void Display(vector<int>& Full_name_postion,int line_number,vector<int>& last_name_postion,vector<int>& indicator)
{
	/*------------------condition to check display of names on same line---------------------------*/
	if(Full_name_postion[0]>=0)
	{
		cout<<setw(6)<<line_number<<"\t     "<<setw(3)<<(Full_name_postion[0]+1)<<"   "<<MAKAR<<endl;
	}

	if(Full_name_postion[1]>=0)
	{
		cout<<setw(6)<<line_number<<"\t     "<<setw(3)<<(Full_name_postion[1]+1)<<"   "<<JOSEPH<<endl;
	}

	if(Full_name_postion[2]!=-1)
	{
		cout<<setw(6)<<line_number<<"\t     "<<setw(3)<<(Full_name_postion[2]+1)<<"   "<<BORIS<<endl;
	}
/*-----------------------------------condition check to display of split names---------------------------------------------------*/
	if((indicator[2]==1) && (indicator[0]==(line_number-1) && (last_name_postion[1]==0)))
	{
		cout<<setw(6)<<indicator[0]<<"\t     "<<setw(3)<<(indicator[1])<<"   "<<JOSEPH<<endl;
		indicator[2]=0;
	}

	if((indicator[2]==2) && (indicator[0]==(line_number-1) && (last_name_postion[0]==0)))
	{
		cout<<setw(6)<<indicator[0]<<"\t     "<<setw(3)<<(indicator[1])<<"   "<<MAKAR<<endl;
		indicator[2]=0;
	}

	if((indicator[2]==3) && (indicator[0]==(line_number-1) && (last_name_postion[2]==0)))
	{
		cout<<setw(6)<<indicator[0]<<"\t     "<<setw(3)<<(indicator[1])<<"   "<<BORIS<<endl;
		indicator[2]=0;
	}
}

void Printheader()
{

	cout<<"  LINE"<<"\t"<<"POSITION  "<<" NAME"<<endl;

}
