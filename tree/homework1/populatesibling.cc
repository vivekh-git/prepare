#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node* nextRight;
	node(int d): data(d), left(NULL), right(NULL), nextRight(NULL) {}
};

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
}

node* getNextRightChild(node* root) {
	node* curr = root->nextRight;
	while (curr) {
		if (curr->left)
			return curr->left;
		if (curr->right)
			return curr->right;
		curr = curr->nextRight;
	}
	return NULL;
}

void connect(node* root) {
	if (! root) return;
	root->nextRight = NULL;
	while (root) {
		node* curr = root;
		while (curr) {
			if (curr->left) 
				curr->left->nextRight = (curr->right) ? curr->right : getNextRightChild(curr);
			if (curr->right) 
				curr->right->nextRight = getNextRightChild(curr);
			curr = curr->nextRight;
		}
		if (root->left)
			root = root->left;
		else if (root->right)
			root = root->right;
		else 
			root = getNextRightChild(root);
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
	
	connect(root);
	printTreeNextRight(root);
	
	return 0;
}