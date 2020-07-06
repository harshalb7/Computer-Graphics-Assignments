/*
											ASSIGNMENT NO - 06

Name   :- Harshal Bhimrao Bodhare
SUB    :- CGL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A									
*/#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class pixel
{
	public:
		int xco,yco,color;
		pixel()
		{
			xco=yco=0;
			color=4;
		}
		void set_co(int x,int y,int c=15)
		{
			xco=x;
			yco=y;
			color=c;
		}
		void draw_pixel()
		{
			putpixel(xco,yco,color);
		}
};

class draw_line:public pixel
{
	
	
		public:
		int x2,y2;
		draw_line()
		{
			x2=0;y2=0;
		}
		void set_line(int x,int y,int xx,int yy)
		{
			set_co(x,y);
			x2=xx;
			y2=yy;
		}
		void dotted_line()
		{
			float x,y,len,dx,dy;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			
			if(dx>=dy)			
				len=dx;
			else 
				len=dy;
			
			dx=(x2-xco)/len;
			dy=(y2-yco)/len;
			
			x=xco+0.5;
			y=yco+0.5;
			int i=1;
			while(i<=len)
			{
				x=x+dx;
				y=y+dy;
				if(i%2==0)
				{
					set_co(x,y,4);
					draw_pixel();
				}
				i=i+1;
				
			}
			
			delay(2000);
		}
		void dashed_line()
		{
			float x,y,len,dx,dy;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			
			if(dx>=dy)			
				len=dx;
			else 
				len=dy;
			
			dx=(x2-xco)/len;
			dy=(y2-yco)/len;
			
			x=xco+0.5;
			y=yco+0.5;
			int i=1;
			while(i<=len)
			{
				x=x+dx;
				y=y+dy;
				if(i%5!=0)
				{
					set_co(x,y,4);
					draw_pixel();
				}
				i=i+1;
				
			}
			
			delay(2000);
		}

		void thick_line(int th)
		{
			float x,y,len,dx,dy;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			
			if(dx>=dy)			
				len=dx;
			else 
				len=dy;
			
			dx=(x2-xco)/len;
			dy=(y2-yco)/len;
			
			x=xco+0.5;
			y=yco+0.5;
			float w1,w2;
			w1=((th-1)/2)*(sqrt(pow((x2-xco),2)+pow((y2-yco),2))/(abs(x2-xco)));
			w2=((th-1)/2)*(sqrt(pow((x2-xco),2)+pow((y2-yco),2))/(abs(y2-yco)));
			for(int i=0;i<len;i++)
			{
				if(abs(x2-xco)>abs(y2-yco))
				{
					set_co(x,y,15);
					draw_pixel();
					for(int j=y+1;j<=y+w1;j++)	
					{	
						set_co(x,j,15);
						draw_pixel();
					}
					for(int j=y-1;j>=y+w1;j--)	
					{
						set_co(x,j,15);
						draw_pixel();
					}
				}
				else
				{
					set_co(x,y,15);
					draw_pixel();
					for(int j=y+1;j<=y+w2;j++)	
					{
						set_co(x,j,15);
						draw_pixel();
					}
					for(int j=y-1;j>=y+w2;j--)
					{
						set_co(x,j,15);	
						draw_pixel();
					}

				}
				x=x+dx;
				y=y+dy;
			}
			delay(7000);
		}
};


int main()
{
	draw_line obj;
	float x1,y1,x2,y2,w;
	
	char resp;
	int gd=DETECT,gm,ch;

	do
	{
		cout<<"\nMENU\n1.DOTTED_LINE\n2.DASHED_LINE\n3.THICK_LINE\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter starting co-ordinates : ";	
				cin>>x1>>y1;	
				cout<<"\nEnter ending co-ordinates : ";	
				cin>>x2>>y2;
				initgraph(&gd,&gm,NULL);
				obj.set_line(x1,y1,x2,y2);
				obj.dotted_line();
				getch();
				closegraph();
				break;
			case 2:	
				cout<<"Enter starting co-ordinates : ";	
				cin>>x1>>y1;	
				cout<<"\nEnter ending co-ordinates : ";	
				cin>>x2>>y2;
				obj.set_line(x1,y1,x2,y2);	
				obj.dashed_line();
				initgraph(&gd,&gm,NULL);
				getch();
				break;
			case 3:
				cout<<"Enter starting co-ordinates : ";	
				cin>>x1>>y1;	
				cout<<"\nEnter ending co-ordinates : ";	
				cin>>x2>>y2;
				cout<<"\nEnter thickness : ";	
				cin>>w;
				initgraph(&gd,&gm,NULL);
				obj.set_line(x1,y1,x2,y2);
				obj.thick_line(w);
				
				break;
			default:
				break;
		}
		cout<<"\nAny more?(y/n)";
		cin>>resp;
	}while(toupper(resp)=='Y');
	cout<<"\nOUT OF PROGRAM"<<endl;
	getch();
	closegraph();

	return 0;
}

