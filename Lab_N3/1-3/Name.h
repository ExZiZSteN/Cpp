#ifndef Name_h
#define Name_h
#include <iostream>


class Name{
    private:
        std::string lastName_ {};
        std::string firstName_ {};
        std::string middleName_ {};
    public:
        Name(std::string lastName = "", std::string firstName = "", std::string middleName = "")
        {
            lastName_ = lastName;
            firstName_ = firstName;
            middleName_ = middleName;
        };
        void printName();
};


#endif