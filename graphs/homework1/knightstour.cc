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
#include <utility> 
#include <iostream>

using namespace std;

/*
 * Complete the function below.
 */
/*
vector<pair<int, int>> get_neighbors(int rows, int cols, int i, int j) {
	vector<pair<int, int>> neighbors;
	vector<pair<int, int>> candidates = {{i-2, j-1}, {i-2, j+1}, {i+2, j-1}, {i+2, j+1}, {i-1, j-2}, {i-1, j+2}, {i+1, j-2}, {i+1,j+2}};
	for (vector<pair<int,int>>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < rows && it->second >= 0 && it->second < cols)
			//pair<int, int> element = {it->first, it->second };
			neighbors.push_back( {it->first, it->second });
	}
	return neighbors;
}



int minimumMoves(int rows, int cols, int startx, int starty, int endx, int endy) {
	queue<pair<int, int>> q;
	unordered_map<pair<int, int>*, pair<int, int>*> pred;
	unordered_map<pair<int, int>*, int> dist;
	q.push( {startx, starty});
	pair<int, int> p = {startx, starty}
	pred[{startx, starty}] = {-1, -1};
	dist[ {startx, starty}] = 0;
	
	while (!q.empty()) {
		pair<int, int> n = q.front(); q.pop();
		if (n.first == endx && n.second == endy)
			break;
		vector<pair<int, int>> neighbors = get_neighbors(rows, cols, n.first, n.second);
		for (vector<pair<int,int>>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
			if (dist.count({it->first, it->second}) != 0)  // // already visited
				continue;
			q.push({it->first, it->second});
			pred[{it->first, it->second}] = {n.first, n.second};
			dist[{it->first, it->second}] = 1+dist[{n.first, n.seond}];
		}
	}

    if (dist.count({endx, endy}) == 0)
		return -1;

    return dist[{endx, endy}];
}



struct node {
	int x;
	int y;
	node(int r, int c): x(r), y(c) {}
	//operator = 
};

vector<node> get_neighbors(int rows, int cols, int i, int j) {
	vector<node> neighbors;
	vector<node> candidates = { node(i-2, j-1),  node(i-2, j+1),  node(i+2, j-1),  node(i+2, j+1),  node(i-1, j-2), node(i-1, j+2), node(i+1, j-2), node(i+1,j+2)};
	for (vector<node>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		if (it->x >= 0 && it->x < rows && it->y >= 0 && it->y < cols)
			//pair<int, int> element = {it->first, it->second };
			neighbors.push_back(node(it->x, it->y));
	}
	return neighbors;
}



int minimumMoves(int rows, int cols, int startx, int starty, int endx, int endy) {
	queue<node> q;
	unordered_map<node, node> pred;
	unordered_map<node, int> dist;
	//node* st = new ;
	q.push(node(startx, starty));

	pred[node(startx, starty)] = node(-1, -1);
	dist[node(startx, starty)] = 0;
	
	while (!q.empty()) {
		node n = q.front(); q.pop();
		if (n.x == endx && n.y == endy)
			break;
		vector<node> neighbors = get_neighbors(rows, cols, n.x, n.y);
		for (vector<node>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
			node t = *it;
			if (dist.count(t) != 0)  // // already visited
				continue;
			q.push(t);
			pred[t] = n;
			dist[t] = 1+dist[n];
		}
	}

    node ey = node(endx, endy);
    if (dist.count(ey) == 0)
		return -1;

    return dist[ey];
}

*/
/*
vector<node> get_neighbors(int rows, int cols, int i, int j) {
	vector<node> neighbors;
	vector<node> candidates = { node(i-2, j-1),  node(i-2, j+1),  node(i+2, j-1),  node(i+2, j+1),  node(i-1, j-2), node(i-1, j+2), node(i+1, j-2), node(i+1,j+2)};
	for (vector<node>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		if (it->x >= 0 && it->x < rows && it->y >= 0 && it->y < cols)
			//pair<int, int> element = {it->first, it->second };
			neighbors.push_back(node(it->x, it->y));
	}
	return neighbors;
}*/
void print_arr(vector<pair<int, int>>& paths) {
    for (int i = 0; i < paths.size(); i++) {
    	cout << "(" << (paths[i]).first << ", " << (paths[i]).second << ")" << " -> ";
    }
	cout << endl;
}

void print_arr_arr(vector<vector<pair<int, int>>>& pred) {
	for (int i = 0; i < pred.size(); i++) {
		for (int j = 0; j < pred[0].size(); j++) {
			cout << "(" << (pred[i][j]).first << ", " << (pred[i][j]).second << ")" << " "; 
		}
		cout << endl;
	}
}

void print_arr_arr(vector<vector<int>>& dist) {
	for (int i = 0; i < dist.size(); i++) {
		for (int j = 0; j < dist[0].size(); j++) {
			cout << dist[i][j] << " "; 
		}
		cout << endl;
	}
}


vector<pair<int, int>> get_neighbors(int rows, int cols, int i, int j) {
	vector<pair<int, int>> neighbors;
	vector<pair<int, int>> candidates = {{i-2, j-1}, {i-2, j+1}, {i+2, j-1}, {i+2, j+1}, {i-1, j-2}, {i-1, j+2}, {i+1, j-2}, {i+1,j+2}};
	for (vector<pair<int,int>>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < rows && it->second >= 0 && it->second < cols)
			//pair<int, int> element = {it->first, it->second };
			neighbors.push_back( {it->first, it->second });
	}
	return neighbors;
}

bool isValid(int rows, int cols, int r, int c) {
    if (r >= 0 && r < rows && c >= 0 && c < cols)
        return true;
    else
        return false;
}

int minimumMoves(int rows, int cols, int startx, int starty, int endx, int endy) {
	if (!isValid(rows, cols, startx, starty) || !isValid(rows, cols, endx, endy))
	        return -1;
	    else if (startx == endx && starty == endy)
	        return 0;
	
	queue<pair<int,int>> q;
	
	vector<vector<pair<int, int>>> pred(rows, vector<pair<int, int>>(cols));
	vector<vector<int>> dist(rows, vector<int>(cols, -1));
	
	//node* st = new ;
	q.push({startx, starty});

	pred[startx][starty] = {-1, -1};
	dist[startx][starty]= 0;
	
	while (!q.empty()) {
		pair<int,int> n = q.front(); q.pop();
		if (n.first == endx && n.second == endy)
			break;
		vector<pair<int, int>> neighbors = get_neighbors(rows, cols, n.first, n.second);
		for (vector<pair<int, int>>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
			pair<int, int> t = *it;
			if (dist[t.first][t.second] == -1) { 
				q.push(t);
				pred[t.first][t.second] = n;
				dist[t.first][t.second] = 1 + dist[n.first][n.second];
			}
		}
	}

    //node ey = node(endx, endy);
    if (dist[endx][endy] == -1)
		return -1;

    print_arr_arr(pred);
	print_arr_arr(dist);

	vector<pair<int, int>> paths;
	pair<int, int> curr = {endx, endy};
	while (curr.first != -1 && curr.second != -1) {
		cout << "inside while" << endl;
	   	paths.push_back(curr);
	   	curr = pred[curr.first][curr.second];
	}
	reverse(paths.begin(), paths.end());
	print_arr(paths);

    return dist[endx][endy];
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
	
    int res;
    int _rows;
    cin >> _rows;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _cols;
    cin >> _cols;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _startx;
    cin >> _startx;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _starty;
    cin >> _starty;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _endx;
    cin >> _endx;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _endy;
    cin >> _endy;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = minimumMoves(_rows, _cols, _startx, _starty, _endx, _endy);
    cout << res << endl;
    
    //fout.close();
    return 0;
}