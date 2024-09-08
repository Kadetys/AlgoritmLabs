
#include <iostream>

int main()
{

    int i = 0;
    int m[5];
    while (i < 5) {
        m[i] = i + 1 * i;
        i++;
        }
    for (int j = 0; j < 5; j++) {
        printf("%d \n", m[j]);
    }
}


