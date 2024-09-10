
#include <iostream>
#include <time.h>
#include<locale.h>

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    int i = 0;
    int width;
    int height;
    int type;
    int* m;
    int* sum;
    while (1) {
        printf("Выберите тип массива:\n");
        printf("Одномерный массив: 1\n Двумерный массив: 2\n");
        scanf_s("%d", &type);
        switch (type) {

            case 1:
                printf("Введите размер массива:\n");
                scanf_s("%d", &width);
                m = (int*)malloc(width * sizeof(int));
                while (i < width) {
                    m[i] = rand() % 100;
                    i++;
                }
                for (int j = 0; j < width; j++) {
                    printf("%d \n", m[j]);
                }
                break;
            case 2:
                printf("Введите количество строк:\n");
                scanf_s("%d", &width);
                printf("Введите количество столбцов:\n");
                scanf_s("%d", &height);
                m = (int*)malloc(width * height * sizeof(int));
                sum = (int*)malloc(width * sizeof(int));
                for (int j = 0; j < width; j++) {
                    sum[j * sizeof(int)] = 0;
                    printf("\n");
                    for (int i = 0; i < height; i++) {
                        m[j * i * sizeof(int)] = rand() % 100;
                        sum[j * sizeof(int)] += m[j * i * sizeof(int)];
                        printf("%d  ", m[j * i * sizeof(int)]);
                        if (i == height - 1) {
                            printf(" Сумма элементов строки:  %d", sum[j * sizeof(int)]);
                        }
                    }
                }
                break;
            default:
                printf("Ошибка, введите корректное значение\n");
            }
        if (type == 1 or type == 2) {
           break;
        }
        }
    }


