/*
											ASSIGNMENT NO - 02

Name   :- Harshal Bhimrao Bodhare
SUB    :- CGL
ROLL NO:- 09
CLASS  :- SE 
DIV    :- A									
*/
#include<iostream>
using namespace std;
#include<graphics.h>
class pixel
{
	public:
		void draw_pixel(int x,int y,int c)
		{
			putpixel(x,y,c);
		}
};
class Draw:public pixel
{
	public:
		int x,y,D,d;
		void mh(int x1,int y1,int D1)
		{
			x=x1+1;
			D=D1+2*x1+1;
		}
		void md(int x2,int y2,int D2)
		{
			x=x2+1;
			y=y2-1;
			D=D2+2*x2-2*y2+2;
		}
		void mv(int x3,int y3,int D3)
		{
			y=y3-1;
			D=D3-2*y3-1;
		}
		void draw(int xc,int yc,int rc)
		{
			x=0;
			y=rc;
			int limit=0;
			D=2*(1-rc);
			while(y>=limit)
			{
				draw_pixel(xc+x,yc+y,12);
				draw_pixel(xc+x,yc-y,12);
				draw_pixel(xc-x,yc+y,12);
				draw_pixel(xc-x,yc-y,12);
				delay(50);
				if(D<0)
				{
					d=2*D+2*y-1;
					if(d<0)
						mh(x,y,D);
					else
						md(x,y,D);
				}
				else if(D>0)
				{
					d=2*D-2*x-1;
					if(d<0)
						md(x,y,D);
					else
						mv(x,y,D);
				}
				else
					md(x,y,D);
			}
		}
};
int main()
{
	Draw d;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	d.draw(200,200,100);
	getch();
	closegraph();
	return 0;
}
