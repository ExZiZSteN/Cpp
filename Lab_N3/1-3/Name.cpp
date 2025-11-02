#include "Name.h"

void Name::printName(){
    if (!(lastName_.empty()) && !(firstName_.empty()) && !(middleName_.empty())){
        std::cout << "Name is: " << lastName_ << " " << firstName_ << " " << middleName_ << std::endl;
    }
    else if (lastName_ == "" &&  !(firstName_.empty()) && !(middleName_.empty())){
        std::cout << "Name is: "<< firstName_ << " " << middleName_ << std::endl;
    }
    else if (lastName_ == "" && middleName_ == "" && !(firstName_.empty())){
        std::cout << "Name is: " << firstName_ << std::endl;
    }
    else if (!(lastName_.empty()) && !(firstName_.empty()) && middleName_ == ""){
        std::cout << "Name is: " << lastName_ << " " << firstName_ << std::endl;
    }
}