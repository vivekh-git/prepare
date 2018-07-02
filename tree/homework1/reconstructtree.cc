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

/*
 * Complete the function below.
 */
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(NULL), right(NULL) {}
};

void printTree(Node* root) {
    if (!root) return;
    queue<Node *> q1, q2;
    q1.push(root);
    while (!q1.empty() || !q2.empty()) {
        while (!q1.empty()) {
            Node* qnode = q1.front(); q1.pop();
            cout << qnode->data << " ";
            if (qnode->left) q2.push(qnode->left);
            if (qnode->right) q2.push(qnode->right);
        }
        cout << endl;
        while (!q2.empty()) {
            Node* qnode = q2.front(); q2.pop();
            cout << qnode->data << " ";
            if (qnode->left) q1.push(qnode->left);
            if (qnode->right) q1.push(qnode->right);
        }
        cout << endl;
    }
}

int search(vector<int>& inorder, int istart, int iend, int element) {
    for (int i = istart; i <= iend; i++) {
        if (inorder[i] == element)
            return i;
    }
    return -1;
}



// preorder = { 1 2 4 5 3 6 7 }
// inorder = { 4 2 5 1 6 3 7}
Node* buildTree(vector<int>& inorder, int istart, int iend, vector<int>& preorder, int& pdx) {
	static int preIndex = 0;
    if (istart > iend)
        return NULL;
	cout << "pdx - " << pdx << ", preorder root - " << preorder[pdx] << endl;
    Node* root = new Node(preorder[pdx]); pdx++;
    if (istart == iend)
        return root;
    int iIndex = search(inorder, istart, iend, root->data);
	cout << "search return index - "  << iIndex << endl;
    root->left = buildTree(inorder, istart, iIndex-1, preorder, pdx);
    root->right = buildTree(inorder, iIndex+1, iend, preorder, pdx);
    return root;
}


void constrctTree(vector<int>& iInOrderArray, vector<int>& iPreOrderArray) {
    int pdx = 0;
    Node* root = buildTree(iInOrderArray, 0, iInOrderArray.size()-1, iPreOrderArray, pdx);
    printTree(root);
}

int main() {
    
    int _iInOrderArray_size = 0;
    cin >> _iInOrderArray_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _iInOrderArray;
    int _iInOrderArray_item;
    for(int _iInOrderArray_i=0; _iInOrderArray_i<_iInOrderArray_size; _iInOrderArray_i++) {
        cin >> _iInOrderArray_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _iInOrderArray.push_back(_iInOrderArray_item);
    }
    
    
    int _iPreOrderArray_size = 0;
    cin >> _iPreOrderArray_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _iPreOrderArray;
    int _iPreOrderArray_item;
    for(int _iPreOrderArray_i=0; _iPreOrderArray_i<_iPreOrderArray_size; _iPreOrderArray_i++) {
        cin >> _iPreOrderArray_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _iPreOrderArray.push_back(_iPreOrderArray_item);
    }
    
    constrctTree(_iInOrderArray, _iPreOrderArray);
    
    return 0;
}