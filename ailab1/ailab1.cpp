#include <iostream>
#include<locale.h>  
#include<time.h>

double shell(int* items, int count) {
    int gap;
    time_t start = clock();
    for (gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; ++i) {
            int temp = items[i];
            int j = i - gap;
            while ((j >= 0) && (items[j] > temp)) {
                items[j + gap] = items[j];
                j -= gap;
            }
            items[j + gap] = temp;
        }
    }
    time_t end = clock();
    double time = difftime(end, start) / CLOCKS_PER_SEC;
    return time;
}

double qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    time_t start = clock();
    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
    time_t end = clock();
    double time = difftime(end, start) / CLOCKS_PER_SEC;
    return time;

}
int main() {
    setlocale(LC_ALL, "rus");
    int mas[100000];
    double time_q, time_s;
    int h = 0;
    int i = 0;
    srand(time(0));
    while (1) {
    printf("Выберите режим работы алгоритма:\n 1.Случайное заполнение массива\n 2.Заполнение массива по возрастанию\n 3.Заполнение массива по убыванию\n"); 
    printf(" 4.Заполнение массива  сначала по возрастанию, потом по убыванию\n");
    scanf_s("%d", &h);
    switch (h) {
    case 1:
        for (i = 0; i < 10000; i++) {
            mas[i] = rand() % 10000;
        }
        printf("Заполнение массива выполнено\n");
        break;
    case 2:
        i = 0;
        while (i < 10000) {
            mas[i] = i;
            i++;
        }
        printf("Заполнение массива выполнено\n");
        break;
    case 3:
        i = 0;
        while (i < 10000) {
            mas[i] = (i - 10000) * -1;
            i++;
        }
        printf("Заполнение массива выполнено\n");
        break;
    case 4:
        i = 0;
        while (i < 10000) {
            if (i < 5000) {
                mas[i] = i;
            }
            else {
                mas[i] = (i - 10000) * -1;
            }
            i++;
        }
        printf("Заполнение массива выполнено\n");
        break;
    default:
        printf("Ошибка, выберите один из представленных режимов\n");
        break;
    }
        if (h > 0 and h < 5) {
            time_s = shell(mas, 10000);
            printf(" \nВремя сортировки методом Шелла: %f\n ", time_s);
            time_q = qs(mas, 0, 9999);
            printf("Время сортировки методом быстрой сортировки:%f\n ", time_q);
            break;
            
        }
    }

    return 0;
}