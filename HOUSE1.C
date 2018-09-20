#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
float round(int x)
{
	return x+0.5;
}
void dda(int xa,int ya,int xb,int yb)
{
	int dx,dy,steps,xincr,x,y,yincr,i;
	dx=xb-xa;
	dy=yb-ya;
	if(abs(dx)>abs(dy))
	{
		steps=dx;
	}
	else
	{
		steps=dy;
	}
	xincr=dx/steps;
	yincr=dy/steps;
	x=xa;
	y=ya;
	putpixel(x,y,1);
	for(i=0;i<steps;i++)
	{
		x=x+xincr;
		y=y+yincr;
		putpixel(round(x),round(y),1);
	}
}
void main()
{
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,&"c:/TurboC3/BGI");
	dda(100,100,100,300);
	dda(300,100,300,300);
	dda(100,100,300,100);
	dda(100,300,300,300);
	dda(150,100,150,300);
	dda(120,50,100,100);
	getch();
}