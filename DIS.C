#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#define df_size 50
float df_pen_x,df_pen_y,frame_pen_x,frame_pen_y;
float df_x[df_size],df_y[df_size],x,y;
float we,ws,w,h,hs,he,dx,dy;
float x1,y1;
int df_op[df_size],n,op,free1=1,erase_flag=0;
void initialize()
{
	frame_pen_x=0;
	frame_pen_y=0;
	dx=dy=0;
	hs=ws=0;
	we=getmaxx();
	he=getmaxy();
	w=we-ws;
	h=he-hs;
	free1=1;
}
void bresenham(int xa,int ya,int xb,int yb)
{
	int dx,dy,twody,twodydx,p,x,y,xend,yend,twodx,twodxdy;
	float m;
	dx=abs(xb-xa);
	dy=abs(yb-ya);
	if(dx>dy)
	{
		printf("\n gentle");
		if(dx==0)
			m=(float)dy;
		else
			m=(yb-ya)/(xb-xa);
		p=2*dy-dx;
		twody=2*dy;
		twodydx=2*(dy-dx);
		if(xa>xb)
		{
			x=xb;
			y=yb;
			xend=xa;
		}
		else
		{
			x=xa;
			y=ya;
			xend=xb;
		}
		putpixel(x,y,1);
	while(x<xend)
	{
		x=x+1;
		if(p<0)
		{
			p=p+twody;
		}
		else
		{
			if(0<m<1)
			{
				y=y+1;
			}
			else
			{
				y--;
			}
			p=p+twodydx;
		}
		putpixel(x,y,1);
	}
}
	else
	{
		if(dx==0)
			m=(float)dy;
		else
			m=(yb-ya)/(xb-xa);
		printf("\n steep");
		p=2*dx-dy;
		twodx=2*dx;
		twodxdy=2*(dx-dy);
		if(ya>yb)
		{
			x=xb;
			y=yb;
			yend=ya;
		}
		else
		{
			x=xa;
			y=ya;
			yend=yb;
		}
		putpixel(x,y,1);
		while(y<yend)
		{
			y=y+1;
			if(p<0)
			{
				p=p+twodx;
			}
			else
			{
				if(m>=1)
				{
					x=x+1;
				}
				else
				{
					x=x-1;
				}
				p=p+twodxdy;
			}
		putpixel(x,y,1);
	}
}
}
void getpoint(int n)
{
	op=df_op[n];
	x=df_x[n];
	y=df_y[n];
}
void putpoint(int op,float x,float y)
{
	if(free1>df_size)
	{
		printf("\n full");
	}
	else
	{
		df_op[free1]=op;
		df_x[free1]=x;
		df_y[free1]=y;
		free1++;
	}
}
void display_file_enter(int op)
{
	putpoint(op,df_pen_x,df_pen_y);
}
void move_abs(float x,float y)
{
	df_pen_x=x;
	df_pen_y=y;
	display_file_enter(1);
}
void move_rel(float dx,float dy)
{
	df_pen_x+=dx;
	df_pen_y+=dy;
	display_file_enter(1);
}
void line_abs(float x,float y)
{
	df_pen_x=x;
	df_pen_y=y;
	display_file_enter(2);
}
void line_rel(float dx,float dy)
{
	df_pen_x+=dx;
	df_pen_y+=dy;
	display_file_enter(2);
}
void do_move(float x,float y)
{
      frame_pen_x=max(ws,min(we,x*w+ws));
      frame_pen_y=max(hs,min(he,y*h+hs));
}
void do_line(float x,float y)
{
	x1=frame_pen_x;
	y1=frame_pen_y;
	frame_pen_x=max(ws,min(we,x*w+ws));
	frame_pen_y=max(hs,min(he,y*h+hs));
	bresenham((int)(x1+0.5),(int)(y1+0.5),(int)(frame_pen_x+0.5),(int)(frame_pen_y+0.5));
}
void new_frame()
{
	erase_flag=1;
}
void erase()
{
	int i,j;
	for(i=0;i<getmaxx();i++)
	{
		for(j=0;j<getmaxy();j++)
		{
			putpixel(x,j,1);
		}
	}
}
void inter(int start,int count)
{
	for(n=start;n<=count;n++)
	{
		getpoint(n);
		if(op==1)
		{
			do_move(x,y);
		}
		else if(op==2)
		{
			do_line(x,y);
		}
		else
		{
			printf("\n error");
		}
	}
}
void mpc()
{
	if(erase_flag==1)
	{
		erase();
		erase_flag=0;
	}
	if(free1>1)
	{
		inter(1,free1-1);
	}
	free1=1;
}
void house()
{
	line_rel(-0.2,0.0);
	line_rel(0.0,-0.2);
	line_rel(0.1,-0.2);
	line_rel(0.1,0.2);
	line_rel(0.0,0.2);
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:/TurboC3/BGI");
	cleardevice();
	initialize();
	new_frame();
	move_abs(0.3,0.5);
	house();
	mpc();
	circle(200,40,20);
	getch();
}