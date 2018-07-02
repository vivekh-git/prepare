#include <bits/stdc++.h>
using namespace std;




TreeNode* flattenUtil(TreeNode* root, TreeNode* &tail) {
        if (! root) {
            tail = NULL;
            return NULL;
        }

        TreeNode* lefttail = NULL;
        TreeNode* righttail = NULL;
        
        TreeNode* lefthead = flattenUtil(root->left, lefttail);
        TreeNode* righthead = flattenUtil(root->right, righttail);
        TreeNode* head = tail = root;
        if (root->left) {
            head = lefthead;
            tail = lefttail;
        }
        if (root->right) {
            if (! head) {
                head = righthead;
            }
            tail->right = righthead;
            tail = righttail;
        }
        if (head != root) {
            root->right = head;
        }
        return root;
}
    
void flatten(TreeNode* root) {
        TreeNode* tail = NULL;
        flattenUtil(root, tail);
}


int main() {

}