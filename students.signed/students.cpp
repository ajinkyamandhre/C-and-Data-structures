#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

typedef int* IntArrayPtr;
typedef string* StrngPtr;

const char* INPUT_FILE_NAME="students.txt";

void Display_header();
void Create_Dynamic_Array(StrngPtr &name_students,IntArrayPtr *&score_2D_array,ifstream& input,int score_array[]);
void Display(StrngPtr &name_students,IntArrayPtr *&score_2D_array,int score_array[]);

int main()
{
    ifstream input;
    string line;


    int i=0,First_digit=0,Second_digit=0;
    int nos_of_students=0;

    input.open(INPUT_FILE_NAME);

    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

/*----------------extract the number of students------------------------*/
    getline(input,line);

    for(i=0;line[i]!='\0';i++)
    {
    	if(line[i]>='0' && line[i]<='9')
    	{
		    if(line[i+1]<='9' && line[i+1]>='0')
		    {
		    	First_digit=line[i]-48;// subtract 48 to convert digits in 'char' to 'int'
		    	Second_digit=line[i+1]-48;
		    }
    	}
    }

    nos_of_students=(First_digit*10)+Second_digit;// get the number of students

    StrngPtr name_students= new string[nos_of_students];
    IntArrayPtr *score_2D_array= new IntArrayPtr[nos_of_students];
    int* score_array= new int[nos_of_students];

    Display_header();

    Create_Dynamic_Array(name_students,score_2D_array,input,score_array);

    Display(name_students,score_2D_array,score_array);

/*------------------free the dynamic arrays--------------------------------------*/
 	delete [] name_students;

 	for(int j=0;j<nos_of_students;j++)
 	{
 		delete [] score_2D_array[j];
 	}
 	delete [] score_array;
 	delete [] score_2D_array;


 return 0;
}

void Display_header()
{
	cout<<"STUDENT SCORES for C++"<<endl;
}

void Create_Dynamic_Array(StrngPtr &name_students,IntArrayPtr *&score_2D_array,ifstream& input,int score_array[])
{
	string line;
	string extract_name;
	string extract_marks;

	 int i=0,j=0,p=0,k=0,First_digit=0,Second_digit=0,Third_digit=0,marks=0;

	 int space_count=0,num_pos=0,nos_of_score=0;

	 int flag_ones=0,flag=0,flag_3=0;

	 while(getline(input,line))
	 {
		 for(i=0;line[i]!='\0';i++)
		 {
			 if(line[i]==' ')
			 {
				 space_count=space_count+1;
			 }

			 if(space_count==2 && flag==0)
		  	 {
				 extract_name=line.substr(0,i);
		  		 flag=2;

		  		 if(flag==2 && line[i+1]<='9' && line[i+1]>='0')
		  		 {
		  			 nos_of_score=line[i+1]-48;//extraction of scores
		  		 }
		  	 }

		  	if(space_count==3 && flag_3==0)
		  	{
		  		flag_3=1;
		  		num_pos=i;//start location to extract marks
		  	}
		 }//for ends

	extract_marks=line.substr(num_pos,i-1);//function call to extract marks in string

	    if(flag==2)
	    {
	    	name_students[j]= extract_name;//store name in dynamic array

	    	if(nos_of_score!=0)
	      	{
	    		score_2D_array[j]=new int[nos_of_score];//2D array column allocation

	    		score_array[j]=nos_of_score;
	      	}
	    	else
	    	{
	    		score_2D_array[j]=new int[0];
	    		score_array[j]=0;
	    	}
	    }

	    for(k=0,p=0;extract_marks[k]!='\0';k++)
	    {
	    	if(extract_marks[k]<='9' && extract_marks[k]>='0')
	    	{
	    		First_digit=extract_marks[k]-48;
	         	marks=First_digit;

	        	score_2D_array[j][p]=marks; //dynamic array storing

	        	if(extract_marks[k-1]==' ')
	         	{
	        		flag_ones=1;
	         	}
	        	/*----------------if marks are in 2 digits(75,82) go inside loop---------*/

	         		if(extract_marks[k+1]<='9' && extract_marks[k+1]>='0')
	         		{
	         			First_digit=extract_marks[k]-48;
	  					Second_digit=extract_marks[k+1]-48;
	  					marks=(First_digit*10)+Second_digit;

					    score_2D_array[j][p]=marks;

			   /*----------------if marks are in 3 digits(100) go inside loop---------*/

					    if(extract_marks[k+2]<='9' && extract_marks[k+2]>='0')
					    {
					    	First_digit=extract_marks[k]-48;
					    	Second_digit=extract_marks[k+1]-48;
					    	Third_digit=extract_marks[k+2]-48;
					    	marks=(First_digit*100)+(Second_digit*10)+(Third_digit);

					    	score_2D_array[j][p]=marks;
					    }//if 3 digit marks
	         		}//if 2 digit marks

	         		if(flag_ones==1)
	         		{
	         			p++;//increment column index of marks array
	         		}

	 		}//if 1 digit

	         	flag_ones=0;

		}//for loop of marks extraction ends

	        j++; // increament the row index of 2D array pointer to point to marks of next name
	      	space_count=0;
	      	flag=0;
	      	flag_3=0;

	      }//getline
}

void Display(StrngPtr &name_students,IntArrayPtr *&score_2D_array,int score_array[])
{
	int i=0,j=0,p=0;

	for(j=0;j<10;j++)
	{
		cout<<endl;
		cout<<"  "<<name_students[j]<<endl;
		cout<<"   ";
		for(p=0;p<score_array[j];p++)
		{
			if(score_array[j]>0)
			{
				cout<<"  "<<score_2D_array[j][p];
			}
		}
		if(score_array[j]==0)
		cout<<"  (none)";
		cout<<endl;
	}
}
