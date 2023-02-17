#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100//#define имя_макроса последовательность_символов

int array[MAX_SIZE];

typedef struct result{
    int min, max;
    double avg, rms;
}result ;

result calc(int n){
    result res;
    res.avg = res.rms = 0;
    res.max = res.min = array[0];
    for (int i = 0; i < n; i++){
        if (array[i] < res.min)
            res.min = array[i];
        if (array[i] > res.max)
            res.max = array[i];
        res.avg += array[i];
        res.rms += pow(array[i], 2);
    }
    res.avg /= n;
    res.rms = pow(res.rms / n - pow(res.avg, 2), 0.5);
    return res;
}

int main() {
    int n;
    result res;
    char input;
    printf("речь max, min, avg, rms\n");
    while (1) {
        printf("введите размер массива (%d maximum)\n", MAX_SIZE);
        scanf_s("%d", &n);
        if (n > 100){
            printf("ошибка в размере\n");
            continue;
        }
        printf("введите элементы массиваy\n");
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &array[i]);
        }
        res = calc(n);
        printf("min %d\nmax %d\navg %f\nrms %f\n", res.min, res.max, res.avg, res.rms);
        printf("правильно посчитано ? (y/n)\n");
        scanf_s(" %c", &input);
        if (input == 'n')
            break;
    }
    return 0;
}