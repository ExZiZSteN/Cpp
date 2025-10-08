#include "solution.h"

std::list<int>::iterator fifth_from_end(std::list<int>& lst){
    std::list<int>::iterator it = lst.end();
    for (int i {0}; i < 5; ++i){
        --it;
    }
    return it;
}

std::deque<int> last_five_from_end(std::deque<int>& deq){
    std:: deque<int> result;
    auto it = deq.end();
    for (int i {0}; i < 5; ++i){
        --it;
        result.push_back(*it);
    }
    return result;
}