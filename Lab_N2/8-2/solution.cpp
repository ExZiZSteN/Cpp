#include "solution.h"

struct MakePair
{
    std::string operator()(const std::string& right, const std::string& left) const
    {
    
        return std::string(1, left.front()) + right.back();
    }
};


std::deque<std::string> solution(std::list<std::string> list){
    std::deque<std::string> res {};
    std::adjacent_difference(list.begin(),list.end(),std::inserter(res,res.begin()),MakePair());
    res.erase(res.begin());
    return res;
}