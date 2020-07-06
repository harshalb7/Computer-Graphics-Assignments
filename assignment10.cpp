/*
											ASSIGNMENT NO - 10

Name   :- Harshal Bhimrao Bodhare
SUB    :- CGL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A									
*/
#include<iostream>
using namespace std;
#include<graphics.h>

void generate_curve(int x[],int y[],int colour)
{
	int px,py;
	double t;
	for(t=0;t<=1;t+=0.0005)
	{
		px=x[0]*(1-t)*(1-t)*(1-t)+3*x[1]*(t)*(1-t)*(1-t)+3*x[2]*(t)*(t)*(1-t)+x[3]*(t)*(t)*(t);
		py=y[0]*(1-t)*(1-t)*(1-t)+3*y[1]*(t)*(1-t)*(1-t)+3*y[2]*(t)*(t)*(1-t)+y[3]*(t)*(t)*(t);
		putpixel(px,py,colour);
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	char n,ch;
	int x[4],y[4];
	do
	{
		cout<<"\nEnter four control points\n";
		for(int i=0;i<4;i++)
		{
			cin>>x[i];
			cin>>y[i];
		}
		generate_curve(x,y,GREEN);
		cout<<"\n do you want to continue?";
		cin>>ch;
	}while(ch!='n');
	getch();
	return 0;
}

