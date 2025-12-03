#include <limits>
#include "Laba5.h"

int main()
{
    int N ;
    std::cout << "Enter number of integers to generate: ";
    while (true)
    {
        if (std::cin >> N && N > 0){
            break;
        }
        else{
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    makeFile(N,"numbers.bin");
    int N2 = std::sqrt(N);
    if (N2 * N2 != N){
        N2 += 1;
    }
    Matrix M(N2, std::vector<int>(N2,0));
    FILE * file = fopen("numbers.bin","rb");
    for (int i = 0; i < N2; i++){
        for (int j = 0; j < N2; j++){
            int number;
            if (fread(&number, sizeof(int),1, file) == 1){
                M[i][j] = number;
            }
        }
    }
    fclose(file);
    std::cout << "Matrix:" << std::endl;
    printMatrix(M,N2);
    int maxRow = findMaxRowProizv(M, N2);
    std::cout << "Row with max product: " << maxRow << std::endl;
    for (int i = 0; i < N2; i ++){
        for (int j = 0; j < N2; j++){
            M[i][j] = M[maxRow-1][j];
        }
    }
    std::cout << "Modified matrix:" << std::endl;
    printMatrix(M,N2);
}