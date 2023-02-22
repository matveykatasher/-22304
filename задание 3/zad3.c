#include <stdio.h>

int main()
{
	printf ("Эта программа выводит число Pi с точностью до того\
 знакого, которого потребовал пользователь\nВведите число до коготорого\
 хотите посчитать число Pi\n");
	int i, numb=0, n=0;
	double count=1, S1=0, S2=0;
	int s = scanf ("%d", &numb);
	if ((numb<0)||(s<1)) {
		printf("Вы ввели неправильный тип перемонной");
		return (90);
	}
	for (i=1;i<=numb;i++) { /*мы высчитываем точность до которой
		 хотим посчитать число Pi*/
		count/=10;
	}
	do {
		n++;
		S1=S2+(4.0/(2*n-1));
		n++;
		S2=S1-(4.0/(2*n-1));
	}
	while ((S1-S2)>count);
	switch (numb) {	
	case 0: printf ("%.f\n", (float)((S1+S2)/2));
	break;
	case 1: printf ("%.1f\n", (float)((S1+S2)/2));
	break;
	case 2: printf ("%.2f\n", (float)((S1+S2)/2));
	break;
	case 3: printf ("%.3f\n", (float)((S1+S2)/2));
	break;
	case 4: printf ("%.4f\n", (float)((S1+S2)/2));
	break;
	case 5: printf ("%.5f\n", (float)((S1+S2)/2));
	break;
	default: printf ("%f\n", (float)((S1+S2)/2));
	break; 
	}
	printf("%d", n);
    int c;
    scanf ("%d", &c);
	return 0;
}

