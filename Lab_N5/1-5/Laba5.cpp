#include "Laba5.h"
#include <iostream>


void makeFile(int& N, const char * fileName)
{
    srand(time(0));
    FILE * file = fopen(fileName, "wb");
    for (int i = 0; i < N; i++){
        int number = rand() % 10;
        fwrite(&number, sizeof(int), 1, file);
    }
    fclose(file);
}