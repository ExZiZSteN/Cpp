#include "solution.h"


void combineList(std::list<int>& lst1, std::list<int>& lst2){
    int len = lst1.size();
    std::list<int>::iterator it1 = lst1.begin();
    std::list<int>::iterator it2 = lst2.begin();

    for (int i = 0; i < len; i++){
        lst2.splice(it2, lst1,it1);
        it1 = lst1.begin();
        ++it2;
    }
}