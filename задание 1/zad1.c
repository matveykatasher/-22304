#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	int tr=0;
	int a,b,c,d,n,x,y;
	while (tr==0)
	{
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
		printf_s("%d","OK(0/1):");
		scanf("%d",&n);

		if (n==1)
		{
			tr=1;
		}
	}
	return 0;
}