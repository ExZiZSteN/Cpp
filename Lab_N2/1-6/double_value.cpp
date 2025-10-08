#include "double_value.h"

void Double(vector<int>& arr){
    vector<int>::iterator it = arr.begin();
    *it *= 2;
    it = arr.begin() + arr.size() / 2;
    *it *= 2;
    it = arr.end() - 1;
    *it *= 2;

}

void Double(deque<int>& arr){
    deque<int>::iterator it = arr.begin();
    *it *= 2;
    it = arr.begin() + arr.size() / 2;
    *it *= 2;
    it = arr.end() - 1;
    *it *= 2;

}

void Double(list<int>& arr){
    
    list<int>::iterator it = arr.begin();
    *it *= 2;
    advance(it, arr.size() / 2);
    *it *= 2;
    it = arr.end();
    --it;
    *it *= 2;
}