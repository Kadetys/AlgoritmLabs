
#include <iostream>
#include<locale.h>  

struct students {
    char family[20];
    char name[20];
    char faculty[20];
    int number;
}stud[3];
#pragma warning(disable: 4996)

int main()
{
    setlocale(LC_ALL, "rus");
    struct students s1;
    int count;
    int search;
    char search_char[20];
    int search_number;
    int k = 0;
    printf("Введите количество студентов\n");
    scanf_s("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Введите фамилию студента %d\n", i + 1);
        scanf("%s", stud[i].family);
        rewind(stdin);
        printf("Введите имя студента %d\n", i + 1);
        scanf("%s", stud[i].name);
        rewind(stdin);
        printf("Введите факультет студента %d\n", i + 1);
        scanf("%s", stud[i].faculty);
        rewind(stdin);
        printf("Введите номер зачётки студента %d\n", i + 1);
        scanf("%d", &stud[i].number);
        rewind(stdin);
    }
    while (1) {
        printf("Выберите тип данных, по которому хотите найти студента:\n 1: Фамилия\n 2: Имя\n 3: Факультет\n 4: Номер зачетной книжки\n");
        scanf("%d", &search);
        switch (search) {
        case 1:
            printf("Введите фамилию студента\n");
            scanf("%20s", search_char);
            printf("Студенты, подходящте под заданные данные:\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(stud[i].family, search_char) == 0) {
                    printf("%s %s %s %d\n", stud[i].family, stud[i].name, stud[i].faculty, stud[i].number);
                    k++;
                }
            }
            if (k == 0) {
                printf("Ни одного студента не найдено\n");
            }
            break;
        case 2:
            printf("Введите имя студента\n");
            scanf("%20s", search_char);
            printf("Студенты, подходящте под заданные данные:\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(stud[i].name, search_char) == 0) {
                    printf("%s %s %s %d\n", stud[i].family, stud[i].name, stud[i].faculty, stud[i].number);
                    k++;
                }
            }
            if (k == 0) {
                ("Ни одного студента не найдено\n");
            }

            break;
        case 3:
            printf("Введите факультет студента\n");
            scanf("%20s", search_char);
            printf("Студенты, подходящте под заданные данные:\n");
            for (int i = 0; i < count; i++) {
                if (strcmp(stud[i].faculty, search_char) == 0) {
                    printf("%s %s %s %d\n", stud[i].family, stud[i].name, stud[i].faculty, stud[i].number);
                    k++;
                }
            }
            if (k == 0) {
                printf("Ни одного студента не найдено\n");
            }
            break;
        case 4:
            printf("Введите номер зачетки студента\n");
            scanf("%d", &search_number);
            printf("Студенты, подходящте под заданные данные:\n");
            for (int i = 0; i < count; i++) {
                if (stud[i].number == search_number) {
                    printf(" %s %s %s %d\n", stud[i].family, stud[i].name, stud[i].faculty, stud[i].number);
                    k++;
                }
            }
            if (k == 0) {
                printf("Ни одного студента не найдено\n");
            }
            break;

        default:
            printf("Ошибка, выберите один из представленых пунктов");
            break;
        }
        if (search > 0 and search < 5) {
            break;
        }
    }
            return 0;
            }

        
