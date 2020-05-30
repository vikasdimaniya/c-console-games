#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<unistd.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score,tailx[100],taily[100],ntail,a,b=1;
char c;
enum edirection
{
	stop,LEFT,RIGHT,up,down
};
edirection dir;


void setup()
{
	gameover=false;
	dir=stop;
	x=width/2;
	y=height/2;
	srand(time(0));
	fruitx=rand()%width;
	fruity=rand()%height;
	score=0;
}
void draw()
{
	system("cls");
	for(int i=0;i<width+2;i++)
		cout<<"#";
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			
			if(j==0)
				cout<<"#";
			if(i==y && j==x)
				cout<<c;
			else if(i==fruity && j==fruitx)
				cout<<"*";
			else 
			{
				int p=0;
				for(int k=0;k<ntail;k++)
				{
					if(tailx[k]==j && taily[k]==i)
					{
						cout<<c;
						p=1;
					}	
				}
				if(p==0)
					cout<<" ";
			}
			if(j==width-1)
				cout<<"#";
		}
		cout<<endl;
	}
	for(int i=0;i<width+2;i++)
		cout<<"#";
	cout<<endl;
	cout<<"Score: "<<score<<endl;
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'w':
				dir=up;
				break;
			case 's':
				dir=down;
				break;
			case 'x':
				gameover=true;
				break;
		}
	}
}
void logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(dir)
	{
			case LEFT:
				x--;
				break;
			case RIGHT:
				x++;
				break;
			case up:
				y--;
				break;
			case down:
				y++;
				break;
	}
	
	if(b==1)
	{
		if (x >= width) x = 0; else if (x < 0) x = width - 1;
    	if (y >= height) y = 0; else if (y < 0) y = height - 1;
	}
	if(b==2)
	{
		if(x>width|| x<0||y>height||y<0)
		gameover=true;
	}
	if(x==fruitx && y==fruity)
	{
		srand(time(0));
		score+=10;
		fruitx=rand()%width;
		fruity=rand()%height;
		ntail++;
	}
	for(int i=1;i<ntail-1;i++)
	{
		if(x==tailx[i] && y==taily[i]){gameover=true;break;}
	}
}
void pause()
{
	for(int i=0;i<80000000;i++);
}
void menu();
main()
{
	setup();
	menu();
}
void game()
{
		while(!gameover)
		{
			c='a';
			draw();
			input();
			logic();
			pause();
			//sleep() to slow game
		}
		sleep(2);
		system("cls");
		cout << " #####     #    #     # ####### ####### #     # ####### ######\n" ;
    	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
    	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
    	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
    	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
    	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
    	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
}
void menu()
{
	cout<<"\t\t\tSNAKE"<<endl;
	sleep(1);
	menu:
	cout<<"1. START NEW GAME\n2. OPTIONS\n3. EXIT"<<endl;
	cin>>a;
	if(a==1)
	{
		game();
	}
	else if(a==2)
	{
		cout<<"SELECT STAGE\n\t1. CLASSIC\n\t2. WALLS"<<endl;
		cin>>b;
		a=0;
		system("cls");
		goto menu;
	}
}
