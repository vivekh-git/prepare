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

void postOrder(Node* root) {
	if (! root) return;
	postOrder(root->right);
	postOrder(root->left);
	cout << root->val << " ";
}

void postorderTraversal(Node* root) {
	cout << "postorderTraversal" << endl;
	if (! root) return;
	stack<Node *> st, output;
	st.push(root);
	while (!st.empty()) {
		Node* t = st.top(); st.pop();
		output.push(t);
		if (t->left) st.push(t->left);
		if (t->right) st.push(t->right);
	}
	while (!output.empty()) {
		Node* t = output.top(); output.pop();
		cout << t->val << " ";
	}
	cout << endl;
}


//.     1
//.   2.  3
//. 4  5 6. 7
// nn.nn nn nn
void printPostorderOnestack(Node* node) {
	cout << "printPostorderOnestack" << endl;
	if (! node) return;
	stack<Node *> st;
	Node* curr = node;
	while (curr || !st.empty()) {
		if (curr) {
			st.push(curr);
			curr = curr->left;
		}
		else {
			Node* tmp = st.top()->right;
			if (! tmp) { // tmp is right of top, both left and right of st.top is null
				tmp = st.top(); st.pop();
				cout << tmp->val << " ";
				while (!st.empty() && tmp == st.top()->right) {
					tmp = st.top(); st.pop();
					cout << tmp->val << " ";
				}
			}
			else {
				curr = tmp;
			}
		}
	}
	cout << endl;
}



void printInorder(Node* n) {
    if(!n) return;
    printInorder(n->left);
    cout << n->val << " ";
    printInorder(n->right);
}


void printInordernorecur(Node* node) {
	if (! node) return;
	stack<Node *> st;
	Node* curr = node;
	bool done = false;
	while (! done) {
		if (curr) {
			st.push(curr);
			curr = curr->left;
		}
		else {
			if (st.empty()) {
				done = true;
			}
			else {
				curr = st.top(); st.pop();
				cout << curr->val << " ";
				curr = curr->right;
			}
		}
	}
	cout << endl;
}


// morris inorder traversal
// morris preorder traversal
// morris postorder traversal


int main() {
    int _size;
    cin >> _size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str;
    getline(cin, _str);
    Node* root = createTree(_str);
    postorderTraversal(root);
	printPostorderOnestack(root);
	
	printInorder(root); cout << endl;
	printInordernorecur(root);
    
    return 0;
}