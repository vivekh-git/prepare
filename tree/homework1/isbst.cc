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
#include <algorithm>

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


bool isBSTUtil(Node* node, Node* & prev) { // prev pointer passed by reference
	if (! node) return true;
	if (! isBSTUtil(node->left, prev))
		return false;
	if (prev && node->val <= prev->val)  // <= allows only distinct values
		return false;
	prev = node;
	return isBSTUtil(node->right, prev);
}


bool isBST(Node *root) {
	//cout << "isBST" << endl;
	Node* nullnode = NULL;
	return isBSTUtil(root, nullnode);
}

//  min. >= node >= max      min              max
bool isBSTUtil2(Node* node, Node* l = NULL, Node* r = NULL) {
	if (!node) return true;
	if (l && node->val <= l->val) // <= allows no dups
		return false;
	if (r && node->val >= r->val) // >= allows no dups
		return false;
	return isBSTUtil2(node->left, l, node) &&
		isBSTUtil2(node->right, node, r);
}


bool isBST2(Node* root) {
	return isBSTUtil2(root, NULL, NULL);
}




void printTree(Node* root) {
	if (!root) return;
	else {
		cout << root->val <<  " - ";
		printTree(root->left);		
		printTree(root->right);
	}	
}


int main() {
    
    int _str_size = 0;
    cin >> _str_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _str;
    string _str_item;
    getline(cin, _str_item);
    
    Node* root = createTree(_str_item);
    printTree(root); cout << endl;
	printTree(root); cout << endl;
	//bool flag = isBST(root);
	bool flag = isBST2(root);
	cout << "flag = " << flag << endl;
    
    return 0;
}