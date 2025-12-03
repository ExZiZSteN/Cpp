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

void save(int N){
    std::vector<struct Toy> toys;
    for (int i = 0; i < N; i++){
        std::cout << "Enter toy " << i + 1 << " details (name, price, minAge, maxAge)" << std::endl;
        struct Toy t;
        std::string name;
        std::cin >> t.name;
        int price;
        std::cin >> t.price;
        int minAge;
        std::cin >> t.minAge;
        int maxAge;
        std::cin >> t.maxAge;
        toys.push_back(t);
    }
    // struct Toy t1 = {"Car",30,3,7};
    // struct Toy t2 = {"Sword",50,5,10};
    // struct Toy t3 = {"Train",40,4,8};
    const char * fileName = "toys.bin";
    FILE * file = fopen(fileName, "wb");
    for (const auto& toy : toys){
        fwrite(&toy, sizeof(struct Toy),1,file);
    }
    fclose(file);
}
