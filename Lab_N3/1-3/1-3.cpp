#include "Name.h"
#include <limits>
#include <sstream>
#include <vector>

bool isCorrect(std::string&  part , bool& flag){
    for (auto i : part){
        if (i < 'A' || (i > 'Z' && i < 'a') || i > 'z'){
            flag = false;
            break;            
        }        
    }
    return flag;
}



int main(){
    std::vector<std::string> fullName {"", "", ""};
    std::string input {};
    std::string lastName {}, fisrtName {}, middleName {};
    std::cout << "Enter name:" << std::endl;
    std::getline(std::cin,input);
    std::stringstream ss(input);
    std::string part {};
    int i = 0;
    while (ss >> part){
        bool flag = true;

        isCorrect(part, flag);

        while (!flag) {
            std::cout << "Invalid input. Input valid value: ";
            std::cin >> part;

            flag = true;
            isCorrect(part, flag);
        }     
        fullName[i] = part;
        i++;
    }
    if (i == 0){
        std::cout << "Atleast first name should be given." << std::endl;
        std::cout << "Enter name:" << std::endl;
        while (true){
            if (std::cin >> part){
                break;
            }
            else{
                std::cout << "Invalid input. Input valid value: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }
        Name name("", part, "");
        name.printName();
    }
    if (i == 1){
        fisrtName = fullName[0];
        Name name("", fisrtName, "");
        name.printName();
    }
    else if (i == 2){
        fisrtName = fullName[1];
        lastName = fullName[0];
        Name name(lastName, fisrtName, "");
        name.printName();
    }
    else if (i == 3){
        lastName = fullName[0];
        fisrtName = fullName[1];
        middleName = fullName[2];
        Name name(lastName, fisrtName, middleName);
        name.printName();
    }

}
