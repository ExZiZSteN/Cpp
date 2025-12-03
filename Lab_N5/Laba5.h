#pragma once
#include <cmath>
#include <iostream>

void makeFile(int& N)
{
    srand(time(0));
    const char * fileName = "numbers.bin";
    FILE * file = fopen(fileName, "wb");
    for (int i = 0; i < N; i++){
        int number = rand() % 10;
        fwrite(&number, sizeof(int), 1, file);
    }
    fclose(file);
}
