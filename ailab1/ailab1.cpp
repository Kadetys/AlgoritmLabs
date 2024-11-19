
#include <locale.h>
#include <iostream>
#include <cstdlib> // для rand()

using namespace std;

// Функция для генерации матрицы смежности
int** GenMat(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    return matrix;
}

// Функция для вывода матрицы на экран
void PrintMat(int** matrix, int n) { // добавлена n для корректного вывода
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    int n1, n2;

    cout << "Введите количество вершин для графа G1: ";
    cin >> n1;
    cout << "Введите количество вершин для графа G2: ";
    cin >> n2;

    if (n1 <= 0 || n2 <= 0) {
        cout << "Количество вершин должно быть больше 0." << endl;
        return 1;
    }

    int** Mat1 = GenMat(n1);
    int** Mat2 = GenMat(n2);

    cout << "Матрица смежности G1:" << endl;
    PrintMat(Mat1, n1); // передаем размер матрицы

    cout << "\nМатрица смежности G2:" << endl;
    PrintMat(Mat2, n2); // передаем размер матрицы

    // Обязательно освобождаем память!
    for (int i = 0; i < n1; i++) {
        delete[] Mat1[i];
    }
    delete[] Mat1;

    for (int i = 0; i < n2; i++) {
        delete[] Mat2[i];
    }
    delete[] Mat2;

    return 0;
}