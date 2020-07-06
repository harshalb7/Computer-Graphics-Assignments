/*
											ASSIGNMENT NO - 05

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
#include<math.h>
class pixel1
{
	public:
		int xco,yco,color;
		pixel1()
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
class draw_lines:public pixel1
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
		void draw()
		{
		
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
				delay(30);
			}
		}
		
		
};

class pixel
{
	public:
		int drawpixel(int,int,int);
};
int pixel::drawpixel(int x1,int y1,int c)
{	
	putpixel(x1,y1,c);	
}
class draw_circle:public pixel
{
	public:
		
		int x,y,r;
		int Di;
		void circle1(int,int,int);
		void mh(int,int,int);
		void md(int,int,int);
		void mv(int,int,int);		
};
void draw_circle::circle1(int xc,int yc,int r)
{
	int d,d1;
	x=0;
	y=r;	
	Di=2*(1-r);
	int limit=0;
	while(y>=limit)
	{
		int m,n;
		drawpixel(xc+x,yc+y,12);
		drawpixel(xc+x,yc-y,12);
		drawpixel(xc-x,yc+y,12);
		drawpixel(xc-x,yc-y,12);
		delay(50);
		if(Di<0)
		{
			d=(2*Di)+(2*y)-1;
			if(d<=0)
			{
				mh(x,y,Di);	
			}
			else
			{
				md(x,y,Di);
			}	
		}
		else if(Di>0)
		{
			d=(2*Di)-(2*x)-1;
			if(d<=0)
			{
				md(x,y,Di);	
			}
			else
			{
				mv(x,y,Di);
			}	
		}
		else
			md(x,y,Di);
			
	}
}
void draw_circle::mh(int x1,int y1,int Di1 )
{
	x=x1+1;
	Di=Di1+(2*x1)+1;
}
void draw_circle::md(int x2,int y2,int Di2 )
{
	x=x2+1;
	y=y2-1;
	Di=Di2+(2*x2)-(2*y2)+2;
}
void draw_circle::mv(int x3,int y3,int Di3 )
{
	y=y3-1;
	Di=Di3-(2*y3)+1;	
}

int main()
{		
	int l,b,x1,ch,y1;
	draw_circle c;	
	draw_lines d;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int xmax,ymax,xmid,ymid;
	
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	line(xmid,0,xmid,ymax);
	line(0,ymid,xmax,ymid);
	do
	{
		cout<<"\n 1>SHAPE 1\n\n 2>SHAPE 2\n\n 3>EXIT";
		cout<<"\n ENTER YOUR CHOICE";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n Enter length breadth";
			cin>>l>>b;
			cout<<"\n Enter the starting point";
			cin>>x1>>y1;

			//==============================================
			d.setline(xmid+x1,ymid-y1,xmid+x1+l,ymid-y1);
			d.draw();
			d.setline(xmid+x1,ymid-y1,xmid+x1,ymid-(y1+b));
			d.draw();
			d.setline(xmid+x1+l,ymid-y1,xmid+x1+l,ymid-(y1+b));
			d.draw();	
			d.setline(xmid+x1,ymid-(y1+b),xmid+x1+l,ymid-(y1+b));
			d.draw();	
			//==============================================
			setcolor(12);
			d.setline(xmid+x1,ymid-(y1+b/2),xmid+x1+l/2,ymid-(y1+b));
			d.draw();
			d.setline(xmid+x1+l/2,ymid-(y1+b),xmid+x1+l,ymid-(y1+b/2));
			d.draw();
			d.setline(xmid+x1+l,ymid-(y1+b/2),xmid+x1+l/2,ymid-y1);
			d.draw();
			d.setline(xmid+x1+l/2,ymid-y1,xmid+x1,ymid-(y1+b/2));
			d.draw();
		
			//===============================================
			setcolor(4);
			d.setline(xmid+x1+3*l/4,ymid-(y1+b/4),xmid+x1+3*l/4,ymid-(y1+3*b/4));
			d.draw();
			d.setline(xmid+x1+l/4,ymid-(y1+3*b/4),xmid+x1+3*l/4,ymid-(y1+3*b/4));
			d.draw();
			d.setline(xmid+x1+l/4,ymid-(y1+b/4),xmid+x1+l/4,ymid-(y1+3*b/4));
			d.draw();
			d.setline(xmid+x1+l/4,ymid-(y1+b/4),xmid+x1+3*l/4,ymid-(y1+b/4));
			d.draw();
		
			
			//===============================================
			break;
			
		case 2:
			float a,r1,r2;
			int x,x2,y,y2,h;
			cout<<"\n enter side of equilateral triangle";
			cin>>a;
			cout<<"\n Enter the top vertex of traingle";
			cin>>x>>y;
			x2=xmid+x;
			y2=ymid-y;
			h=a*(sqrt(3)/2);
 			r1=a*(sqrt(3)/6);
			r2=a*(sqrt(3)/3);
			
			cout<<"radius 1:"<<r1;
			cout<<"\n radius 2:"<<r2;
			
			d.setline(x2,y2,x2-a/2,y2+h);
			d.draw();
			d.setline(x2-a/2,y2+h,x2+a/2,y2+h);
			d.draw();
			d.setline(x2+a/2,y2+h,x2,y2);
			d.draw();
			setcolor(10);
			c.circle1(x2,y2+r2,r1);
			setcolor(4);
			c.circle1(x2,y2+r2,r2);
			break;
			
		case 3:
			break;
		}	
	}while(ch<3);	
	getch();
}	
