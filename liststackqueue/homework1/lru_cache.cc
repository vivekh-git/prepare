#include <bits/stdc++.h>

using namespace std;

struct node {
    int key;
    int value;
    node(int k, int v) : key(k), value(v) {}
};

class LRUCache {
private:
    int _capacity;
    unordered_map<int, deque<node*>::iterator> _dict;
    deque<node*> _lru;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
	// if size is at capacity, remove oldest item from list and delete it from hash
    void put(int k, int v) {
		if (_lru.size() == _capacity) {
			node* n = _lru.back();
			_lru.pop_back();
			_dict.erase(n->key);
			delete n; n = NULL;
		}
        node* n = new node(k, v);
		_lru.push_front(n);
        _dict[k] = _lru.begin();
	}

	// element accessed need to be removed from current position and moved to first position
    int get(int k) {
        if (_dict.count(k) == 0)
            return -1;
        deque<node*>::iterator it = _dict[k];
		// *it is the actual node
		int result = it->value;
		node* n = new node(it->key, it->value);
		_lru.erase(it);
		_lru.push_front(n);
		_dict[k] = _lru.begin();
        return result;
	}

};

vector<int> implement_LRU_cache(int capacity, vector<int>& query_type, vector<int>& key, vector<int>& value) {
    LRUCache cache(capacity);
    vector<int> result;
    for (int i = 0; i < query_type.size(); i++) {
        if (query_type[i] == 1) { // set
            cache.put(key[i], value[i]);
        }
        else {
            result.push_back(cache.get(key[i]));
        }
    }
    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector <int> res;
    int capacity;
    cin >> capacity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int query_type_size = 0;
    cin >> query_type_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> query_type;
    for(int i = 0; i < query_type_size; i++) {
        int query_type_item;
        cin >> query_type_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        query_type.push_back(query_type_item);
    }

    int key_size = 0;
    cin >> key_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> key;
    for(int i = 0; i < key_size; i++) {
        int key_item;
        cin >> key_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        key.push_back(key_item);
    }

    int value_size = 0;
    cin >> value_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> value;
    for(int i = 0; i < value_size; i++) {
        int value_item;
        cin >> value_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        value.push_back(value_item);
    }

    res = implement_LRU_cache(capacity, query_type, key, value);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    fout.close();
    return 0;
}

/*
q - 1 1 0 1 0 1 0

k - 5 10 5 15 10 5 5

v - 11 22 1 33 1 55 1

11 22 55 
*/
