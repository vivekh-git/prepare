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
bool countSingleValueTree(Node* node, int& counter) {
	if (!node)
		return true;
	
	bool l = countSingleValueTree(node->left, counter);
	bool r = countSingleValueTree(node->right, counter);
	
	if (l && r) {
		// is this a leaf node
		if (! node->left && ! node->right) {
			counter += 1;
			return true;
		}
		else if (node->left && node->right && node->val == node->left->val && node->val == node->right->val) {
			counter += 1;
			return true;
		}
		else if (node->left && node->val == node->left->val) {
			counter += 1;
			return true;
		}
		else if (node->right && node->val == node->right->val) {
			counter += 1;
			return true;
		}
	}
	
	return false;
}


bool countOptimized_Util(Node *root, int& counter)
{
    if(!root)
        return true;
 
    bool l=countOptimized_Util(root->left,counter);
    bool r=countOptimized_Util(root->right,counter);
 
	// both left and right subtrees are unival
    if(l&&r)
    {
        Node *rl=root->left;
        Node *rr=root->right;
        // if leaf node
        if(!rl && !rr)
        {
            counter++;
            return true;
        }
        // left and right child exists and their data is also same as root's data
        else if(rl && rr && rl->val==root->val && rr->val==root->val)
        {
            counter++;
            return true;
        }
        // only left child exists and its data is same as root's data
        else if(rl && rl->val==root->val)
        {
            counter++;
            return true;
        }
        // only right child exists and its data is same as root's data
        else if(rr && rr->val==root->val)
        {
            counter++;
            return true;
        }
    }
    return false;
}

// Function takes a root node and an integer key.
// Returns true if each node of tree rooted with 'root'
// has same value equal to 'key' otherwise false
bool isUnival_Util(Node *root,int key)
{
    if(root==NULL)
        return true;
 
    // if root's data and key are equal and left subtree 
    // and right subtree are also unival
    return (root->val==key && isUnival_Util(root->left,key) && isUnival_Util(root->right,key));
}
 
// Tells whether tree is unival or not using a helper function
bool isUnival(Node *root)
{
    if(root==NULL)
        return true;
    int key=root->val;
    return isUnival_Util(root,key);
}
 
// Function takes a root node and an integer pointer
// which stores the total count of unival subtrees
void countUnivalsBF_Util(Node *root, int& counter)
{
    if(!root)
        return;
 
    if(isUnival(root))
        counter++;
    countUnivalsBF_Util(root->left,counter);
    countUnivalsBF_Util(root->right,counter);
}
 
// Counts the number of unival subtrees
int countUnivalsBF(Node *root)
{
    int counter=0;
    countUnivalsBF_Util(root,counter);
 
    return counter;
}


int findSingleValueTrees(Node* node) {
	int count = 0;
	//countSingleValueTree(node, count);
	//countOptimized_Util(node, count);
    countUnivalsBF_Util(node, count);
	return count;
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

    res = findSingleValueTrees(root);
    cout << res << endl;
    
    //fout.close();
    return 0;
}