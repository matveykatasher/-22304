#include <stdio.h>
#include <math.h>
int k;
void Compare_to_Big (int *numb1, int *numb2) {
	if (*numb1>*numb2) {
		k=*numb1;
		*numb1=*numb2;
		*numb2=k;
	}
}

void Compare_to_Small (int *numb1, int *numb2) {
	if (*numb1<*numb2) {
		k=*numb1;
		*numb1=*numb2;
		*numb2=k;
	}
}

void Compare_Absolutely (int *numb1, int *numb2) {
	if (fabs(*numb1)>fabs(*numb2)) {
		k=*numb1;
		*numb1=*numb2;
		*numb2=k;
	} 
}

int Replace (int* DMas, int numb, char direct) {
	int i, j;
		if (direct=='>') {
			for (i=1;i<=numb-1;i++) {
				for (j=i;j<=numb;j++) {
					Compare_to_Big (&DMas[i], &DMas[j]);
				}
			}
		}
		else if (direct=='<') {
			for (i=1;i<=numb-1;i++) {
				for (j=i;j<=numb;j++) {
					Compare_to_Small (&DMas[i], &DMas[j]);
				}
			}
		}
		else {
			for (i=1;i<=numb-1;i++) {
				for (j=i;j<=numb;j++) {
					Compare_Absolutely (&DMas[i], &DMas[j]);
				}
			}	
		}
	return (*DMas);
}

int main()
{
	printf ("Эта программа производит сортировку введенного\
 динамического массива\nВведите размер массива:\n"); 
	int numb, i;
	int s = scanf ("%d", &numb);
	if (s<1) {
		printf("Вы ввели неправильный тип перемонной");
		return (90);
	}
	int* DMas = new int [numb];
	for(i=1;i<=numb;i++) {
		printf ("Введите %d элемент:\n", i);
		scanf ("%d", &DMas[i]);
	}
	char direct;
	printf ("В каком направлении стоить производить сортировку? По\
 убыванию (<), или по возростанию (>), или по абсолютному значению (!)\
?\n");
	scanf (" %c", &direct);
	Replace (DMas, numb, direct);
	for(i=1;i<=numb;i++) {
		printf ("DMas [%d] = %d\n", i ,DMas[i]);
	}
	delete [] DMas;
	return 0;
}

