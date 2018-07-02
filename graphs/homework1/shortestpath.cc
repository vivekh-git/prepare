#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
// First attempt using BFS
/*
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
		cout << "{" << path[k].first << "," << path[k].second << "} " << endl;
	}
	cout << endl;
}


void DFS_visit(pair<int, int> node, vector<string>& grid, vector<pair<int,int>> path,  vector<pair<int,int>>& shortestpath, unordered_set<char> keys, vector<vector<bool>> visited) {
	// start is like a node u - do something with node u
	// check for all conditions with the node
	// color[u] = gray = mark it visited 
	// iterate on neighbors and if not visited called DFS visit
	// backtrack after visiting all neighbors
	// finishing time of the node
	//cout << "{" << node.first << "," << node.second << "}" << endl;
	char c = grid[node.first][node.second];
	
	if (c == '#') { // water
		return;
	}
	else if (c >= 'A' && c <= 'J') { // Door
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

	if (c == '+') { // goal
		// add to path or shortest path.
		// add path to shortestpath
		if (shortestpath.empty() || path.size() < shortestpath.size()) {
			shortestpath.clear();
			shortestpath = path;
		}
		return;
	}

	if (!shortestpath.empty()  && path.size() >= shortestpath.size()-1) {
		return;
	}

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
	return;
}

// DFS with backtracking needed
vector<vector<int>> find_shortest_path(vector <string> grid) {
	pair<int, int> start;
	
	for (int i = 0; i < grid.size(); i++) {
		for (int j= 0; j < grid[i].length(); j++) {
			if (grid[i][j] == '@') {
				start = {i, j};
				break;
			}
		}
	}
	
	int rows = grid.size();
	int cols = grid[0].length();
	
	vector<pair<int,int>> path, shortestpath;
	vector<vector<bool>> visited(rows, vector<bool>(cols)); 
	set_visited_false(visited);
	unordered_set<char> keys;
	
	DFS_visit(start, grid, path, shortestpath, keys, visited);
	vector<vector<int>> res; // assign shortestpath to res
	for(int k =0; k < shortestpath.size(); k++) {
		vector<int> pair = {shortestpath[k].first, shortestpath[k].second};
		res.push_back(pair);
	}
	return res;
}
*/

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

// bfs
vector<vector<int>> find_shortest_path(vector<string>& grid) {
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
	
	int rows = grid.size(); int cols = grid[0].length();
	int maxkeycollection = 2048; // a through j need 10 bits, 2 pow 10 - 1024, if we have 11 bit - 2048
	// <x,y>,keycollectionint
	vector<vector<vector<pair<pair<int,int>,int>>>> pred(rows, vector<vector<pair<pair<int,int>,int>>>(cols, vector<pair<pair<int,int>,int>>(maxkeycollection)));
	//vector<vector<int>> dist(rows, vector<int>(cols));
	int keycollectionint; // key collection is packed into bits of this integer
	vector<pair<int, int>> paths;
	queue<pair<pair<int,int>,int>> q;

    //cout << "    Pushing {" << start.first << "," << start.second << "}, " << 0 << endl;
    q.push({{start},0});
	pred[start.first][start.second][0] = {{-1, -1}, 0};
	//dist[start.first][start.second] = 0;
	
    while (!q.empty()) {
    	pair<pair<int, int>,int> qnode = q.front(); q.pop();
		keycollectionint = qnode.second;
		//cout << "qnode - {" << qnode.first.first << "," << qnode.first.second << "}, " << keycollectionint << endl;
		// check if target is reached
		char c = grid[qnode.first.first][qnode.first.second];
		if (c == '+') {
			target = {qnode.first.first, qnode.first.second};
			//cout << "{" << qnode.first.first << "," << qnode.first.second << "} target found" << " , keycollectionint - " << qnode.second << endl;
			break;
		}
		else if (c == '#') { // water
			//cout << "{" << qnode.first.first << "," << qnode.first.second << "} - water found " << endl; 
			continue;
		}
		else if (c >= 'a' && c <= 'j') { // key
			int pos = c - 'a';
			//cout << "{" << qnode.first.first << "," << qnode.first.second << "} - " << c << " key found " << endl;
			//cout << "pre keycollectionint - " << keycollectionint << endl;
			//cout << "pos - " << pos << endl;
			keycollectionint = keycollectionint | (1 << pos);
			//cout << "post keycollectionint - " << keycollectionint << endl;
		}
		else if (c >= 'A' && c <= 'J') {
			int dpos = c - 'A';
			//cout << "{" << qnode.first.first << "," << qnode.first.second << "} - " << c << " door found , dpos - " << dpos << endl;
			if (! (keycollectionint & (1 << dpos))) { // no key found
				//cout << "no key found" << endl;
				continue;
			}
		}
		
		vector<pair<int, int>> n = getneighbors(qnode.first.first, qnode.first.second, grid);
		for (vector<pair<int, int>>::iterator it = n.begin(); it != n.end(); it++) {			
			if (grid[it->first][it->second] == '#') continue;
			if (pred[it->first][it->second][keycollectionint] == make_pair(make_pair(0,0),0)) { // not visited
				//cout << "    Pushing {" << it->first << "," << it->second << "}, " << keycollectionint << endl;
				q.push({*it,keycollectionint});
				pred[it->first][it->second][keycollectionint] = qnode;
			}
		}
    }
	
	if (target.first == -1 || target.second == -1) {
		cout << "target not found - 1" << endl;
		return {{}};
	}

	//cout << "keycollectionint - " << keycollectionint << endl;
	if (pred[target.first][target.second][keycollectionint] ==  make_pair(make_pair(0,0),0)) {
		cout << "target not found - 2" << endl;
		return {{}};
	}
	//cout << "pred/target - {"<<pred[target.first][target.second][keycollectionint].first.first << "," << pred[target.first][target.second][keycollectionint].first.second << "}, " << pred[target.first][target.second][keycollectionint].second << endl;
	
	pair<pair<int, int>,int> curr = {target, keycollectionint};
	//cout << "{" << curr.first.first <<"," << curr.first.second << "}," << curr.second << endl;
	
	while (curr.first.first != start.first || curr.first.second != start.second || curr.second != 0) {
		paths.push_back(curr.first);
		curr = pred[curr.first.first][curr.first.second][curr.second];
		//cout << "{" << curr.first.first <<"," << curr.first.second << "}," << curr.second << endl;
	}
	if (paths.size() > 0) paths.push_back(start);
	reverse(paths.begin(), paths.end());
	
	vector<vector<int>> res;
	for(int k =0; k < paths.size(); k++) {
		vector<int> pair = {paths[k].first, paths[k].second};
		res.push_back(pair);
	}
	
	return res;
}


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