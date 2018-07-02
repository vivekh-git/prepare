#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the function below.
 * dfs(node) {
     if (!node) return NULL;
     else {
		dfs(node->left);
		dfs(node->right);
	 }
   }
  
   count(level) {
     if (level == 1) return 1;
     else {
		return count(level-1) + count(level-1);
     }
}


 */
// Start - 11.18p
// End - 
// Total - 
int countTrees(int numNodes) {
      if (numNodes <= 1) return 1;
      else {
		  int sum=0;
		  int left, right, root;
		  for (root = 1; root <= numNodes; root++) {
			  left = countTrees(root-1);
			  right = countTrees(numNodes - root);
			  sum += left*right;
		  }
		  return sum;
      }
}



int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    int iNodeCount;
    cin >> iNodeCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = countTrees(iNodeCount);
    cout << res << endl;

    //fout.close();
    return 0;
}