#include <stdio.h>
#include <math.h>

int main() {
    double result, pii = 0, pi = 4, n; //pii это прем значение
    int N, i = 1;//N колличество знаков
    printf("Введите колличество знаков: ");
    scanf_s("%d", &N);
    for (i = 1 ; ; i ++){
        if (fabs(pi - tmp_pi) <= 1/pow(10, N))//Функция pow() возвращает значение base, возведенное в степень ехр:Функция fabs() возвращает абсолютную величину аргумента num.
            break;
        tmp_pi = pi;
        pi +=  4 / ((2*i + 1) *  pow(-1, i));
    }
    result = (pi + tmp_pi) / 2;
    printf("Pi = %.*f\n",precision, (double)(((int)(result*pow(10,N)))/pow(10,N)));
    scanf("%d",&n);
    return 0;
}