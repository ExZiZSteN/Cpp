#include "City.h"


int main(){
    City A("A");
    City B("B");
    City C("C");
    City D("D");
    City E("E");
    City F("F");
    
    A.addRoute(std::vector<std::map<std::string, double>>{{{"B", 5}, {"D", 6},{"F",1}}});
    B.addRoute(std::vector<std::map<std::string, double>>{{{"A", 5}, {"C", 3}}});
    C.addRoute(std::vector<std::map<std::string, double>>{{{"B", 3}, {"D", 4}}});
    D.addRoute(std::vector<std::map<std::string, double>>{{{"E", 2}, {"C", 4},{"A",6}}});
    E.addRoute(std::vector<std::map<std::string, double>>{{{"F", 1}}});
    F.addRoute(std::vector<std::map<std::string, double>>{{{"E", 2}, {"B", 1}}});
    A.printRoutes();
    B.printRoutes();
    C.printRoutes();
    D.printRoutes();
    E.printRoutes();
    F.printRoutes();
}