#include <iostream>
#include <map>
using namespace std;

class CacheLine {
public:
    CacheLine *prev;
    CacheLine *next;
    int key;
    int value;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        max_capacity = capacity;
        first = 0;
        last = 0;
    }
    
    int get(int key) {
        map<int,CacheLine*>::iterator itor = cache.find(key);
        if (itor != cache.end()) {
            CacheLine *ptr = itor->second;
            if (ptr != last) {
                // remove the get value from last
                if (ptr->prev != 0)
                    ptr->prev->next = ptr->next;
                if (ptr->next != 0)
                    ptr->next->prev = ptr->prev;
                // move the get value to the last
                if (ptr == first && ptr->next != 0) {
                    first = ptr->next;
                }
                last->next = ptr;
                ptr->prev = last;
                last = ptr;
            }
            return ptr->value;
        } else
            return -1;
    }
    
    void put(int key, int value) {
        map<int,CacheLine*>::iterator itor = cache.find(key);
        if (itor != cache.end()) {
            CacheLine *ptr = itor->second;
            if (ptr != last) {
                // remove the get value from last
                if (ptr->prev != 0)
                    ptr->prev->next = ptr->next;
                if (ptr->next != 0)
                    ptr->next->prev = ptr->prev;
                // move the get value to the last
                if (ptr == first && ptr->next != 0) {
                    first = ptr->next;
                }
                last->next = ptr;
                ptr->prev = last;
                last = ptr;
            }
            ptr->value = value;
        } else {
            if (cache.size() == max_capacity){
                CacheLine *ptr = first;
                first = first->next;
                if (first)
                    first->prev = 0;
                if (last == ptr) // while max_capacity == 1
                    last = 0;
                cache.erase(ptr->key);
                delete ptr;
            }
            CacheLine *ptr = new CacheLine();
            cache[key] = ptr;
            ptr->key = key;
            ptr->value = value;
            ptr->next = 0;
            ptr->prev = last;
            if (last)
                last->next = ptr;
            last = ptr;
            if (first == 0)
                first = ptr;
        }
    }

private:
    map<int,CacheLine *> cache;
    CacheLine *first;
    CacheLine *last;
    int max_capacity;
};

int main() {
#if 0
    LRUCache* obj = new LRUCache(2);
    cout << "put key=1 value=1" << endl;
    obj->put(1, 1);
    cout << "put key=2 value=2" << endl;
    obj->put(2, 2);
    cout << "get key=1 " << "return=" << obj->get(1) << endl;
    cout << "put key=3 value=3" << endl;
    obj->put(3, 3);
    cout << "get key=2 " << "return=" << obj->get(2) << endl;
    cout << "put key=4 value=4" << endl;
    obj->put(4, 4);
    cout << "get key=1 " << "return=" << obj->get(1) << endl;
    cout << "get key=3 " << "return=" << obj->get(3) << endl;
    cout << "get key=4 " << "return=" << obj->get(4) << endl;
#elif 1
    LRUCache* obj = new LRUCache(1);
    cout << "put key=2 value=1" << endl;
    obj->put(2, 1);
    cout << "get key=2 " << "return=" << obj->get(2) << endl;
    cout << "put key=3 value=2" << endl;
    obj->put(3, 2);
    cout << "get key=2 " << "return=" << obj->get(2) << endl;
    cout << "get key=3 " << "return=" << obj->get(3) << endl;
#endif
    delete obj;
    return 0;
}