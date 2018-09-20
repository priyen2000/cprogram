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
	int line[10]={1,1,1,0,1,1,1,0,1,1},cnt=0;
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
		if(cnt<10)
		{
			x=x+xincr;
			y=y+yincr;
		if(line[cnt]==1)
		{
			putpixel(round(x),round(y),3);
		}
		else
		{
		}
		cnt++;
		}
		else
		{
				cnt=0;
		}



	}
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,&"c:/TurboC3/BGI");
	clrscr();
	dda(100,300,400,100);
	getch();
}