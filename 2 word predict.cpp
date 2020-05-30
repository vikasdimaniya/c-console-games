#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
class vikas
{
	public:
};
main()
{
	int i,r,correct=0,wrong=0,repeat=0,times,z,y=0,s,c;
	string b;
	string a[10]={"vik","dud","wai","abc","tat","com","zam","gok","car","bik"};
	while(repeat!=2)
	{
		system("cls");
		cout<<"RULES-->>\n\n\n\tNo cheating.\n\tTHREE LETTER WORD.\n\tOnly lowercase letters are allowed.\n\tTEN chances will be given.\n\tFind the correct word.\n\tCorrect means there are as many correctly matched letters,\n\twrong means there are as many wrong letters."<<endl;
		srand(time(0));
		r=rand()%10;
		cout<<"\n\n\n\n\n\t\t\t\t-->> START GAME"<<endl;
		getch();
		system("cls");
	
	
		
		while(times<=10)					//chances
		{
			correct=0;
			wrong=0;
			times++;
			cin>>b;
			for(y=0;y<3;y++)
			{
				for(i=0;i<3;i++)				//checker
				{
					if(b[y]==a[r][i])
					{
						correct++;
						if(correct==3)
						{
							s=1;
							break;
						}
						break;
					}

				}
				if(s==1)
				{
					break;
				}
			}
			if(s==1)
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t**WINNER**"<<endl;
				getch();
				system("cls");
				break;
			}
			cout<<"\t\t\tcorrect :"<<correct<<"\twrong :"<<3-correct<<endl;

		}
		system("cls");
		if(s!=1)
		{
			cout<<"\t\t\tGAME OVER\n\n\n\t\t\t"<<endl;
			getch();
			system("cls");
		}
		cout<<"1: NEW GAME\n2: EXIT"<<endl;
		cin>>repeat;
		times=1;
		s=0;
	}
}
