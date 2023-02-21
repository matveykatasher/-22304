#define data 100
#include <stdio.h>
#include <math.h>
int Mas[data];

int Max (int numb) {
	int i, max=0;
	int* pMas;
	for (i=1, pMas=Mas;i<=numb;i++) {
		if (*(pMas+i)>max) {
			max=*(pMas+i);
		}
	}
	return (max);
}

int Min (int numb) {
	int* pMas;
	int i=1, min=Max(numb);
	for (i=1, pMas=Mas;i<=numb;i++) {
		if (*(pMas+i)<min) {
			min=*(pMas+i);
		}
	}
	return (min);
}

float Mean (int numb) {
	int i;
	float count=0;
	for(i=1;i<=numb;i++) {
		count+=Mas[i];
	}
	count/=numb;
	return (count);
}

float RMS (int numb) {
	int i;
	float S=0;
	for (i=1;i<=numb;i++) {
		S+=pow(Mas[i]-Mean(numb),2);
	}
	S/=numb;
	return(sqrt(S));
}

int main()
{
	printf ("Эта программа вычисляет максимум, минимум, среднее\
 значение, среднеквадратичное отклонение во введенном статическом\
 массиве\nВведите размер массива\n"); 
	int numb, i;
	int s = scanf ("%d", &numb);
	if (s<1) {
		printf("Вы ввели неправильный тип перемонной");
		return (90);
	}
	for(i=1;i<=numb;i++) {
		printf ("Введите %d элемент\n", i);
		scanf ("%d", &Mas[i]);
	}
	printf ("\n\nMax = %d\nMin = %d\nMean = %f\nRMS = %f\n", Max(numb), Min(numb), Mean(numb), RMS(numb));
	return 0;
}
