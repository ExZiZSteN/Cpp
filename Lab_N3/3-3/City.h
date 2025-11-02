#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>

class City{
    private:
        std::string name_ {};
        std::map<std::string, double> routes_ {};
    public:
        City(const std::string& name){
            name_ = name;
        };
        void addRoute(const std::vector<std::map<std::string, double>>& destinations);
        void printRoutes() const;
};