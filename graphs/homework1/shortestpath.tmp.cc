#include <bits/stdc++.h>
#include <string>
#include <locale>

using namespace std;

/*
 * Complete the function below.
 */
// First attempt using BFS
vector<pair<int, int>> getneighbors(int x, int y, vector<string>& grid) {
	int rows = grid.size();
	int cols = grid[0].length();
	//vector<pair<int, int>> candidates = {{x,y-1}, {x, y+1}, {x-1, y}, {x-1, y-1}, {x-1, y+1}, {x+1, y}, {x+1, y-1}, {x+1, y+1}};
	// diagonal movements not allowed
	vector<pair<int, int>> candidates = {{x,y-1}, {x, y+1}, {x-1, y}, {x+1, y}};
	vector<pair<int, int>> neighbors;
	for (vector<pair<int, int>>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < rows && it->second >= 0 && it->second < cols) {
			neighbors.push_back({it->first, it->second});
		}
	}
	return neighbors;
}


void set_visited_false(vector<vector<bool>>& visited) {
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[i].size(); j++) {
			visited[i][j] = false;
		}
	}
}

void print_path(vector<pair<int,int>>& path) {
	for(int k =0; k < path.size(); k++) {
		cout << "{" << path[k].first << "," << path[k].second << "} ";
	}
	cout << endl;
}

void print_shortestpath(vector<vector<vector<pair<int,int>>>>& shortestpath) {
	for(int k =0; k < shortestpath.size(); k++) {
		for (int l = 0; l < shortestpath[k].size(); l++) {
			for (int m = 0; m < shortestpath[k][l].size(); m++) {
				cout << "{" << shortestpath[k][l][m].first << "," << shortestpath[k][l][m].second << "} ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void DFS_visit(pair<int, int> node, vector <string>& grid, vector<pair<int,int>> path,  vector<vector<vector<pair<int,int>>>>& shortestpath, unordered_set<char> keys, vector<vector<bool>> visited) {
	// start is like a node u - do something with node u
	// check for all conditions with the node
	// color[u] = gray = mark it visited 
	// iterate on neighbors and if not visited called DFS visit
	// backtrack after visiting all neighbors
	// finishing time of the node
	cout << "{" << node.first << "," << node.second << "}" << endl;
	char c = grid[node.first][node.second];
	
	if (c == '#') { // water
		return;
	}
	
	if (c == '+') { // goal
		// add to path or shortest path.
		// add path to shortestpath
		if (shortestpath[node.first][node.second].empty() || path.size()+1 < shortestpath[node.first][node.second].size()) {
			shortestpath[node.first][node.second].clear();
			visited[node.first][node.second] = true;
			path.push_back({node.first, node.second});
			shortestpath[node.first][node.second] = path;
		}
		print_shortestpath(shortestpath);
		return;
	}
	
	if (!shortestpath[node.first][node.second].empty()  && path.size()+2 >= shortestpath[node.first][node.second].size()) {
	//if (!shortestpath[node.first][node.second].empty()) {
		return;
	}
	
	
	if (c >= 'A' && c <= 'J') { // Door
		locale loc;
		char lowerc = tolower(c, loc);
		if (keys.count(lowerc) == 0) { // no corresponding key
			return;
		}
	}
	else if (c >= 'a' && c <= 'j') { // key
		if (keys.count(c) == 0) { // key doesnt exist already
			keys.insert(c); // add key to keyset
			set_visited_false(visited); // you get to revisit all nodes again here
		}
	}
	
	// mark visited, 
	// add to path
	visited[node.first][node.second] = true;
	path.push_back({node.first, node.second});

	// recurse on neighbors
	vector<pair<int, int>> n = getneighbors(node.first, node.second, grid);
	vector<pair<int, int>>::iterator it;
	for (it = n.begin(); it != n.end(); it++) {
		if (! visited[it->first][it->second]) { // not visited
			//cout << "{" << it->first << "," << it->second << "} - not visited" << endl;
			DFS_visit(make_pair(it->first, it->second), grid, path, shortestpath, keys, visited);
		}
	}
	
	// backtrack
	path.pop_back();
	visited[node.first][node.second] = false;
}

// DFS with backtracking needed
vector<vector<int>> find_shortest_path(vector <string> grid) {
	pair<int, int> start, target;
	
	bool st = false; bool end = false;
	for (int i = 0; i < grid.size(); i++) {
		for (int j= 0; j < grid[i].length(); j++) {
			if (grid[i][j] == '@') {
				start = {i, j};
				st = true;
			}
			if (grid[i][j] == '+') {
				target = {i, j};
				end = true;
			}
			if (st && end)
				break;
		}
	}
	
	int rows = grid.size();
	int cols = grid[0].length();
	
	vector<pair<int,int>> path;
	vector<vector<vector<pair<int,int>>>> shortestpath(rows, vector<vector<pair<int,int>>>(cols));
	vector<vector<bool>> visited(rows, vector<bool>(cols)); 
	set_visited_false(visited);
	unordered_set<char> keys;
	
	DFS_visit(start, grid, path, shortestpath, keys, visited);
	//print_shortestpath(shortestpath);
	print_path(shortestpath[target.first][target.second]);
	
	vector<vector<int>> res; // assign shortestpath to res
	for(int k =0; k < shortestpath[target.first][target.second].size(); k++) {
		vector<int> pair = {shortestpath[target.first][target.second][k].first, shortestpath[target.first][target.second][k].second};
		res.push_back(pair);
	}
	return res;
}


// bfs
/*
vector<vector<int>> find_shortest_path(vector <string> grid) {
	pair<int, int> start;
	pair<int, int> target = {-1, -1};
	for (int i = 0; i < grid.size(); i++) {
		for (int j= 0; j < grid[i].length(); j++) {
			if (grid[i][j] == '@') {
				start = {i, j};
				break;
			}
		}
	}
	//cout << "start found - " << start.first << " - " << start.second << endl;
	
	vector<vector<pair<int,int>>> pred(rows, vector<pair<int, int>>(cols));
	vector<vector<int>> dist(rows, vector<int>(cols));
	unordered_set<char> keys;
	
	vector<pair<int, int>> paths;
	queue<pair<int,int>> q;

    q.push(start);
	pred[start.first][start.second] = {-1, -1};
	dist[start.first][start.second] = 0;
    while (!q.empty()) {
    	pair<int, int> qnode = q.front(); q.pop();
		// check if target is reached
		char c = grid[qnode.first][qnode.second];
		if (c == '+') {
			target = {qnode.first, qnode.second};
			cout << "{" << qnode.first << "," << qnode.second << "} target found" << endl;
			break;
		}
		else if (c == '#') { // water
			cout << "{" << qnode.first << "," << qnode.second << "} - water found " << endl; 
			continue;
		}
		else if (c >= 'a' && c <= 'j') {
			cout << "{" << qnode.first << "," << qnode.second << "} - key found " << endl;
			keys.insert(c);
		}
		else if (c >= 'A' && c <= 'J') {
			cout << "{" << qnode.first << "," << qnode.second << "} - door found " << endl;
			if (keys.count(tolower(c, loc) == 0)) { // no keys
				cout << "{" << qnode.first << "," << qnode.second << "} - door found and we dont have key " << endl;
				continue;
			}
		}
		
		vector<pair<int, int>> n = getneighbors(qnode.first, qnode.second, grid);
		vector<pair<int, int>>::iterator it;
		for (it = n.begin(); it != n.end(); it++) {
			if (pred[it->first][it->second] == make_pair(0,0)) { // not visited
				//cout << "{" << it->first << "," << it->second << "} - not visited" << endl;
				q.push({it->first, it->second});
				pred[it->first][it->second] = qnode;
				dist[it->first][it->second] = 1 + dist[qnode.first][qnode.second];
			}
		}
    }
	
	if (target.first == -1 || target.second == -1) {
		//cout << "target not found" << endl;
		return {{}};
	}
	if (dist[target.first][target.second] == 0) {
		//cout << "target not found" << endl;
		return {{}};
	}
	pair<int, int> curr = target;
	while (curr.first != -1 && curr.second != -1) {
		paths.push_back(curr);
		curr = pred[curr.first][curr.second];
	}
	reverse(paths.begin(), paths.end());
	vector<vector<int>> res;
	for(int k =0; k < paths.size(); k++) {
		vector<int> pair = {paths[k].first, paths[k].second};
		res.push_back(pair);
	}
	return res;
}
*/

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector < vector<int> > res;
    int grid_size = 0;
    cin >> grid_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> grid;
    for(int i = 0; i < grid_size; i++) {
        string grid_item;
        getline(cin, grid_item);
        grid.push_back(grid_item);
    }

    res = find_shortest_path(grid);
	cout << "RESULT" << endl;
    for(int res_i = 0; res_i < res.size(); res_i++) {
        for(int res_j = 0; res_j < res[res_i].size(); res_j++) {
            cout << res[res_i][res_j] << " ";;
        }
        cout << endl;
    }

    //fout.close();
    return 0;
}