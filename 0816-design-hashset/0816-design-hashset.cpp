#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    int n;
    vector<list<int>>vec;
    // vector<bool>vec;
    
    int getIndex(int key){
        return key % n;
    }

    MyHashSet() {
        n = 15000;
        vec = vector<list<int>>(n, list<int>{});
    }
    
    void add(int key) {
        int idx = getIndex(key);

        auto it = find(vec[idx].begin(), vec[idx].end(), key);

        if(it == vec[idx].end()){
            vec[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = getIndex(key);

        auto it = find(vec[idx].begin(), vec[idx].end(), key);

        if(it != vec[idx].end()){
            vec[idx].erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = getIndex(key);

        auto it = find(vec[idx].begin(), vec[idx].end(), key);

        return it != vec[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */