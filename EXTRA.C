#include<stdio.h>
#include<conio.h>
void main()
{
	int i=1,j=1,a=0,b=0;
	clrscr();
	while(i++,j++)
	{
		printf("%d %d",i,j);
		if(i<5)
		break;
	}
	if(a=0,b=0)
	{
		printf("\n yes");
	}
	else
	{
		printf("\n no");
	}
	getch();
}
