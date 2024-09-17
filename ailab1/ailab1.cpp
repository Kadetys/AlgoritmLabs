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
    double time_q, time_s;
    int h = 0;
    int i = 0;
    int n[5];
    int* mas;
    srand(time(0));
    printf("Введите пять размеров массивов для сбора аналитики:\n");
    scanf_s("%d %d %d %d %d", &n[0], &n[1], &n[2],&n[3], &n[4]);
    for(int j = 0; j<5; j++){
         mas = (int*)malloc(n[j] * sizeof(int));
        for (i = 0; i < n[j];  i++) {
            mas[i] = rand() % (n[j] * 100);
        }
        printf("\nСлучайное заполнение массива размером %d выполнено\n", n[j]);
        time_s = shell(mas, n[j]);
        printf(" Время сортировки методом Шелла: %f\n ", time_s);
        time_q = qs(mas, 0, n[j] - 1);
        printf("Время сортировки методом быстрой сортировки:%f\n ", time_q);
        i = 0;
        while (i < n[j]) {
            mas[i] = i;
            i++;
        }
        printf("\nЗаполнение массива по возрастанию размером %d выполнено\n", n[j]);
        time_s = shell(mas, n[j]);
        printf(" Время сортировки методом Шелла: %f\n ", time_s);
        time_q = qs(mas, 0, n[j] - 1);
        printf("Время сортировки методом быстрой сортировки:%f\n ", time_q);
        i = 0;
        while (i < n[j]) {
            mas[i] = (i - n[j]) * -1;
            i++;
        }
        printf("\nЗаполнение массива по убыванию размером %d выполнено\n", n[j]);
        time_s = shell(mas, n[j]);
        printf("Время сортировки методом Шелла: %f\n ", time_s);
        time_q = qs(mas, 0, n[j] - 1);
        printf("Время сортировки методом быстрой сортировки:%f\n ", time_q);
        i = 0;
        while (i < n[j]) {
            if (i < (n[j] / 2)) {
                mas[i] = i;
            }
            else {
                mas[i] = (i - n[j]) * -1;
            }
            i++;
        }
        printf("\nЗаполнение массива по возрастанию и убыванию размером %d выполнено\n", n[j]);
        time_s = shell(mas, n[j]);
        printf(" Время сортировки методом Шелла: %f\n ", time_s);
        time_q = qs(mas, 0, n[j] - 1);
        printf("Время сортировки методом быстрой сортировки:%f\n ", time_q);
    }

    return 0;
}