#include <iostream>
#include <list>
#include <algorithm>


int main(){
    std::list<int> lst {-1,-2,-3,4,5,10};
    auto negative = std::find_if(lst.begin(), lst.end(), [](int x){ return x < 0;});
    lst.insert(negative, 0);
    auto positive = std::find_if(lst.rbegin(), lst.rend(), [](int x){ return x > 0;});
    lst.insert((++positive).base(), 0);
    std::cout << "After inserting 0 before first negativ element the list is: " << std::endl;
    for (const auto& item : lst){
        std:: cout << item << " ";
    }
}