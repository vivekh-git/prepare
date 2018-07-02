#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<pair<int,int>> get_neighbors(int rows, int cols, int r, int c) {
    vector<pair<int,int>> neighbors;
    vector<pair<int,int>> candidates = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};
    for (auto it = candidates.begin(); it != candidates.end(); it++) {
        if (it->first >= 0 && it->first < rows && it->second >= 0 && it->second < cols)
            neighbors.push_back(*it);
    }
    return neighbors;
}

vector<vector<int>> find_shortest_path(vector<string>& grid) {
    pair<int, int> start, target;
    bool st = false; bool et = false;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '@') {
                start = {i, j};
                st = true;
            }
            else if (grid[i][j] == '+') {
                target = {i, j};
                et = true;
            }
        }
        if (st && et) break;
    }
    
    // 10 bits for storing 10 different keys
    int maxkeys = 2048;
    int rows = grid.size(); int cols = grid[0].size();
    queue<pair<pair<int,int>, int>> q;
    vector<vector<vector<pair<pair<int,int>,int>>>> pred(rows, vector<vector<pair<pair<int,int>,int>>>(cols, vector<pair<pair<int,int>,int>>(maxkeys)));
    vector<vector<vector<int>>> dist(rows, vector<vector<int>>(cols, vector<int>(maxkeys, -1)));
    int keys;
    q.push({start, 0});
    pred[start.first][start.second][0] = {{-1,-1}, 0};
    dist[start.first][start.second][0] = 0;
    while(!q.empty()) {
        pair<pair<int,int>, int> qn = q.front(); q.pop();
        pair<int, int> qnode = qn.first;
		int oldkeys = qn.second;
        keys = qn.second;
        if (qnode == target) break;
        else if (grid[qnode.first][qnode.second] >= 'a' && grid[qnode.first][qnode.second] <= 'j') { // collect keys
            keys = keys | (1 << (grid[qnode.first][qnode.second] - 'a'));        
        }
        else if (grid[qnode.first][qnode.second] >= 'A' && grid[qnode.first][qnode.second] <= 'J') { // Doors
            if (!(keys & (1 << (grid[qnode.first][qnode.second] - 'A')))) // dont have key for the door
                continue;
        }
        // get neighbors
        vector<pair<int,int>> neighbors = get_neighbors(rows, cols, qnode.first, qnode.second);
        for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
            pair<int, int> n = *it;
            if (grid[n.first][n.second] == '#') { // skip water
                continue;
            }
            // add to queue if not visited
            if (dist[n.first][n.second][keys] != -1) continue; // visited already
            q.push({n, keys});
            pred[n.first][n.second][keys] = {qnode, oldkeys};
            dist[n.first][n.second][keys] = 1 + dist[qnode.first][qnode.second][oldkeys];
        }
    }
    // check if we reached target
    if (dist[target.first][target.second][keys] == -1) // target not found
        return {{}};
    vector<pair<int, int>> paths;
    pair<pair<int, int>,int> curr = {target, keys};
    while (curr.first.first != -1 || curr.first.second != -1 || curr.second != 0) {
        paths.push_back({curr.first.first, curr.first.second});
        curr = pred[curr.first.first][curr.first.second][curr.second];
    }
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