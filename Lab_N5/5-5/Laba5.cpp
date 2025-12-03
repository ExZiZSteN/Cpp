#include "Laba5.h"
#include <iostream>

void makeFile(const char * fileName)
{
    int N = 10;
    std::ofstream out("numbers.txt");
    srand(time(0));
    for (int i = 0; i < N; i++) {
        int number = rand() % 10 + 1;
        for (int j = 0; j < number % 5; j++){
            int number2 = rand() % 10 + 1;
            out << number2 << " ";
        }
        out << number << "\n";
    }
    out.close();
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
void save(){
    struct Toy t1 = {"Car",30,3,7};
    struct Toy t2 = {"Sword",50,5,10};
    struct Toy t3 = {"Train",40,4,8};
    const char * fileName = "toys.bin";
    FILE * file = fopen(fileName, "wb");
    fwrite(&t1, sizeof(struct Toy),1,file);
    fwrite(&t2, sizeof(struct Toy),1,file);
    fwrite(&t3, sizeof(struct Toy),1,file);
    fclose(file);
}
