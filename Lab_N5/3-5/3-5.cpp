#include <limits>
#include "Laba5.h"


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