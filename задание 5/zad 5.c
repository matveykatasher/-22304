#include <stdio.h>
#include <math.h>

double Func (float x){ //интереумая функция
	double value;
	value = 1/logl(x); //самостоятельно вводим интересуемую нами функцию
	return (value);
}

int main()
{
	int step, i;
	double a, b, h, integral, result;
	int s = scanf ("%lf %lf %d", &a, &b, &step);
	if (s<3) {
		printf("error");
		return (90);
	}
	h=(b-a)/step; //вычисляем длину каждого шага
	integral=(Func(a)+Func(b))/2; /*это первый член суммы по методу 
	трапеции */
	for(i=1;i<step;i++) {
		a+=h;
		integral+=Func(a);
	}
	result = h*integral;
	printf ("%lf\n", result);
	return 0;
}
