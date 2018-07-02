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


void printInorder(Node* n) {
    if(!n) return;
    printInorder(n->left);
    cout << n->val << " ";
    printInorder(n->right);
}


/*
 * Complete the function below.
 */
void print_arr(vector<int> path) {
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
 	}
	cout << endl;
}

void printPaths(Node* node, vector<int>& path) {
	if (! node) return;
	path.push_back(node->val);
	if (! node->left && ! node->right) {
		// both left and right child are null
		print_arr(path);
		//path.pop_back();
	}
	else {
		printPaths(node->left, path);
		//path.pop_back();
		printPaths(node->right, path);
		//path.pop_back();
	}
	path.pop_back();
}


void printAllPaths(Node* root) {
	vector<int> path;
	printPaths(root, path);
	//print_arr(path);
}



int main() {
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str;
    getline(cin, _str);
    
    Node* root = createTree(_str);
	//printInorder(root);
    printAllPaths(root);
    
    return 0;
}