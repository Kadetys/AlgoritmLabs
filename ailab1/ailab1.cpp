
#include <iostream>
#include <time.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    int i = 0;
    int r;
    printf("Введите размер массива:\n");
    scanf_s("%d", &r);
    int* m = new int[r];
    srand(time(0));
    while (i < r) {
        m[i] = rand() % 100;
        i++;
    }
    for (int j = 0; j < r; j++) {
        printf("%d \n", m[j]);
    }
}


