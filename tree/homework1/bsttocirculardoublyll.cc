#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(nullptr), right(nullptr) {}
};


Node* deserialize(istringstream& in) {
		if(in.eof()) return nullptr;

        string val;
        in >> val;

        if(val.empty()) return nullptr;

        if (val == "#")
            return nullptr;

        Node* root = new Node(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
}

Node* createTree(string data) {
	if(data.empty()) return nullptr;
    istringstream in(data);
    return deserialize(in);
}




/*
 * Complete the function below.
 */
// join 2 nodes
// append 2 lists
// recurse function
// join 2 nodes to point to each other as in doubly linked list
void join(Node* a, Node* b) {
	a->right = b;
	b->left = a;
}

// append 2 circular linked list
Node* append(Node* a, Node* b) {
	if (!a) return b;
	if (!b) return a;
	Node* aLast = a->left;
	Node* bLast = b->left;
	join(aLast, b);
	join(bLast, a);
	return a;
}

void printCircularList(Node* head) {
	Node* curr = head;
	while (curr) {
		cout << curr->val << " ";
		curr = curr->right;
		if (curr == head) break;
	}
	cout << endl;
}

Node* _BSTtoLL(Node* root) {
	if (!root) return NULL;
	Node* aList = _BSTtoLL(root->left);
	Node* bList = _BSTtoLL(root->right);
	root->left = root;
	root->right = root;
	aList = append(aList, root);
	aList = append(aList, bList);
	//printCircularList(aList);
    return aList;
}


void BSTtoLL(Node* root) {
    Node* list = _BSTtoLL(root);
	printCircularList(list);
}




int main() {
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str;
    getline(cin, _str);
    
    Node* root = createTree(_str);
    BSTtoLL(root);
    
    return 0;
}