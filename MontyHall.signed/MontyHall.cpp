/**************************************************************************/
/*	The code is written by Ajinkya Mandhre				                  */
/*	For Educational purpose: for understanding the topic and cnocepts     */
/*	This is is part of assignments that where given by Prof.Ron Mak       */
/**************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

void printHeader();
void simulate(int sequence, int& win1, int& win2);
Door hideCar();
void makeFirstChoice(int& first_choice);
Door MontyOpenDoor(Door first_Choice, Door car_Behind_Door);
void remainingdoor(int& remaining_door,int& first_choice,int& monty_first_open);
void makefinalchoice(int sequence,int& first_choice,int& remaining_door,int& car_Behind_Door,int& monty_first_open,int& win1,int& win2);


int main()
{
    int win1 = 0, win2 = 0;

    srand(time(NULL));  // seed the random number generator
    printHeader();// used to print the header of table

    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++)
    	{
    		simulate(i, win1, win2);
    	}

    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
}



void simulate(int sequence,int& win1,int& win2)
{
	int car_Behind_Door=0,first_choice=0,monty_first_open=0,remaining_door=0;


	car_Behind_Door=hideCar();/*function to hide the car behind a door---*/
	
	
	makeFirstChoice(first_choice);/*function to select a door from user randomly------*/
		

	monty_first_open=MontyOpenDoor(first_choice,car_Behind_Door);/*--this function to open a random door having goat--*/
	
	
	remainingdoor(remaining_door,first_choice,monty_first_open);/*-function to get the number of leftout door-----*/
	
	
	makefinalchoice(sequence,first_choice,remaining_door,car_Behind_Door,monty_first_open,win1,win2);
	/*-function to make choice of switch or stay--*/

}

Door hideCar()
{

	int car_Behind_Door=(rand()%3)+1;

	return car_Behind_Door;
}

void makeFirstChoice(int& first_choice)
{

	 first_choice=(rand()%3)+1;

}

Door MontyOpenDoor(Door first_choice, Door car_Behind_Door)
{
	int monty_first_open=0;

	do
	{
		monty_first_open=(rand()%3)+1;

	}while(monty_first_open==car_Behind_Door || monty_first_open==first_choice);

	return monty_first_open;
}

void remainingdoor(int& remaining_door,int& first_choice,int& monty_first_open)
{
	do
	{
		remaining_door=(rand()%3)+1;

	}while(remaining_door==first_choice || remaining_door==monty_first_open);


}

void makefinalchoice(int sequence,int& first_choice,int& remaining_door,int& car_Behind_Door,int& monty_first_open,int& win1,int& win2)
{
	int selection=0,flag1=0;

	selection=(rand()%2)+1;

	if(selection==1)
	{
		if(first_choice==car_Behind_Door)
		{

			win1++;
			flag1=1;
		}
		else
		{
			win2++;
			flag1=0;
		}

	}
	else if(selection==2)
	{

		if(remaining_door==car_Behind_Door)
		{

			win2++;
			flag1=0;
		}
		else
		{
			win1++;
			flag1=1;
		}
	}

	if(flag1)
	{
		cout<<setw(4)<<sequence<<"  "<<"\t"<<setw(4)<<car_Behind_Door<<"\t"<<setw(4)<<first_choice<<"\t"<<setw(4)<<monty_first_open<<"\t"<<setw(4)<<remaining_door<<"\t    "<<setw(4)<<"yes"<<endl;
	}
	else
	{
		cout<<setw(4)<<sequence<<"  "<<"\t"<<setw(4)<<car_Behind_Door<<"\t"<<setw(4)<<first_choice<<"\t"<<setw(4)<<monty_first_open<<"\t"<<setw(4)<<remaining_door<<"\t\t\t"<<setw(4)<<"yes"<<endl;
	}

}


void printHeader()
{

	cout<<"  #    "<<" Car    "<<" First    "<<"Opened    "<<"Second    "<<"  Win     "<<"   Win"<<endl;
	cout<<"       "<<"Here    "<<"Choice    "<<"  Door    "<<"Choice    "<<"First     "<<"Second"<<endl<<endl;

}
/***** Complete this program. ****/
