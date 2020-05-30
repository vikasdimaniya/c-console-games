/*Create a program that will:
1.	Display a list of numbers to the screen (random numbers).
2.	Pick one of those numbers at random and start a guessing game
3.	The user must guess the selected number. You must validate that the number the user guessed was valid, and among the choices listed.
4.	Tell the user whether or not the number they guessed is larger or smaller than the number you're looking for.
5.	After a certain number of guesses, the user loses and gets prompted to try again.
Concepts used: Functions, variables, loops, random functions, returns, boolean, vectors / lists / arrays, template class member functions,
			   stringstream
*/
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
main()
{
	int a[20],b,c,d,i;
	while(b!=2)						//new program
	{
		cout<<"RULES:\n\tThe user must guess the correct number from the given numbers.\n\tThe players have only ten chances";
		cout<<"\n\n\t\t\t\t-->>PRESS ANY KEY TO START<<--.";
		getch();
		system("cls");
		b=0;
		srand(time(0));				//all numbers should be defferent
		for(i=0;i<20;i++)
		{
			a[i]=rand()%100;
			cout<<a[i]<<"	";
		}
		c=a[rand()%20];
		cout<<endl<<"GUESS THE NUMBER :"<<endl;
		for(i=0;i<10;i++)
		{
			cin>>d;
			if(c==d)
			{
				cout<<"\t\t\t\t---->>CORRECT<<----\nPress any key....."<<endl;
				getch();
				system("cls");
				break;
			}
			else
			{
				cout<<"\tWRONG\t\t\t\t";
				if(c>d)
				{
					cout<<"guess SMALLER"<<endl;
				}
				if(c<d)
				{
					cout<<"guess LARGER"<<endl;
				}
				
			}
		}
		cout<<"1: NEW GAME"<<endl<<"2: EXIT"<<endl;
		cin>>b;
		system("cls");
	}
}
