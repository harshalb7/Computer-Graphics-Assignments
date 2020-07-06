/*
											ASSIGNMENT NO - 08

Name   :- Harshal Bhimrao Bodhare
SUB    :- CGL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A									
*/

#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

using namespace std;

class POLYGON
{
    private:
        int p[10][10],Trans_result[10][10],Trans_matrix[10][10];
        float Shearing_result[10][10],Shearing_matrix[10][10];
        int Reflection_result[10][10],Reflection_matrix[10][10];

    public:
	int accept_poly(int [][10]);
	void draw_poly(int [][10],int);
	void draw_polyfloat(float [][10],int);
	void matmult(int [][10],int [][10],int,int,int,int [][10]);
	void matmultfloat(float [][10],int [][10],int,int,int,float [][10]);
	void shearing(int [][10],int);
	void reflection(int [][10],int);
};

int POLYGON :: accept_poly(int p[][10])
{
	int i,n;
	cout<<"\n\n\t\tEnter no.of vertices:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n\n\t\tEnter (x,y)Co-ordinate of point P"<<i<<": ";
		cin >> p[i][0] >> p[i][1];
		p[i][2] = 1;
	}
	
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<p[i][j]<<"\t";
		}
	}

	return n;
}
void POLYGON :: draw_poly(int p[][10], int n)
{
	
	int i;
	for(i=0;i<n;i++)
	{
		if(i<n-1)
		{
			line(p[i][0]+320, -p[i][1]+240, p[i+1][0]+320, -p[i+1][1]+240);
			
		}		
		else
			line(p[i][0]+320, -p[i][1]+240, p[0][0]+320, -p[0][1]+240);
	}
	delay(3000);
	
	
}

void POLYGON :: draw_polyfloat(float p[][10], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i<n-1)
		{
			line(p[i][0]+320, -p[i][1]+240, p[i+1][0]+320, -p[i+1][1]+240);
			
		}		
		else
			line(p[i][0]+320, -p[i][1]+240, p[0][0]+320, -p[0][1]+240);
	}
	delay(8000);
	
}



void POLYGON :: shearing(int p[][10],int n)
{
	float Sx,Sy,type; int i,j;
        int i1,j1,k1,r1,c1,c2;
        r1=n;c1=c2=3;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		if(i == j)
			Shearing_matrix[i][j] = 1;
		else
			Shearing_matrix[i][j] = 0;
	}
	cout << "\n\n **** Shearing Types ****";
	cout << "\n\n\t\t1.X-Direction Shear \n\n\t\t2.Y-Direction Shear ";
	cout << "\n\n\t\tEnter your choice(1-2): ";
	cin >> type;
	if(type == 1)
	{
		cout << "\n\n\t\tEnter X-Shear Sx: ";
		cin >> Sx;
		Shearing_matrix[1][0] = Sx;
	}
	else
	{
		cout << "\n\n\t\tEnter Y-Shear Sy: ";
		cin >> Sy;
		Shearing_matrix[0][1] = Sy;
	}
	
        
        for(i1=0;i1<10;i1++)
	for(j1=0;j1<10;j1++)
		Shearing_result[i1][j1] = 0;
	for(i1=0;i1<r1;i1++)
	for(j1=0;j1<c2;j1++)
	for(k1=0;k1<c1;k1++)
		Shearing_result[i1][j1] = Shearing_result[i1][j1]+(p[i1][k1] * Shearing_matrix[k1][j1]);

	cout << "\n\n\t\tPolygon after Shearing…";
	draw_polyfloat(Shearing_result,n);
}

void POLYGON :: reflection(int p[][10],int n)
{
	int type,i,j;
      
        int i1,j1,k1,r1,c1,c2;
 	r1=n;c1=c2=3;
	cout << "\n\n **** Reflection Types ****";
	cout << "\n\n\t\t1.About X-Axis \n\n\t\t2.About Y-Axis \n\n\t\t3.About Origin \
	\n\n\t\t4.About Line y = x \n\n\t\t5.About Line y = -x \
	\n\n\t\tEnter your choice(1-5): ";
	cin >> type;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
			Reflection_matrix[i][j] = 0;
	}
	switch(type)
	{
		case 1:
			Reflection_matrix[0][0] = 1;
                        Reflection_matrix[1][1] = -1;
                        Reflection_matrix[2][2] = 1;
			break;
		case 2:
			Reflection_matrix[0][0] = -1;
                        Reflection_matrix[1][1] = 1;
                        Reflection_matrix[2][2] = 1;
			break;
		case 3:
			Reflection_matrix[0][0] = -1;
                        Reflection_matrix[1][1] = -1;
                        Reflection_matrix[2][2] = 1;
			break;
		case 4:
			Reflection_matrix[0][1] = 1;
			Reflection_matrix[1][0] = 1;
			Reflection_matrix[2][2] = 1;
			break;
		case 5:
			Reflection_matrix[0][1] = -1;
			Reflection_matrix[1][0] = -1;
			Reflection_matrix[2][2] = 1;
			break;
	}
	
        for(i1=0;i1<10;i1++)
	for(j1=0;j1<10;j1++)
		Reflection_result[i1][j1] = 0;
	for(i1=0;i1<r1;i1++)
	for(j1=0;j1<c2;j1++)
	for(k1=0;k1<c1;k1++)
		Reflection_result[i1][j1] = Reflection_result[i1][j1]+(p[i1][k1] * Reflection_matrix[k1][j1]);

	cout << "\n\n\t\tPolygon after Reflection…";
//cout << "\n\n\t\tPolygon after Rotation…";
        for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<Reflection_result[i][j]<<"\t";
		}
	}
	draw_poly(Reflection_result,n);
//closegraph();
}



int main()
{
	int ch,n,p[10][10];
	POLYGON p1;
	cout<<"\n\n **** 2-D TRANSFORMATION ****";
	n= p1.accept_poly(p);
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(320,0,320,480);
	line(0,240,640,240);
	cout <<"\n\n\t\tOriginal Polygon …";
	p1.draw_poly(p,n);
	do
	{
		
                int ch;
	        cout<<"\n\n **** 2-D TRANSFORMATION ****";
		cout<<"\n\n\t\t1.Reflection \n\n\t\t2.Shearing \n\n\t\t3.Exit ";
	        cout<<"\n\n\tEnter your choice(1-3):";
	        cin>>ch;
	   
		switch(ch)
		{
			
			case 1:
				cout<<"case4";
				p1.reflection(p,n);
				break;

			case 2:
				cout<<"case5";
				p1.shearing(p,n);
				break;

			case 3:
				exit(0);
		}
	}while(1);
	getch();
	closegraph();
}
