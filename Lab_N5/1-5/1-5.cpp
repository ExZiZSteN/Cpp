#include <vector>
#include <map>
#include <limits>
#include "Laba5.h"

int main()
{

    int N;
    std::cout << "Enter number of integers to generate: ";
    while (true)
    {
        if (std::cin >> N && N > 0){
            break;
        } else{
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    makeFile(N,"numbers.bin");

    FILE * file = fopen("numbers.bin","rb");
    std::vector<int> numbers;
    for (int i = 0; i < N; i++){
        int number;
        if (fread(&number, sizeof(int), 1, file) == 1){
            numbers.push_back(number);
        };
    }

    fclose(file);
    std::cout << "Generated numbers:" << std::endl;
    for (const auto& num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::map<int,int> seen;
    const char * outputFileName = "result.txt";
    FILE * outputFile = fopen(outputFileName, "wr");
    for (auto& num : numbers){
        seen[num]++;
        if (seen[num] == 1){
            std::cout << num << " ";
            fwrite(&num, sizeof(int), 1, outputFile);
        }
    }
    std::cout << std::endl;
    std::cout << "Unique numbers: " << std::endl;
    for (int i = 0; i < N; i++){
        int number;
        if (fread(&number, sizeof(int), 1, outputFile) == 1){
            std::cout << number << " ";
        };
    }
    fclose(outputFile);
}