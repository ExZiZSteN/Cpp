#include <iostream>
#include <limits>

struct Toy{
    char name[50];
    int price;
    int minAge;
    int maxAge;
};

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

int main()
{
    save();
    int k;
    std::cout << "Enter maximum price: ";
    while (true){
        if (std::cin >> k && k > 0){
            break;
        }
        else{
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    FILE * file = fopen("toys.bin","rb");
    struct Toy t;
    std::cout << "You can buy following toys:" << std::endl;
    while (fread(&t,sizeof(struct Toy),1,file) == 1){
        if (t.price <= k && 5 >= t.minAge && t.maxAge >= 5 ){
            std::cout << t.name << ", Price: " << t.price << std::endl;;
        }
    }
    fclose(file);
}