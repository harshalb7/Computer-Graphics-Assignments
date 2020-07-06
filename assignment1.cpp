/*
											ASSIGNMENT NO - 01

Name   :- Harshal Bhimrao Bodhare
SUB    :- CGL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A									
*/
#include<iostream>
using namespace std;
#include<graphics.h>
#include<math.h>
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
class draw_lines:public pixel
{
	public:
		int x2,y2;
		draw_lines()
		{
			x2=0;y2=0;
		}
		void setline(int x,int y,int xx,int yy)
		{
			set_co(x,y);
			x2=xx;
			y2=yy;
		}
		void draw1()
		{
				int xmax,ymax,xmid,ymid;

			xmax=getmaxx();
			ymax=getmaxy();
			xmid=xmax/2;
			ymid=ymax/2;

			int s1,s2,i,ex;
			float x,y,e,temp,dy,dx;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			
			x=xco;
			y=yco;
			
			if(x2>xco)
				s1=1;
			else if(x2==xco)
				s1=0;
			else if(x2<xco)
				s1=-1;

			if(y2>yco)
				s2=1;
			else if(y2==yco)
				s2=0;
			else if(y2<yco)
				s2=-1;
			
			if(dy>dx)
			{
				temp=dy;
				dy=dx;
				dx=temp;
				ex=1;
			}
			else
				ex=0;
					
			e=2*dy-dx;
			cout<<"\t"<<1;
			cout<<"\t"<<x-xmid;
			cout<<"\t"<<ymid-y<<"\n";
			i=1;			
			while(i<=dx)
			{
				if(e>=0)
				{
					if(ex==1)
						x=x+s1;
					else
						y=y+s2;
					e=e-2*dx;
				}
				if(ex==1)
					y=y+s2;
				else
					x=x+s1;
				e=e+2*dy;
				i=i+1;
				set_co(x,y);
				draw_pixel();
				cout<<"\t"<<1;
				cout<<"\t"<<x-xmid;
				cout<<"\t"<<ymid-y;
				cout<<"\n";
				delay(30);
			}
		}
		void draw1(int color)
		{
			int xmax,ymax,xmid,ymid;

			xmax=getmaxx();
			ymax=getmaxy();
			xmid=xmax/2;
			ymid=ymax/2;

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
			set_co(x,y);
			draw_pixel();
			cout<<"\t"<<1;
			cout<<"\t"<<x-xmid;
			cout<<"\t"<<ymid-y;
			cout<<"\n";
			int i=1;
			while(i<=len)
			{
				x=x+dx;
				y=y+dy;
				i=i+1;
				set_co(x,y,4);
				draw_pixel();
				cout<<"\t"<<i;
				cout<<"\t"<<x-xmid;
				cout<<"\t"<<ymid-y;
				cout<<"\n";
			}
		}
};
int main()
{
	draw_lines d1;
	int xmax,ymax,xmid,ymid;
	int x1,y1,x2,y2;
	cout<<"\n ENTER THE X1 AND Y1";
	cin>>x1>>y1;
	cout<<"\n ENTER THE X2 AND Y2";
	cin>>x2>>y2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	line(0,ymid,xmax,ymid);
	line(xmid,0,xmid,ymax);

	cout<<"\ti\tx\ty\n";	
	d1.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
	d1.draw1(15);
	cout<<"\n\t*********************************************************\n\n";
	cout<<"\ti\tx\ty\n";	
	d1.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
	d1.draw1();
	getch();
	delay(1000);
	closegraph();
	return 0;	
}
