/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/


#include "RomanNumeral.h"
#include <string>

using namespace std;

/*
 * Default constructor.
 * */

RomanNumeral::RomanNumeral() : roman_array(""), decimal_value(0)
{
}
/*
 * Constructor to intialize string to RomanNumeral
 * */
RomanNumeral::RomanNumeral(string roman):roman_array(roman)
{
	toDecimal();
}

/*
 * Constructor to intialize decimal value
 * */
RomanNumeral::RomanNumeral(int value):decimal_value(value)
{
	toRoman();
}

/*
 * Set functions
 * Private members are assigned the values
 * */
void RomanNumeral::Set_RomanNumeral(string roman) {roman_array=roman;}

void RomanNumeral::Set_RomanNumeral(int value) {decimal_value=value;}


/*
 * Get Functions
 * GetString() returns Roman numeral
 * GetInteger() returns decimal value
 * */

string RomanNumeral::GetString() {return roman_array;}
int RomanNumeral::GetInteger() {return decimal_value;}

/*
 * function to convert Roman to decimal
 * */

void RomanNumeral::toDecimal()
{
	string Roman=roman_array;
	int num=0,number=0,flag=0;

	for(int i=0;Roman[i]!='\0';i++)
	{
		if(Roman[i]=='M')
		{
			num=1000;
		}
		if(Roman[i]=='D')
		{
			num=500;
		}
		if(Roman[i]=='C')
		{
			num=100;

			if(Roman[i+1]=='M')
			{
				num=900;
				flag=1;
			}
			if(Roman[i+1]=='D')
			{
				num=400;
				flag=1;
			}
		}
		if(Roman[i]=='L')
		{
			num=50;
		}
		if(Roman[i]=='X')
		{
			num=10;

			if(Roman[i+1]=='C')
			{
				num=90;
				flag=1;
			}
			if(Roman[i+1]=='L')
			{
				num=40;
				flag=1;
			}
		}
		if(Roman[i]=='V')
		{
			num=5;
		}
		if(Roman[i]=='I')
		{
			num=1;
			if(Roman[i+1]=='X')
			{
				num=9;
				flag=1;
			}
			if(Roman[i+1]=='V')
			{
				num=4;
				flag=1;
			}
		}
		number=number+num;
		decimal_value=number;
		if(flag==1)
		{
			flag=0;
			i++;
		}
	}//for i
}//function ends

/*
 * function to convert Decimal to Roman Numeral
 * */

void RomanNumeral::toRoman()
{
	int num=decimal_value;
	int x=0;
	string Numeral="";

	while(num>=1)
	{
		if(num>=1000)
		{
			do{
				x=num/1000;
				for(int i=1;i<=x;i++)
				{
					Numeral=Numeral+'M';
				}
				num=num%1000;
			}while(num>=1000);
		}

		else if(num>=900)
		{
			do{
				x=num/900;
				for(int i=1;i<=x;i++)
				{
					Numeral=Numeral+"CM";
				}
				num=num%900;
			}while(num>=900);
		}

		else if(num>=500)
		{
			do{
				x=num/500;
				for(int i=1;i<=x;i++)
				{
					Numeral=Numeral+'D';
				}
				num=num%500;
			}while(num>=500);
		}

		else if(num>=400)
		{
			do{
				x=num/400;
				for(int i=1;i<=x;i++)
				{
					Numeral=Numeral+"CD";
				}
				num=num%400;
			}while(num>=400);
		}

		else if(num>=100)
		{
			do{
				x=num/100;
				for(int i=1;i<=x;i++)
				{
					Numeral=Numeral+'C';
				}
				num=num%100;
			}while(num>=100);
		}

		else if(num>=90)
		{
			do{
				x=num/90;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+"XC";
				}
				num=num%90;
			}while(num>=90);
		}

		else if(num>=50)
		{
			do{
				x=num/50;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+'L';
				}
				num=num%50;
			}while(num>=50);
		}

		else if(num>=40)
		{
			do{
				x=num/40;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+"XL";
				}
				num=num%40;
			}while(num>=40);
		}


		else if(num>=10)
		{
			do{
				x=num/10;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+'X';
				}
				num=num%10;
			}while(num>=10);
		}

		else if(num>=9)
		{
			do{
				x=num/9;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+"IX";
				}
				num=num%9;
			}while(num>=9);
		}

		else if(num>=5)
		{
			do{
				x=num/5;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+'V';
				}
				num=num%5;
			}while(num>=5);
		}

		else if(num>=4)
		{
			do{
				x=num/4;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+"IV";
				}
				num=num%4;
			}while(num>=4);
		}

		else if(num>=1)
		{
			do{
				x=num/1;
				for(int i=0;i<x;i++)
				{
					Numeral=Numeral+'I';
				}
				num=num%1;
			}while(num>=1);
		}
	}//while
	roman_array=Numeral;
}

/*
 *override operators +
 *@param RomanNumeral& a is an object passed for addition
 *@param RomanNumeral& b is an object passed for addition
 *@param RomanNumeral the return value of the addition
 * */

RomanNumeral operator +(const RomanNumeral& a,const RomanNumeral& b)
{
	RomanNumeral a2;
	int x=b.decimal_value;
	int y=a.decimal_value;

	a2.decimal_value=y+x;
	a2.toRoman();
	return a2;
}

/*
 *override operators -
 *@param RomanNumeral& a is an object passed for subtraction
 *@param RomanNumeral& b is an object passed for getting subtracted
 *@param RomanNumeral the return value of the subtraction
 * */
RomanNumeral operator -(const RomanNumeral& a,const RomanNumeral& b)
{
	RomanNumeral a2;
	int x=b.decimal_value;
	int y=a.decimal_value;

	a2.decimal_value=y-x;
	a2.toRoman();
	return a2;
}

/*
 *override operators *
 *@param RomanNumeral& a is an object passed
 *@param RomanNumeral& b is an object passed
 *@param RomanNumeral the return value of the Multiplication
 * */
RomanNumeral operator *(const RomanNumeral& a,const RomanNumeral& b)
{
	RomanNumeral a2;
	int x=b.decimal_value;
	int y=a.decimal_value;

	a2.decimal_value=y*x;
	a2.toRoman();
	return a2;
}

/*
 *override operators /
 *@param RomanNumeral& a is an object passed as divisor
 *@param RomanNumeral& b is an object passed as dividend
 *@param RomanNumeral the return value of the Division
 * */
RomanNumeral operator /(const RomanNumeral& a,const RomanNumeral& b)
{
	RomanNumeral a2;
	int x=b.decimal_value;
	int y=a.decimal_value;

	a2.decimal_value=y/x;
	a2.toRoman();
	return a2;
}

/*
 *override operators ==
 *@param RomanNumeral& a is an object passed for comparison
 *@param RomanNumeral& b is an object passed for comparison
 *@param bool returns the boolean equivalent for the result
 * */
bool operator ==(const RomanNumeral& a,const RomanNumeral& b)
{
	int x=b.decimal_value;
	int y=a.decimal_value;
	if(y==x)
		return true;
	else
		return false;
}

/*
 *override operators !=
 *@param RomanNumeral& a is an object passed for comparison
 *@param RomanNumeral& b is an object passed for comparison
 *@param bool returns the boolean equivalent for the result
 */
bool operator !=(const RomanNumeral& a,const RomanNumeral& b)
{
	int x=b.decimal_value;
	int y=a.decimal_value;

	if(y!=x)
		return true;
	else
		return false;
}
/*
 *override operators << i.e the output operator
 *@param "ostream& out" refers to output stream passed by reference
 *@param RomanNumeral& b is an object passed which is to be displayed
 *@param ostream& returns the stream back as refernce
 */

ostream& operator <<(ostream& out,const RomanNumeral& b)
{

	out<<"["<<b.decimal_value<<":"<<b.roman_array<<"]";

	return out;
}

/*
 *override operators >> i.e the input operator
 *@param "istream& in" refers to input stream passed by reference
 *@param RomanNumeral& b is an object passed for the file to be read into
 *@param istream& returns the stream back as refernce
 */

istream& operator >>(istream& in,RomanNumeral& b)
{
	char input[20];
	string array;

	in>>input;

	b.roman_array=input;
	b.toDecimal();
	return in;
}

