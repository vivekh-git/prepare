#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> find_skyline(vector<vector<int>> buildings) {
	    vector<vector<int>> result;
	    int cur = 0; int cur_X; int cur_H = -1; int len = buildings.size();
	    priority_queue<pair<int,int>> pq;
	    while (cur < len || !pq.empty()) {
	        cur_X = pq.empty() ? buildings[cur][0] : pq.top().second;
	        if (cur >= len || buildings[cur][0] > cur_X) {
	            // new building starts at a point greater than top of priority queue - pop the pq.
	            while (!pq.empty() && pq.top().second <= cur_X)
	                pq.pop();
	        }
	        else {
	            // new building is overlapping with pq.top - so process the new building and push to pq.
	            cur_X = buildings[cur][0];
	            while (cur < len && buildings[cur][0] == cur_X) {
	                pq.push({buildings[cur][1], buildings[cur][2]});
	                cur++;
	            }
	        }
	        cur_H = pq.empty() ? 0 : pq.top().first;
	        if (result.empty() || result.back()[1] != cur_H)
	            result.push_back({cur_X, cur_H});
	    }
	    return result;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int buildings_rows;
    cin >> buildings_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int buildings_columns;
    cin >> buildings_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> buildings(buildings_rows);
    for (int buildings_row_itr = 0; buildings_row_itr < buildings_rows; buildings_row_itr++) {
        buildings[buildings_row_itr].resize(buildings_columns);

        for (int buildings_column_itr = 0; buildings_column_itr < buildings_columns; buildings_column_itr++) {
            cin >> buildings[buildings_row_itr][buildings_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> res = find_skyline(buildings);

    for (int res_row_itr = 0; res_row_itr < res.size(); res_row_itr++) {
        for (int res_column_itr = 0; res_column_itr < res[res_row_itr].size(); res_column_itr++) {
            cout << res[res_row_itr][res_column_itr];

            if (res_column_itr != res[res_row_itr].size() - 1) {
                cout << " ";
            }
        }

        if (res_row_itr != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}