#include "City.h"

void City::addRoute(const std::vector<std::map<std::string, double>>& destinations){
    for (const auto& dest : destinations) {
        for (const auto& pair : dest) {
            routes_[pair.first] = pair.second;
        }
    }
};
void City::printRoutes() const {
    std::cout << "Routes from " << name_ << ":\n";
    for (const auto& route : routes_) {
        std::cout << "  To " << route.first << ": " << route.second << "\n";
    }
}