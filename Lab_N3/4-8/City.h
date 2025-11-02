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
        City(std::string name){
            name_ = name;
        };
        City(std::string name, std::vector<std::map<std::string,double>> routes ){
            name_ = name;
            this -> addRoute(routes);
        };
        void addRoute(const std::vector<std::map<std::string, double>>& destinations);
        void printRoutes() const;
};