#ifndef soluition_h
#define soluition_h
#include <deque>
#include <list>

std::list<int>::iterator fifth_from_end(std::list<int>& lst);

std::deque<int> last_five_from_end(std::deque<int>& deq);

#endif