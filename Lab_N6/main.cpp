#include "HashSet.h"
#include "Dictionary.h"
#include "Point.h"
#include <clocale>
#include <fstream>
#include <limits>


void check(int& n){
    while (true){
        if (std::cin >> n){
            break;
        }
        else{
            std::cout << "Invalid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
}

void zadanie1()
{   
    int n;
    std::cout << "Enter number of viewers: ";
    std::vector<HashSet<std::string>> viewers;
    check(n);
    for (int i{0}; i < n; i++){
        int j;
        std::cout<< "Enter number of films that viewer " << i+1 << " watched: ";
        check(j);
        HashSet<std::string> person;
        for (int k {0}; k < j; k++){
            std::string film;
            std::cout << "Enter " << k+1 << "film: ";
            std::getline(std::cin >> std::ws,film);
            person.insert(film);
        }
        viewers.push_back(person);
    }

    // person1.insert("Texas Cowboy");
    // person1.insert("Texas Cowboy 2");
    // person1.insert("Texas Cowboy 3");
    // person1.insert("Star wars");
    // person2.insert("Texas Cowboy");
    // person2.insert("Star wars");
    // person3.insert("Star wars");
    HashSet<std::string>allMovies;
    for (const HashSet<std::string>& person : viewers){
        allMovies = allMovies.Union(person);
    }
    HashSet<std::string>allWatched = viewers[0];
    for (size_t i {1}; i < viewers.size(); i++){
        allWatched = allWatched.Intersect(viewers[i]);
    }
    std::cout << "Films that watched by all:" << std::endl;
    std::cout << allWatched << std::endl;
    HashSet<std::string>someWatched = allMovies.Except(allWatched);
    std::cout << "Films that watched by someone:" << std::endl;
    std::cout << someWatched << std::endl;
}



void zadanie2()
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::ifstream file("workers.txt");
    std::string surname, initials, phone;
    Dictionary<std::string,std::vector<std::string>> departments;
    
    while (file >> surname >> initials >> phone){
        std::string department = phone.substr(0,6);

        departments.insert(department,surname + " " + initials);
        departments.insert(department,phone);
    }
    std::cout << departments;
}

Point3D makePoint3D()
{
    std::cout << "Введите координаты точки (x,y,z через пробел):" << std::endl;
    double x,y,z;
    while (true){
        if (std::cin >> x >> y >> z){
            break;
        }
        else{
            std::cout << "Некорректный ввод!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    Point3D p(x,y,z);
    return p;
}

void zadanie3()
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::cout << "Создайте первую точку" << std::endl;
    Point3D p1 = makePoint3D();
    std::cout << "Создайте вторую точку" << std::endl;
    Point3D p2 = makePoint3D();
    std::cout << "Расстояние между этими точками: " << p1.distance(p2); 
}


int main()
{
    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::cout << "1 Задание" << std::endl;
    zadanie1();
    std::cout << std::endl << "2 Задание" << std::endl;
    zadanie2();
    std::cout << std::endl << "3 Задание" << std::endl;
    zadanie3();
}