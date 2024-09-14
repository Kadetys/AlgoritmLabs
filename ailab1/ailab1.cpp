#include <time.h>
#include <iostream>
#include<locale.h>
#include <omp.h>

int main(void)
{
	setlocale(LC_ALL, "");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r;
	int** a;
	int** b;
	int** c;
	int elem_c = 0;
	int m;
	printf("Введите размер квадратной матрицы \n");
	scanf_s("%d", &m);
	a = (int**)malloc(m * sizeof(int*));
	b = (int**)malloc(m * sizeof(int*));
	c = (int**)malloc(m * sizeof(int*));

	for (i; i < m; i++) {
		a[i] = (int*)malloc(m * sizeof(int));
		b[i] = (int*)malloc(m * sizeof(int));
		c[i] = (int*)malloc(m * sizeof(int));
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < m)
	{
		while (j < m)
		{
			a[i][j] = rand() % 100; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < m)
	{
		while (j < m)
		{
			b[i][j] = rand() % 100; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock();

#pragma omp for num_threads(16) collapse(2)

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			elem_c = 0;
#pragma omp critical
			for (r = 0; r < m; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}

	}
	end = clock();
	printf("%f\n", float(end - start) / float(CLOCKS_PER_SEC));

	return(0);
}
