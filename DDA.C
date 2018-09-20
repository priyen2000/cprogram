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
	int x,x1,y,y1;
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,&"c:/TurboC3/BGI");
	printf("\n Enter x co-ordinate");
	scanf("%d %d",&x,&x1);
	printf("\n Enter y co-ordinate");
	scanf("%d %d",&y,&y1);
	dda(x,y,x1,y1);
	getch();
}