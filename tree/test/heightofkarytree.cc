#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

struct TreeNode
{
	//int val;														    // To find height of tree, value stored in nodes does not matter. So in input also we are not given this field. 
	vector<TreeNode*> children;											// Address of children nodes. 
	TreeNode()
	{
		children.clear();
	}
};


/*
 * Complete the function below.
 */

/*
    For your reference:
    
    struct TreeNode
    {
        vector<TreeNode*> children;										// Address of children nodes. 
        TreeNode()
        {
            children.clear();
        }
    };
*/



// vector<TreeNode*> children;	
int _find_height(int k, TreeNode* root) {
	if (! root) return 0;
	if ((root->children).size() == 0) return 0;
	vector<TreeNode*> childr = root->children;
	int max = 0;
	for (int i = 0; i < childr.size(); i++) {
		int h = _find_height(k, childr[i]);
		if (h > max)
			max = h;
	}
	return 1+max;
}

int find_height(int k, TreeNode* root) {
	return _find_height(k, root);
}


unordered_map<int, TreeNode*> address; 									// To build k-ary tree use this to speed up the insertion process. 

TreeNode* build_tree(vector<int> from, vector<int> to)
{
	int N = from.size() + 1;
	address.clear();												   // Clear the global variable. 
	for (int i = 1; i <= N; i++)
	{
		address[i] = new TreeNode();									// Create N nodes. 
	}
	for (int i = 0; i < N - 1; i++)								  
	{
		address[from[i]]->children.push_back(address[to[i]]);		    // Link the nodes. (Build the k-ary tree.)
	}
	return address[1];									
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int edges;
    cin >> edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int N = edges + 1;
    assert(1 <= N);
    assert(N <= MAX_N);
    assert(0 <= k);
    assert(k <= N - 1);

    vector<int> from(edges, 0);
    for (int i = 0; i < edges; i++)
    {
        cin >> from[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        assert(1 <= from[i]);
        assert(from[i] <= N);
    }

    cin >> edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    assert(edges == N - 1);

    vector<int> to(edges, 0);
    for (int i = 0; i < edges; i++)
    {
        cin >> to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        assert(1 <= to[i]);
        assert(to[i] <= N);
    }

    unordered_map<int, int> no_of_in_edges;
    for (int i = 0; i < edges; i++)
    {
        no_of_in_edges[to[i]]++;
    } 
    assert(no_of_in_edges.size() == N - 1);

    for (auto it = no_of_in_edges.begin(); it != no_of_in_edges.end(); it++)
    {
        assert(it->second == 1);
    }

    TreeNode* root = build_tree(from, to);

    int h = find_height(k, root);
    assert(0 <= h);
    assert(h <= N - 1);  
    
    fout << h << endl;

    fout.close();
    return 0;
}
