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
bool findPath(Node* node, vector<Node *>& path, int n) {
	// take care of root null
	if (! node) return false;
	// take care of node
	path.push_back(node);
	if (node->val == n) return true;
	
	if (findPath(node->left, path, n) || findPath(node->right, path, n)) 
		return true;
	
	// backtrack and pop from array and return false
	path.pop_back();
	return false;
}



Node* findLCA2(Node* root, int n1, int n2) {
	vector<Node *> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
		return NULL;
	int i = 0;
	for (i = 0; i < path1.size() && i < path2.size(); i++) {
		// path[i] is node * - can compare addresses
		if (path1[i] != path2[i]) 
			break;
	}
	return path1[i-1];
}

// Second approach - recursively finding in one parse
Node* findLCA(Node* root, int n1, int n2) {
	// take care of root null
	if (!root) return NULL;
	// take care of node
	// if root matches with n1 or n2, return root as that could be the LCA
	if (root->val == n1 || root->val == n2)
		return root;
	Node* left_lca = findLCA(root->left, n1, n2);
	Node* right_lca = findLCA(root->right, n1, n2);
	
	// if both left and right exits - then root is the LCA
	if (left_lca && right_lca) return root;
	else return (left_lca ? left_lca : right_lca);
}


int main() {
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str;
    getline(cin, _str);
    
    int _n1;
    cin >> _n1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _n2;
    cin >> _n2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    Node* root = createTree(_str);

    Node* n = findLCA(root, _n1, _n2);
    cout << n->val << endl;
    return 0;
}
