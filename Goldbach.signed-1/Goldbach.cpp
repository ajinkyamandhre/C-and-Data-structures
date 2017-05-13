/***************************************************************************/
/*	The code is written by Ajinkya Mandhre				   */
/*	For Educational purpose: for understanding the topic and cnocepts  */
/*	This is is part of assignments that where given by Prof.Ron Mak    */
/***************************************************************************/

#include <iomanip>
#include <iostream>
#include <vector>


using namespace std;


void prime_numbers(int prime[]);
void Display_prime(int prime[]);
void even_numbers(int even[]);
void Goldbach_conjecture(int prime[],int even[]);

int main()
{
	int primeno[100];
	int evennum[51];
	int i=0;

	for(i=0;i<100;i++)
	{
		primeno[i]=0;
		evennum[i]=0;
	}

	prime_numbers(primeno);

	Display_prime(primeno);

	even_numbers(evennum);

	Goldbach_conjecture(primeno,evennum);

}

void even_numbers(int even[])
{
	int i=0,j=0;

	for(i=4;i<=100;i++)
		{
			if(i%2==0)
			{
				even[j]=i;
				j++;
			}
		}
}

void prime_numbers(int prime[])
{
	int i=0,j=0;

	prime[j]=0;

	for(i=2,j=1;i<=100;i++,j++)
	{
		if(i==2 || i==3 || i==5 || i==7)
		{
			prime[j]=i;
		}
		if((i%2!=0)&&(i%3!=0)&&(i%5)&&(i%7!=0))
		{
			prime[j]=i;
		}
	}
}

void Display_prime(int prime[])
{
	int i=0,j=0,k=0;

	cout<<"Primes:"<<endl<<endl;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(prime[k]==0)
			{
				cout<<setw(3)<<".";
				k++;
			}
			else
			{
				cout<<setw(3)<<prime[k];
				k++;
			}
		}
		cout<<endl;
	}
}


void Goldbach_conjecture(int prime[],int even[])
{
	int i=0,j=0,k=0;

	cout<<endl<<"Test of Goldbach's Conjecture:"<<endl<<endl;

	for(i=0;i<49;i++)
	{
		cout<<even[i]<<":";

		for(j=1;prime[j]<even[i];j++)
		{
			if(even[i]==prime[j]+prime[j])
			{
				cout<<"\t"<<prime[j]<<"\t"<<prime[j]<<endl;
			}

			for(k=j+1;prime[k]<even[i];k++)
			{
				if(even[i]==prime[j]+prime[k])
				{
					cout<<"\t"<<prime[j]<<"\t"<<prime[k]<<endl;
				}
			}
		}
		cout<<endl;
	}
}
