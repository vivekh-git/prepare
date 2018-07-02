#include <bits/stdc++.h>

using namespace std;

void print_arr_arr(vector<vector<int>>& table) {
	cout << "printing " << endl;
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

class DisjointUnionSets {
private:
	int v;
	vector<int> parent;
	vector<int> rank;
public:
	DisjointUnionSets(int n) {
		v = n;
		parent.resize(v);
		rank.resize(v);
		makeSet();
	}
	void makeSet() {
		for (int i=0; i < v; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int i) {
		if (parent[i] != i) {
			parent[i] = Find(parent[i]);
		}
		return parent[i];
	}
	void Union(int x, int y) {
		int xroot = Find(x);
		int yroot = Find(y);
		if (xroot == yroot) return;
		if (rank[xroot] < rank[yroot]) {
			parent[xroot] = yroot;
		}
		else if (rank[yroot] < rank[xroot]) {
			parent[yroot] = xroot;
		}
		else {
			parent[yroot] = xroot;
			rank[xroot]++;
		}
	}
	void Print(int rows, int cols) {
		cout << "printing dus 2 - rows - " << rows << ", cols - " << cols <<  endl;
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				int index = cols*r+c;
				cout << parent[index] << " ";
			}
			cout << endl;
		}
		cout << "dus ended" << endl;
	}
};

int maxSubmatrix2(vector<vector<int>>& mtx) {
	int rows = mtx.size(); int cols = mtx[0].size();
	DisjointUnionSets dus(rows * cols);
	dus.Print(rows, cols);
	
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (c == 0 || r == 0)
				continue;
			else if (mtx[r][c] == 1) {
				if (mtx[r-1][c] && mtx[r][c-1] && mtx[r-1][c-1]) {	
					dus.Union(cols*r+c, cols*(r-1)+c);
					dus.Union(cols*r+c, cols*r+c-1);
					dus.Union(cols*r+c, cols*(r-1)+c-1);
				}
			}
		}
	}
	cout << "printing dus - " << endl;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			int root = dus.Find(cols*r+c);
			if (root < 10) cout << " ";
			cout << root << " ";
		}
		cout << endl;
	}
	cout << "dus ended" << endl;
	
	unordered_map<int, int> szsubmtx; int root;
	int maxsize = INT_MIN; int maxR; int maxC; 
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (mtx[r][c]) {
				root = dus.Find(cols*r+c);
				if (szsubmtx.count(root) == 0)
					szsubmtx[root] = 1;
				else
					szsubmtx[root]++;
			}
			if (szsubmtx[root] > maxsize) {
				maxsize = szsubmtx[root];
			}
		}
	}
	cout << "maxsize - " << maxsize << endl;
	return maxsize;
}

/*
 * Complete the function below.
 */
/*  DP logic
  Create Size matrx S[R][C] and populate first row and first col as mtx[r][c]
  for other row,col, if mtx[r][c] == 1, then
						s[r][c] = min(s[r, c-1], s[r-1, c], s[r-1, c-1]) + 1
					 else 
						s[r][c] = 0;
*/
int maxSubmatrix(vector<vector<int>>& mtx) {
	vector<vector<int>> sz(mtx.size(), vector<int>(mtx[0].size(), 0));
	int maxsize = 1; int maxR = 0; int maxC = 0;
	for (int r = 0; r < mtx.size(); r++) {
		for (int c = 0; c < mtx[0].size(); c++) {
			if (r ==0 || c == 0)
				sz[r][c] = mtx[r][c];
			else if (mtx[r][c] == 1) {
				sz[r][c] = min(min(sz[r-1][c], sz[r][c-1]), sz[r-1][c-1])+1;
				if (sz[r][c] > maxsize) {
					maxsize = sz[r][c];
					maxR = r; maxC = c;
				}
			}
			else {
				sz[r][c] = mtx[r][c];
			}
		}
	}
	cout << "matrix: " << endl;
	print_arr_arr(mtx);
	cout << "size: " << endl;
	print_arr_arr(sz);
	
	int stR = maxR-maxsize+1; int stC = maxC-maxsize+1;
	cout << "maxsize = " << maxsize << ", maxR = " << maxR << ", maxC = " << maxC << endl;
	cout << "stR = " << stR << ", stC = " << stC << endl;
	cout << "printing max square matrix:" << endl;
	for (int i = stR; i <= maxR; i++) {
		for (int j = stC; j <= maxC; j++) 
			cout << mtx[i][j] << " ";
		cout << endl;
	}
	return maxsize;
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    /*
    int _mtx_rows = 0;
    int _mtx_cols = 0;
    cin >> _mtx_rows >> _mtx_cols;
    vector< vector < int > > _mtx(_mtx_rows);
    for(int _mtx_i=0; _mtx_i<_mtx_rows; _mtx_i++) {
        for(int _mtx_j=0; _mtx_j<_mtx_cols; _mtx_j++) {
            int _mtx_tmp;
            cin >> _mtx_tmp;
            _mtx[_mtx_i].push_back(_mtx_tmp);
        }
    }
	*/
	vector<vector<int>> _mtx = {
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}
	};
    
    res = maxSubmatrix(_mtx);
    cout << res << endl;
    
	//int res2 = maxSubmatrix2(_mtx);
    //cout << res2 << endl;
	
    //fout.close();
    return 0;
}