#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	int a,b,c,d,n,x,y;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if (!(isdigit((int)a))||!(isdigit((int)b))||!(isdigit((int)c)))
	{
		if (a==0)
		{
			if (b==0)
			{
				if (c==0)
				{
					printf("all results");
				}
				else{printf("error");}
			}
			else
			{
				int x=-1*c/b;
			}
		}
		else
		{
			d=pow(b,2)-4*a*c;
			if (d>=0)
			{
				x=(-1*b-sqrt(d))/(2*a);
				y=(-1*b+sqrt(d))/(2*a);
				printf("%d",x);
				printf(" ");
				printf("%d",y);
			}
			else{printf("error");}
		}
	}
	else{printf("error");}
	scanf ("%d",&n);
	return 0;
}