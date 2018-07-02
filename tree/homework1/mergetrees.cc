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

void printInorder(Node* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}


/*
 * Complete the function below.
 */
// serialize into array
// array merge
// reconstruct tree
// print BFS

void print_arr(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void serialize(Node* root, vector<int>& arr) {
	if (! root) return;
	serialize(root->left, arr);
	arr.push_back(root->val);
	serialize(root->right, arr);
}

void merge(vector<int>& output, vector<int>& arr1, vector<int>& arr2) {
	int i=0; int j = 0;
	while (i < arr1.size() && j < arr2.size()) {
		if (arr1[i] < arr2[j]) {
			output.push_back(arr1[i]);
			i++;
		}
		else {
			output.push_back(arr2[j]);
			j++;
		}
	}
	while (i < arr1.size()) {
		output.push_back(arr1[i]);
		i++;
	}
	while (j < arr2.size()) {
		output.push_back(arr2[j]);
		j++;
	}
}

Node* reconstruct(vector<int>& output, int start, int end) {
	if (end >= start) { // check
		int mid = start + (end-start)/2;
		Node* n = new Node(output[mid]);
		n->left = reconstruct(output, start, mid-1);
		n->right = reconstruct(output, mid+1, end);
		return n;
	}
	else {
		return NULL;
	}
}

// 2 queue approach
void printBFS(Node* n) {
	if (! n) return;
	queue<Node *> q1, q2;
	q1.push(n);
	while (!q1.empty() || !q2.empty()) {
		while (!q1.empty()) {
			Node* tmp = q1.front(); q1.pop();
			cout << tmp->val << " ";
			if (tmp->left) q2.push(tmp->left);
			if (tmp->right) q2.push(tmp->right);
		}
		cout << endl;
		while (!q2.empty()) {
			Node* tmp = q2.front(); q2.pop();
			cout << tmp->val << " ";
			if (tmp->left) q1.push(tmp->left);
			if (tmp->right) q1.push(tmp->right);
		}
		cout << endl;
	}
}



Node* mergeTrees(Node* n1, Node* n2) {
	vector<int> arr1, arr2, output;
	serialize(n1, arr1);
	serialize(n2, arr2);
	merge(output, arr1, arr2);
	//print_arr(arr1);
	//print_arr(arr2);
	//print_arr(output);
	Node* n = reconstruct(output, 0, output.size()-1);
    printBFS(n);
	return n;
	//return NULL;
}




int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int _size1;
    cin >> _size1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str1;
    getline(cin, _str1);
    Node* root1 = createTree(_str1);

    int _size2;
    cin >> _size2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _str2;
    getline(cin, _str2);
    Node* root2 = createTree(_str2);

    Node* res = mergeTrees(root1, root2);
    printInorder(res);

    //fout << res << endl;
    
    //fout.close();
    return 0;
}