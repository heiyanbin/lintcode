/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/lru-cache
@Language: C++
@Datetime: 14-12-10 00:28
*/

#include <list>
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end()) return -1;
        int ret = it->second->second;
        l.splice(l.end(), l, it->second);
        it->second=prev(l.end());
        return ret;
    }
    
    void set(int key, int value) {
        auto it = m.find(key);
        if(it!=m.end()){
            it->second->second = value;
            l.splice(l.end(), l, it->second);
        }else{
            if(l.size()==capacity){
                m.erase(l.front().first);
                l.pop_front();
            }
            l.push_back(make_pair(key, value));
        }
        m[key]=prev(l.end());
    }
private:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int capacity;
};
