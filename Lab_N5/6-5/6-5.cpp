#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool hasDigit(const std::string& s) {
    for (char c : s) {
        if (std::isdigit((unsigned char)c))
            return true;
    }
    return false;
}

int main() {
    std::ifstream in("text.txt");
    std::ofstream out("res.txt");

    std::string line;
    while (std::getline(in, line)) {
        if (!hasDigit(line)) {
            out << line << "\n"; 
        }
    }

    std::cout << "Done" << std::endl;

    return 0;
}
