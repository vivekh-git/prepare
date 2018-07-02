#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6000, MAX_VAL = 2000000000;

struct TreeNode
{
	int val;
	TreeNode* left_ptr;
	TreeNode* right_ptr;

	TreeNode(int _val = 0)
	{
		val = _val;
		left_ptr = NULL;
		right_ptr = NULL;
	}
};

TreeNode* bst_insert(TreeNode* root, int val)
{
	if (root == NULL)												// destination.
	{
		return new TreeNode(val);
	}
	if (val <= root->val)											// element is <= hence insert it in left subtree.
	{
		root->left_ptr = bst_insert(root->left_ptr, val);			// if root->left_ptr is null then new TreeNode will be created and root->left_ptr is assigned its address else it will be assigned to the same value as previouly stored.
	}
	else  															// element is > hence insert it in right subtree.
	{
		root->right_ptr = bst_insert(root->right_ptr, val);			// if root->right_ptr is null then new TreeNode will be created and root->right_ptr is assigned its address else it will be assigned to the same value as previouly stored.
	}
	return root;
}



/*
 * Complete the function below.
 */

/*
    For your reference. 

    struct TreeNode
    {
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;

        TreeNode(int _val = 0)
        {
            val = _val;
            left_ptr = NULL;
            right_ptr = NULL;
        }
    };
*/

void serialize(TreeNode* root, vector<int>& arr) {
	if (!root) return;
	serialize(root->left_ptr);
	arr.push_back(root->val);
	serialize(root->right_ptr);
}


int kth_smallest_element(TreeNode* root, int k) {
	vector<int> arr;
    serialize(root, arr);
	return arr[k-1];
}



int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int N;
    cin >> N;
    assert(1 <= N);
    assert(N <= MAX_N);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    TreeNode* root = NULL;

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        assert(-MAX_VAL <= data);
        assert(data <= MAX_VAL);

        root = bst_insert(root, data);
    }

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    assert(1 <= k);
    assert(k <= k);

    int ans = kth_smallest_element(root, k);
    cout << ans << endl;

    //fout.close();
    return 0;
}