#include <iostream>
#include <vector>
#include <map>
#include <limits>

void makeFile(int& N)
{
    srand(time(0));
    const char * fileName = "numbers.bin";
    FILE * file = fopen(fileName, "wb");
    //fwrtie(2,sizeof(int),1,file)
    //fwrtie(2,sizeof(int),1,file)
    //fwrtie(4,sizeof(int),1,file)
    //fwrtie(5,sizeof(int),1,file)
    //fwrtie(1,sizeof(int),1,file)
    for (int i = 0; i < N; i++){
        int number = rand() % 10;
        fwrite(&number, sizeof(int), 1, file);
    }
    fclose(file);
}


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
    makeFile(N);

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