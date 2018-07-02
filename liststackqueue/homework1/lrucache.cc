#include <list>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

struct node {
   string key;
   int value;
   node(string k, int v): key(k), value(v) {}
};

const int CACHE_SIZE = 5;
class LRUCache {
private:
	unordered_map<string, list<node *>::iterator> _cache;
	list<node *> _lru;
public:
    void printTable() {
   		cout << "printing table" << endl;
   		for (unordered_map<string, list<node*>::iterator>::iterator it = _cache.begin(); it!= _cache.end(); it++) {
			node* n = *it->second;
   			cout << "k: v - " << it->first << ": " << n->value << endl;
   		}
   }
   
   void printList() {
   		cout << "printing list" << endl;
   		for (list<node*>::iterator it = _lru.begin(); it != _lru.end(); it++) {
   			node* n = *it;
   			cout << n->key << " - " << n->value << ", ";
   		}
   		cout << endl;
   }
	
    void put(string k, int v) {
		if (_lru.size() >= CACHE_SIZE) {
			// lru full - delete last used from lru and map
			list<node *>::reverse_iterator last = _lru.rbegin();
			node* n = *last;
			string lastkey = n->key;
			_cache.erase(lastkey);
			_lru.pop_back();
			delete n; n = NULL;
		}
	    // add to cache and lru
		node* element = new node(k, v);
		_lru.push_front(element);
		_cache[k] = _lru.begin();
	}

    int get(string k) {
		if (_cache.count(k) != 0) {
			// element exists in map
			list<node*>::iterator it = _cache[k]; // *it is  node *
			int ret = (*it)->value;
			// move the node to the front of _lru list
			_lru.push_front(*it);
			_lru.erase(it);
			return ret;
		}
		else {
			return -1;
		}
	}

};


int main() {
   LRUCache c;
   c.put("k1", 1);
   c.put("k2", 2);
   c.put("k3", 3);
   c.put("k4", 4);
   c.put("k5", 5);
   c.printTable(); c.printList();
   c.put("k6", 6);
   c.printTable(); c.printList();
   c.put("k7", 7);
   c.printTable(); c.printList();
   return 0;
}