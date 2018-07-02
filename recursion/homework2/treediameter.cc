#include <bits/stdc++.h>
#include <locale>
#include <string>

using namespace std;

struct node {
	int dist_from_parent;
	vector<node *> children;
};


int readNumber(string& str, int& idx) {
	locale loc;
	int num = 0;
	while(isdigit(str[idx], loc)) {
		num = num * 10;
		num = num + str[idx] - '0';
		idx++;
	}
	return num;
}


node* buildTree(string& str, int& idx) {
	idx++;  // idx at {
	node* root = new node;
	root->dist_from_parent = readNumber(str, idx);
	// now idx at ,
	idx++;
	int childrenCount = readNumber(str, idx);
	// now idx at , if children exit or } if no children
	idx++;
	if (childrenCount == 0) return root;
	for (int i = 0; i < childrenCount; i++) {
		root->children.push_back(buildTree(str, idx));
		idx++; // this is for comma },{
	}
	return root;
}

int diameter(node* root, int& height) {
	if (! root) {
		height = 0;
		return 0;
	}
	int d,h;
	int mh1=0, mh2=0, md=0;
	for (auto it = root->children.begin(); it != root->children.end(); it++) {
		d = diameter(*it, h);
		if (d > md) md = d;
		if (h > mh1) {
			mh2 = mh1;
			mh1 = h;
		}
		else if (h > mh2) {
			mh2 = h;
		}
	}
	height = mh1 + root->dist_from_parent;
	return max(mh1+mh2, md);  // not adding mh1+mh2+root->dist_from_parent as dist_from_parent should get included only at parent level
}


int main() {
	string input;
	cin >> input; int idx = 0;
	node* root = buildTree(input, idx);
	int height;
	int d = diameter(root, height);
	cout << "diameter - " << d << endl;
}
