#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<stdio.h>
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)

{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}
	
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->right = r;
		else root->left = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->right, data);
	else
		CreateTree(r, r->left, data);

	return root;
}

//Функция вывода дерева на экран(дерево выводится повёрнутым на 90 градусов, корень находится слева) :

	void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->left, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->right, l + 1);
}

	int find_tree(struct Node* r, int* orig)
	{
		if (r == NULL)
		{
			return 0;
		}
		int count = 0;
		if (r->data == *orig) 
		{
			count ++;
		}
			count += find_tree(r->right, orig);
			count += find_tree(r->left, orig);
		return count;
	}
//Программа, использующая приведенные функции :

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;

	root = NULL;
	printf("Для завершения заполнения дерева введите значение -1\n");
	while (start)
	{
		int doubly = 0;
		printf("Введите число: ");
		scanf("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
			continue;
		}
		else
			doubly = find_tree(root, &D);
		if (doubly != 0) {
			printf("Этот элемент уже добавлен в дерево!\n");
			continue;
		}
			root = CreateTree(root, root, D);

	}
	print_tree(root, 0);
	int H, find = 1;
	while (find) {
		printf("Хотите начать поиск элемента?\n 0. Нет\n 1. Да\n");
		scanf("%d", &find);
		if (find == 1) {
			int count = 0;
			printf("Введите элемент, который желаете найти\n");
			scanf("%d", &H);
			count = find_tree(root, &H);
			if (count == 0) {
				printf("Элемент не найден\n");
			}
			else {
				printf("Элемент встречается в дереве %d раз(а)\n", count);
			}
		}
	}
	return 0;
}