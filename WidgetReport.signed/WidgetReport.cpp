#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class WidgetReport
{
    /***** Complete this class. *****/

public:
    WidgetReport(ifstream& in);  // constructor
    void print();
    void Extractdata();

private:
    ifstream& input;  // reference to the input stream
    string line,data,name,header;
    int linenumber,state,plant,dept,empid,cnt;
    int state1,plant1,dept1,flag,flag1;
    int dept_total,plant_total,state_total,grand_total;
};

const char* INPUT_FILE_NAME = "widgets.txt";

int main()
{
    ifstream input;

    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Generate and print the Widget Report.
    /***** Complete this main. *****/

    WidgetReport a(input);

    a.Extractdata();

    input.close();
    return 0;
}

/*****Put member function definitions after the main*****/

WidgetReport::WidgetReport(ifstream& in):input(in),linenumber(0),state(0),plant(0),dept(0),empid(0),cnt(0)
{
	name="";
	data="";
	state1=0;
	plant1=0;
	dept1=0;
	flag=0;
	dept_total=0;
	plant_total=0;
	state_total=0;
	grand_total=0;
	flag1=0;
}

void WidgetReport::print()
{
	if(linenumber>1 && flag1==0)
	{
		if(flag==0)
		{
			state1=state;
			plant1=plant;
			dept1=dept;
			flag=1;
		}
		if(state1!=state)
		{
			cout<<"\n\t\t\t  "<<setw(2)<<dept_total<<" TOTAL FOR DEPT  "<<dept1<<setw(2)<<" *"<<endl;
			cout<<"\t\t\t  "<<setw(2)<<plant_total<<" TOTAL FOR PLANT "<<plant1<<setw(2)<<" **"<<endl;
			cout<<"\t\t\t  "<<setw(2)<<state_total<<" TOTAL FOR state "<<state1<<setw(2)<<" ***"<<endl<<endl;

			state_total=0;
			plant_total=0;
			dept_total=0;
			state1=state;
			plant1=plant;
			dept1=dept;
		}
		else if(plant1!=plant)
		{
			cout<<"\n\t\t\t  "<<setw(2)<<dept_total<<" TOTAL FOR DEPT  "<<dept1<<setw(2)<<" *"<<endl;
			cout<<"\t\t\t  "<<setw(2)<<plant_total<<" TOTAL FOR PLANT "<<plant1<<setw(2)<<" **"<<endl<<endl;
			plant_total=0;
			dept_total=0;
			plant1=plant;
			dept1=dept;
		}
		else if(dept1!=dept)
		{
			cout<<"\n\t\t\t  "<<dept_total<<" TOTAL FOR DEPT  "<<dept1<<setw(2)<<" *"<<endl<<endl;
			dept_total=0;
			dept1=dept;
		}

		state_total=state_total+cnt;
		plant_total=plant_total+cnt;
		dept_total=dept_total+cnt;
		grand_total=grand_total+cnt;

		cout<<setw(5)<<state;
		cout<<setw(6)<<plant;
		cout<<setw(5)<<dept;
		cout<<setw(6)<<empid;
		cout<<setw(6)<<cnt;
		cout<<" "<<setw(2)<<name<<endl;

	}//if ends
	else if(linenumber==1)
	{
		string first_header,name_header,count_header;
		int count_pos;
		int pos=0;

		pos=header.find("NAME");

		first_header=header.substr(0,pos-1);

		count_pos=header.find("COUNT");

		name_header=header.substr(pos,(count_pos-pos));

		count_header=header.substr(count_pos,(header.length()-count_pos));

		cout<<first_header<<" "<<count_header<<" "<<name_header<<endl<<endl;
	}
	else
	{
		cout<<"\n\t\t\t  "<<setw(2)<<dept_total<<" TOTAL FOR DEPT  "<<dept1<<setw(2)<<" *"<<endl;
		cout<<"\t\t\t  "<<setw(2)<<plant_total<<" TOTAL FOR PLANT "<<plant1<<setw(2)<<" **"<<endl;
		cout<<"\t\t\t  "<<setw(2)<<state_total<<" TOTAL FOR STATE "<<state1<<setw(2)<<" ***"<<endl<<endl;
		cout<<"\t\t\t  "<<setw(2)<<grand_total<<" GRAND TOTAL\t****";
	}
}

void WidgetReport::Extractdata()
{
	int i=0,count=0,pos=0;
	string temp;

	while(getline(input,line))
	{
		linenumber=linenumber+1;

		for(i=0;i<line.size();i++)
		{
			if(linenumber==1)
			{
				header=line;
			}

			else if(linenumber>1 && line.at(i)==' ')
			{
				count=count+1;

				if(count==1)
				{
					temp=line.substr(pos,(i-pos));
					state=stoi(temp);
					pos=i;
				}
				if(count==2)
				{
					temp=line.substr(pos+1,(i-pos));
					plant=stoi(temp);
					pos=i;
				}
				if(count==3)
				{
					temp=line.substr(pos+1,(i-pos));
					dept=stoi(temp);
					pos=i;
				}
				if(count==4)
				{
					temp=line.substr(pos+1,(i-pos));
					empid=stoi(temp);
					pos=i;
				}
				if(count==6 )
				{
					name=line.substr(pos+1,(i-pos));
					pos=i;

					temp=line.substr(pos+1,(line.length()-pos));
					cnt=stoi(temp);
					count=0;
					pos=0;
				}
			}//if loop of space check
		}//for loop of string scanning
/*
 * function call to print the data line by line
 * */

		print();

	}//while ends here
/*
 *print the last line and grand total
 */
	flag1=1;
	print();

}
