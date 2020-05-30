#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
int exitLoop =0;
main()
{
	string a[9];
	int v,i,r,m;
	a[0]=" ";
	a[1]=" ";
	a[2]=" ";
	a[3]=" ";
	a[4]=" ";
	a[5]=" ";
	a[6]=" ";
	a[7]=" ";
	a[8]=" ";
	
	cout<<"Press a number from:"<<endl;
	cout<<"1,2,3\n4,5,6\n7,8,9"<<endl;
	
	cout<<"   |   |   "<<endl;
	cout<<"  ";
	cout<<" |  ";
	cout<<" |  ";
	cout<<" "<<endl;
	cout<<"___|___|___"<<endl;
	cout<<"   |   |   "<<endl;
	cout<<"   ";
	cout<<"|  ";
	cout<<" |  ";
	cout<<" "<<endl;
	cout<<"___|___|___"<<endl;
	cout<<"   |   |   "<<endl;
	cout<<"   ";
	cout<<"|  ";
	cout<<" |  ";
	cout<<"  "<<endl;
	cout<<"   |   |   "<<endl;
	
	for(m=1;m<=9;m++)
	{
		if(m%2==0){
			while(1){
				cout<<"player 2: ";
				cin>>v;
				if(a[v-1]==" "){
					a[v-1]='o';
					break;
				}else{
					cout<<"Already occupied space.";
				}
			}
		}
		else
		{
			while(1){
				cout<<"player 1: ";
				cin>>v;
				if(a[v-1]==" "){
					a[v-1]='x';
					break;
				}else{
					cout<<"Already occupied space.";
				}
			}
		}
		system("cls");
		cout<<"Press a number from:"<<endl;
		cout<<"1,2,3\n4,5,6\n7,8,9"<<endl;
		cout<<"   |   |   "<<endl;
		cout<<" "<<a[0];
		cout<<" | "<<a[1];
		cout<<" | "<<a[2];
		cout<<" "<<endl;
		cout<<"___|___|___"<<endl;
		cout<<"   |   |   "<<endl;
		cout<<" "<<a[3];
		cout<<" | "<<a[4];
		cout<<" | "<<a[5];
		cout<<" "<<endl;
		cout<<"___|___|___"<<endl;
		cout<<"   |   |   "<<endl;
		cout<<" "<<a[6]<<" ";
		cout<<"| "<<a[7];
		cout<<" | "<<a[8]<<"  "<<endl;
		cout<<"   |   |   "<<endl;
		if((a[0]==a[1] && a[1]==a[2] && a[0]!=" ") || (a[3]==a[4] && a[4]==a[5] && a[3]!=" ")||(a[6]==a[7] && a[7]==a[8] && a[6]!=" ")||(a[0]==a[3] && a[3]==a[6] && a[0]!=" ")||(a[1]==a[4] && a[4]==a[7] && a[1]!=" ")||(a[2]==a[5] && a[5]==a[8] && a[2]!=" ")||(a[0]==a[4] && a[4]==a[8] && a[0]!=" ")||(a[2]==a[4] && a[4]==a[6] && a[2]!=" "))
		{
			if((a[0]==a[1] && a[1]==a[2]) || (a[3]==a[4] && a[4]==a[5])||(a[6]==a[7] && a[7]==a[8])||(a[0]==a[3] && a[3]==a[6])||(a[1]==a[4] && a[4]==a[7])||(a[2]==a[5] && a[5]==a[8])||(a[0]==a[4] && a[4]==a[8])||(a[2]==a[4] && a[4]==a[6]))
			{
				if(m%2==0)
				{
					cout<<"player 2 wins";
				}
				else if(m%2!=0)
				{
					cout<<"player 1 wins";
				}
				break;
			}
		}
	}
	getch();
}
