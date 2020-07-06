/*
											ASSIGNMENT NO - 03

Name   :- Harshal Bhimrao Bodhare
SUB    :- CGL
ROLL NO:- 09
CLASS  :- SE
DIV    :- A
*/
#include<iostream>
#include<cmath>
using namespace std;
#include<graphics.h>
class polygon
{
	public:
		float reflection_matrix[10][3];
		void rotation(int v,float c[][3],int theta);
		void scaling(int v,float c[][3],int sx,int sy);
		void translation(int v,float c[][3],int tx,int ty);
		void display(int ,float c[][3]);
		void reflection(int,float c[][3]);
		void shearing(int,float c[][3]);
		void mul(int ,float c[][3],float b[][3],float a[][3]);
};
void polygon::display(int v,float c[][3])
{
	int xmax,ymax,xmid,ymid;
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	line(0,ymid,xmax,ymid);
	line(xmid,0,xmid,ymax);
	for(int i=0;i<v-1;i++)
	{
		line(xmid+c[i][0],ymid-c[i][1],xmid+c[i+1][0],ymid-c[i+1][1]);
	}
	line(xmid+c[v-1][0],ymid-c[v-1][1],xmid+c[0][0],ymid-c[0][1]);

}
void polygon::reflection(int v,float c[][3])
{
	int choice;
	float a[10][3];
	cout<<"\n *****	REFLECTION	*****";
	cout<<"\n1>About x-axis\n2>About y-axis\n3>about y=x line\n4>about origin";
	cout<<"\n Enter your choice";
	cin>>choice;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<3;j++)
		{
			reflection_matrix[i][j]=0;
		}
	}
	switch(choice)
	{
		case 1:
			reflection_matrix[0][0]=1;
			reflection_matrix[1][1]=-1;
			reflection_matrix[2][2]=1;
			break;
		case 2:
			reflection_matrix[0][0]=-1;
			reflection_matrix[1][1]=1;
			reflection_matrix[2][2]=1;
			break;

		case 3:
			reflection_matrix[0][0]=1;
			reflection_matrix[1][1]=1;
			reflection_matrix[2][2]=1;
			break;

		case 4:
			reflection_matrix[0][0]=-1;
			reflection_matrix[1][1]=-1;
			reflection_matrix[2][2]=1;
			break;
	}
	mul(v,c,reflection_matrix,a);
	display(v,a);
}
void polygon::translation(int v,float c[][3],int tx,int ty)
{
	float b[10][3],a[10][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=1;
	b[1][1]=1;
	b[2][2]=1;
	b[2][0]=tx;
	b[2][1]=ty;
	mul(v,c,b,a);
	display(v,a);
}
void polygon::shearing(int v,float c[][3])
{
	int choice;
	float a[10][3];
	int s_x,s_y;
	float shear_matrix[10][3];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
				shear_matrix[i][j]=1;
			else
				shear_matrix[i][j]=0;
		}
	}
	cout<<"\n*****	Shearing Types	*****";
	cout<<"\n1>x-shear\n2>y-shear";
	cin>>choice;
	if(choice==1)
	{
		cout<<"\n Enter x shear";
		cin>>s_x;
		shear_matrix[1][0]=s_x;
	}
	else
	{
		cout<<"\n Enter y shear";
		cin>>s_y;
		shear_matrix[0][1]=s_y;
	}
	mul(v,c,shear_matrix,a);
	display(v,a);
}
void polygon::rotation(int v,float c[][3],int angle)
{
	float b[10][3],a[10][3];
	int xp,yp;
	xp=c[0][0];
	yp=c[0][1];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]= cos(angle*3.14/180);
	b[0][1]= sin(angle*3.14/180);
	b[1][0]=-sin(angle*3.14/180);
	b[1][1]= cos(angle*3.14/180);
	b[2][0]=((-xp*cos(angle*3.14/180))+(yp*sin(angle*3.14/180)))+xp;
	b[2][1]=((-xp*sin(angle*3.14/180))-(yp*cos(angle*3.14/180)))+yp;
	b[2][2]=1;
	mul(v,c,b,a);
	display(v,a);
}

void polygon::scaling(int v,float c[][3],int sx,int sy)
{
	float b[10][3],a[10][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;
	mul(v,c,b,a);
	display(v,a);
}

void polygon::mul(int v,float c[][3],float b[][3],float a[][3])
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[i][j]=0;
		}
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				a[i][j]=a[i][j]+c[i][k]*b[k][j];
			}
		}
	}
}
int main()
{
	polygon p;
	int v;
	int ch,tx,ty,sx,sy,theta;
	float c[3][3];
	cout<<"\n ENTER NUMBER OF VETICES";
	cin>>v;
	for(int i=0;i<v;i++)
	{
		cout<<"\n enter vertex no"<<"("<<i+1<<")";
		cin>>c[i][0];
		cin>>c[i][1];
		c[i][2]=1;
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	p.display(v,c);
	do
	{


	        cout<<"\n\n **** 2-D TRANSFORMATION ****";
		cout<<"\n\n\t\t1.SCALING \n\n\t\t2.ROTATION \n\n\t\t3.TRANSLATION \n\n\t\t4.REFLECTION \n\n\t\t5.SHEARING \n\n\t\t6.EXIT ";
	        cout<<"\n\n\tEnter your choice(1-3):";
	        cin>>ch;

		switch(ch)
		{

			case 1:
				cout<<"case 1";
				cout<<"\n Enter scaling factors";
				cin>>sx>>sy;
				p.scaling(v,c,sx,sy);
				break;

			case 2:
				cout<<"case 2";
				cout<<"\n Enter angle of rotation ";
				p.rotation(v,c,theta);
				break;

			case 3:
				cout<<"case 3";
				cout<<"\n Enter translating factors";
				cin>>tx>>ty;
				p.scaling(v,c,tx,ty);
				break;

			case 4:
				cout<<"case 4";
				p.reflection(v,c);
				break;

			case 5:
				cout<<" case 5";
				p.shearing(v,c);
				break;
		}
	}while(ch<6);
	getch();
	closegraph();
	return 0;

}

