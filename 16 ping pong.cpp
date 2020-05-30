/*ping pong
	RULES:
		map 25*25
		height-y,width=x
		ball reflect backs of touching bottom and top
		side two players 
		if ball touches bat it will reflects just like on the bottom and top
		otherwise game over for the player of side on which ball touches 
		x1,x2,x is for up down*/
#include<iostream>
#include<conio.h>
#include<unistd.h>
using namespace std;
int difficulty=3;
int x,y,x1[5],y1,x2[5],y2,height=20,width=100,ifverify=0,balldirection=1,playerlose=0,balldirection_y=0;
bool gameover;
enum directions
{
	stop,up1,down1,up2,down2,gameo
};
directions dir;
void setup()
{
	for(int l=0;l<5;l++)
	{
		x1[0]=0;
		x2[0]=0;
		x=height/2;
		y=width/2;
		for(int i=0;i<4;i++)
		{
			x1[i+1]=x1[i]+1;
			x2[i+1]=x2[i]+1;
		}
			y1=0;
			y2=width-1;
	}
}
void draw()
{
	system("cls");
	cout<<"Use  p1:  W,S  and                                                              num p2: 8,5 to play."<<endl;
	cout<<"PLAYER 1:                                                                                  PLAYER 2:"<<endl;
	for(int i=0;i<width;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			for(int l=0;l<5;l++)
			{
				if(i==x1[l] && j==y1)
				{
					cout<<"|";
					ifverify=1;
					break;
				}
			}
			for(int l=0;l<5;l++)
			{
				if(i==x2[l] && j==y2)
				{
					cout<<"|";
					ifverify=1;
					break;
				}
			}
			if(i==x && j==y)
			{
				cout<<"*";
				ifverify=1;
			}
			if(ifverify==0)
				cout<<" ";
			ifverify=0;
		}
		cout<<endl;
	}
	for(int i=0;i<width;i++)
	{
		cout<<"#";
	}
}
void input()
{
	if(_kbhit())
	{
		switch(getch())
		{
			case 'w':
				dir=up1;
				break;
			case 's':
				dir=down1;
				break;
			case '8':
				dir=up2;
				break;
			case '5':
				dir=down2;
				break;
			case 'x':
				gameover=true;
				break;
		}
	}
}
void logic()
{
	if(x>height || x<0){
		balldirection_y*=-1;
	}
	
	if(y>width){
		gameover=true;
		playerlose=2;
	}
	if(y<0){
		gameover=true;
		playerlose=1;
	}
	switch(dir)
	{
		case stop:
			break;
		case up1:
			x1[0]-=difficulty;
			break;
		case down1:
			x1[0]+=difficulty;
			break;
		case up2:
			x2[0]-=difficulty;
			break;
		case down2:
			x2[0]+=difficulty;
			break;
		case gameo:gameover=true;
	}
	if(x1[0]>height-6)
	{
		dir=stop;
		x1[0]=height-6;
	}
	if(x2[0]>height-6)
	{
		dir=stop;
		x2[0]=height-6;
	}
	if(x1[0]==0)
	{
		dir=stop;
		x1[0]=1;
	}
	if(x2[0]==0)
	{
		dir=stop;
		x2[0]=1;
	}
	
	for(int i=0;i<4;i++)
	{
		x1[i+1]=x1[i]+1;
		x2[i+1]=x2[i]+1;
	}
	if(y==y1){
		if((x==x1[0])||(x==x1[1])||(x==x1[2])||(x==x1[3])||(x==x1[4])){
			balldirection=0;
			if(dir==up1){
				balldirection_y-=difficulty;
			}
			if(dir==down1){
				balldirection_y+=difficulty;
			}
		}
	}
	if(y==y2-1){
		if(x==x2[0]||x==x2[1]||x==x2[2]||x==x2[3]||x==x2[4]){
			balldirection=1;
			if(dir==up2){
				balldirection_y-=difficulty;
			}
			if(dir==down2){
				balldirection_y+=difficulty;
			}
		}
	}
	
	if(balldirection==0)y=y+difficulty;
	if(balldirection==1)y=y-difficulty;
	x+=balldirection_y;
	
	
	
	
}
void gameOver(){
		sleep(2);
		system("cls");
		cout << " #####     #    #     # ####### ####### #     # ####### ######\n" ;
    	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
    	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
    	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
    	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
    	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
    	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
    	if(playerlose==2)
    	{
			cout<<"######  #          #    #     # ####### ######       #    #     # # #     #"<<endl;
    		cout<<"#     # #         # #    #   #  #       #     #      #    #     # # ##    #"<<endl;
   	 		cout<<"#     # #        #   #    # #   #       #     #      #    #     # # # #   #"<<endl;
    		cout<<"#     # #       #     #    #    ######  ######       #    #  #  # # #  #  #"<<endl;
  		  	cout<<"######  #       #######    #    #       #  #         #    # # # # # #   # #"<<endl;
  		  	cout<<"#       #       #     #    #    #       #   #        #    ##   ## # #    ##"<<endl;
   		 	cout<<"#       ####### #     #    #    ####### #    #       #    #     # # #     #"<<endl;
   		}
		if(playerlose==1)
		{
			cout<<"######  #          #    #     # ####### ######       ######     #     # # #     #"<<endl;
    		cout<<"#     # #         # #    #   #  #       #     #            #    #     # # ##    #"<<endl;
   	 		cout<<"#     # #        #   #    # #   #       #     #            #    #     # # # #   #"<<endl;
    		cout<<"#     # #       #     #    #    ######  ######           #      #  #  # # #  #  #"<<endl;
  		  	cout<<"######  #       #######    #    #       #  #           #        # # # # # #   # #"<<endl;
  		  	cout<<"#       #       #     #    #    #       #   #        #          ##   ## # #    ##"<<endl;
   		 	cout<<"#       ####### #     #    #    ####### #    #       #######    #     # # #     #"<<endl;
   		}
}
main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
	}
	gameOver();
}
