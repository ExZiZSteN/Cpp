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

int findMaxRowProizv(const Matrix&M, int N){
    int maxRow;
    int maxRowProizv;
    for (int i = 0; i < N; i++){
        int Row {i+1};
        int rowProizv {1};
        for (int j = 0; j < N; j ++){
            rowProizv *= M[i][j];
        }
        if (rowProizv > maxRowProizv){
            maxRowProizv = rowProizv;
            maxRow = Row;
        }
    }
    return maxRow;
}

void printMatrix(const Matrix&M, int N){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j ++){
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
