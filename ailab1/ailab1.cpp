
#include <iostream>
#include <time.h>

int main()
{

    int i = 0;
    int m[5];
    srand(time(0));
    while (i < 5) {
        m[i] = rand() % 100;
        i++;
    }
    for (int j = 0; j < 5; j++) {
        printf("%d \n", m[j]);
    }
}


