#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int round(float x)
{
	return (x+0.5);
}
void dda(int xa,int ya,int xb,int yb)
{
	int dx,dy,x,y,xincr,yincr,steps,i;
	dx=abs(xb-xa);
	dy=abs(yb-ya);
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
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
	initgraph(&gd,&gm,"c:/TurboC3/BGI");
	dda(200,300,200,500);
	getch();

}