#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node(int d): data(d), left(NULL), right(NULL) {}
};

/*
void printTreeNextRight(node* root) {
	if (!root) return;
	cout << root->data << " -> ";
	if (root->nextRight)
		cout << root->nextRight->data;
	else
		cout << "NIL";
	cout << endl;
	printTreeNextRight(root->left);
	printTreeNextRight(root->right);
}*/

/* Single threaded tree */
void MorrisTraversal(node* root) {
	if (!root) return;
	node* curr = root;
	while (curr) {
		if (! curr->left) {
			cout << curr->data << " ";
			curr = curr->right;
		}
		else {
			node* pre = curr->left;
			while (pre && pre->right && pre->right != curr)
				pre = pre->right;
			if (! pre->right) {
				pre->right = curr;
				curr = curr->left;
			}
			else {
				pre->right = NULL;
				cout << curr->data << " ";
				curr = curr->right;
			}
		}
	}
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	
    MorrisTraversal(root);
	
	return 0;
}