#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTICES 100
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void readGraphFromFile(const char* filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        exit(1);
    }
    inputFile >> numVertices;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            inputFile >> graph[i][j];
        }
    }
    inputFile.close();
}
void generateRandomGraph(int numVertices, std::ofstream& graphFile) {
    srand(time(0));
    ::numVertices = numVertices;
    graphFile << numVertices << std::endl; 
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = rand() % 2;
                graph[j][i] = graph[i][j];
            }
            graphFile << graph[i][j] << (j == numVertices - 1 ? "" : " ");
        }
        graphFile << std::endl;
    }
}
void findIndependentSets(int subset[], int index, int count, std::ofstream& outputFile) {
    if (index == numVertices) {
        bool independent = true;
        for (int i = 0; i < count; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (graph[subset[i]][subset[j]] == 1) {
                    independent = false;
                    break;
                }
            }
            if (!independent) break;
        }
        if (independent) {
            for (int i = 0; i < count; ++i) {
                printf("%d ", subset[i]);
            }
            printf("\n");

            for (int i = 0; i < count; ++i) {
                outputFile << subset[i] << (i == count - 1 ? "" : " ");
            }
            outputFile << std::endl;
        }
        return;
    }
    subset[count] = index;
    findIndependentSets(subset, index + 1, count + 1, outputFile);
    findIndependentSets(subset, index + 1, count, outputFile);
}
int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    char filename[100], outputFilename[100], graphFilename[100];
    int subset[MAX_VERTICES];
    std::ofstream outputFile, graphFile;
    printf("Выберите режим работы:\n");
    printf("1. Считать граф из файла\n");
    printf("2. Сгенерировать случайный граф\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Введите имя файла: ");
        scanf("%s", filename);
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return 1;
        }
        inputFile >> numVertices;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                inputFile >> graph[i][j];
            }
        }
        inputFile.close();
    }
    else if (choice == 2) {
        printf("Введите количество вершин: ");
        scanf("%d", &numVertices);
        printf("Введите имя файла для сохранения графа: ");
        scanf("%s", graphFilename);
        graphFile.open(graphFilename);
        if (!graphFile.is_open()) {
            std::cerr << "Ошибка! Не удалось открыть файл для записи графа: " << graphFilename << std::endl;
            return 1;
        }
        generateRandomGraph(numVertices, graphFile);
        graphFile.close();
    }
    else {
        std::cerr << "Неверный выбор режима работы." << std::endl;
        return 1;
    }
    printf("Введите имя файла для вывода независимых множеств: ");
    scanf("%s", outputFilename);

    outputFile.open(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка! Не удалось открыть файл для записи независимых множеств: " << outputFilename << std::endl;
        return 1;
    }
    printf("Независимые множества:\n");
    findIndependentSets(subset, 0, 0, outputFile);
    outputFile.close();
    return 0;
}
