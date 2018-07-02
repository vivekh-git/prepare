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

bool _findBST2(Node* node, int & size, int& maxsize, Node* l = NULL, Node* r = NULL) {
	if (! node) {
		size = 0;
		//maxsize = 0;
		return true;
	}
	cout << node->val << ", size - " << size << ", maxsize - " << maxsize << endl;
	
	bool lvalid =  _findBST2(node->left, size, maxsize, l, node);
	//cout << "lvalid - " << node->val << ", size - " << size << ", maxsize - " << maxsize << endl;
	int lsize = size;
	
	bool rvalid =  _findBST2(node->right, size, maxsize, node, r);
	//cout <<  "rvalid - " << node->val << ", size - " << size << ", maxsize - " << maxsize << endl;
	int rsize = size;
	
	cout << "lvalid  - " << lvalid << ", rvalid - " << rvalid << endl;
	if (lvalid && rvalid) {
		if ((l && node->val < l->val) || (r && node->val > r->val)) {
			// current node is not a BST
			cout << "current node not bst" << endl;
			size = -1;
			return false;
		}
	
		size = 1 + lsize + rsize;
		if (size > maxsize)
			maxsize = size;
	
	    cout <<  "Current node bst, size - " << size << ", maxsize - " << maxsize << endl;
		return true;
	}
	
	size = -1;
	return false;
}

int minimum(int n1, int n2) {
	return (n1 < n2 ? n1 : n2);
}

int maximum(int n1, int n2) {
	return (n1 > n2 ? n1 : n2);
}

// returns size
int _findBST(Node* node, bool& isBST,  int & min, int& max, int& maxsize) {
	min = INT_MAX;
	max = INT_MIN;
	
	if (! node) {
		isBST = true;
		return 0;
	}
	
	int lsize =  _findBST(node->left, isBST, min, max, maxsize);
	bool lvalid = isBST && (max < node->val);
	
	int tempmin = minimum(node->val, min);
	int tempmax = maximum(node->val, max);
	
	int rsize = _findBST(node->right, isBST, min, max, maxsize);
	//cout <<  "rvalid - " << node->val << ", size - " << size << ", maxsize - " << maxsize << endl;
	bool rvalid = isBST && (min > node->val);
	
	min = minimum(tempmin, min);
	max = maximum(tempmax, max);
	
	cout << "lvalid  - " << lvalid << ", rvalid - " << rvalid << endl;
	if (lvalid && rvalid) {
	    isBST = true;
		int size = 1 + lsize + rsize;
		if (size > maxsize)
			maxsize = size;
	
	    cout <<  "Current node bst, size - " << size << ", maxsize - " << maxsize << endl;
		return size;
	}
	
	isBST = false;
	return -1;
}


// int _findBST(Node* node, bool& isBST,  int & min, int& max, int& maxsize) {
int findLargestBST(Node* node) {
	int maxsize = 0; bool isBST = 1;
	int min = INT_MAX;
	int max = INT_MIN;
	_findBST(node, isBST, min, max, maxsize);
	return maxsize;
}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str;
    getline(cin, _str);
    
    Node* root = createTree(_str);
    res = findLargestBST(root);
    cout << res << endl;
    
    //fout.close();
    return 0;
}