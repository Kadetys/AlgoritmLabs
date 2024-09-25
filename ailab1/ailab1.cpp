#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<stdio.h>
struct node
{
	char inf[256];  // полезная информация
	int prioryty;
	struct node* next; // ссылка на следующий элемент 
};

//Обращение к списку и его элементам осуществляется посредством указателей :

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

//Для списка реализованы функции создания, добавления, удаления элемента, просмотра списка, нахождения нужного элемента списка :

// Функции добавления элемента, просмотра списка
void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента



struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		last->next = p;
		last = p;
	}
	return;
}


/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}




/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			printf("Элемент  найден!\n");
			printf("Элемент: %s\n", struc->inf);
			return struc;
		}
		struc = struc->next;

	}
	printf("Элемент не найден\n");
	return NULL;

}
/* Удаление элемента по содержимому. */
void del(char* name) {
	struct node* struc = head;
	struct node* prev = NULL;
	int found = 0;

	if (head == NULL) {
		printf("Список пуст\n");
		return;
	}

	// Проход по списку для поиска и удаления всех совпадающих элементов
	while (struc) {
		if (strcmp(name, struc->inf) == 0) {
			found = 1;  // Элемент найден

			// Удаление первого элемента
			if (prev == NULL) {
				head = struc->next;
				free(struc);
				struc = head;  // обновляем текущий узел после удаления головы
			}
			else {  // Удаление элемента не в начале списка
				prev->next = struc->next;
				free(struc);
				struc = prev->next;  // обновляем текущий узел
			}

			printf("Элемент удален\n");
		}
		else {
			prev = struc;  // Обновляем предыдущий элемент
			struc = struc->next;  // Переходим к следующему элементу
		}
	}

	if (!found) {
		printf("Элемент не найден\n");
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	char s[10];
	int c = 0;
	do {
		printf("\nМеню:\n");
		printf("1. Добавить элемент\n");
		printf("2. Просмотреть список\n");
		printf("3. Удалить элемент\n");
		printf("4. Поиск элемента\n");
		printf("5. Выход\n");
		printf("Выберите один из пунктов: ");
		scanf_s("%d", &c);

		switch (c) {
		case 1:
			spstore();
			break;
		case 2:

			review();
			break;

		case 3:
			printf("Введите название объекта для удаления: ");
			scanf_s("%s", s, (unsigned)_countof(s));
			del(s);
			break;
		case 4:
			printf("Введите элемент для поиска: ");
			scanf_s("%s", s, (unsigned)_countof(s));
			*find(s);
			break;

		case 5:
			printf("Выход...\n");
			break;
		default:
			printf("Ошибка. Попробуйте снова.\n");
			break;
		}
	} while (c != 5);

	return 0;
}
