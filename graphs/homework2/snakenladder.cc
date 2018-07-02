#include <bits/stdc++.h>

using namespace std;

void print_board(vector<int>& board, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[n*i+j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_map(unordered_map<int, int>& dict) {
	for (auto it = dict.begin(); it != dict.end(); it++) {
		cout << it->first << " -> " << it->second << endl;
	}
}

int getMinDiceThrows(vector<int>& board) {
	vector<bool> visited(board.size());
	unordered_map<int, int> parent;
	unordered_map<int, int> dist;
	
	queue<int> q;
	q.push(0);
	parent[0] = -1;
	dist[0] = 0;
	visited[0] = true;
	
	int qvertex;
	while (!q.empty()) {
		qvertex = q.front(); q.pop();
		if (qvertex == board.size()-1) 
			break;
		// neighbors
		for (int n = qvertex+1; n <= qvertex+6 && n < board.size(); n++) {
			// check if the node is already visited
			if (board[n] == -1) {
				if (visited[n]) continue;
				visited[n] = true;
				parent[n] = qvertex;
				//cout << "parent(" << n << ") -> " << qvertex << endl;
				dist[n] = dist[qvertex] + 1;
				q.push(n);
			}
			else {
				if (visited[board[n]]) continue;
				visited[board[n]] = true; 
				parent[board[n]] = qvertex;
				//cout << "parent(" << board[n] << ") -> " << qvertex << endl;
				dist[board[n]] = dist[qvertex] + 1;
				q.push(board[n]);
			}
		}
	}
	
	return dist[board.size()-1];
}

int getMinDiceThrows2(vector<int>& board) {
	vector<bool> visited(board.size(), false);
	queue<pair<int, int>> q;
	visited[0] = true;
	q.push({0,0});
	
	pair<int, int> qnode;
	while (!q.empty()) {
		qnode = q.front(); q.pop();
		
		int qvertex = qnode.first;
		if (qvertex == board.size()-1) 
			break;
		
		// neighbors
		for (int n = qvertex+1; n <= qvertex+6 && n < board.size(); n++) {
			// check if the node is already visited
			if (visited[n]) continue;
			visited[n] = true;
			int dist = qnode.second + 1;
			if (board[n] == -1)
				q.push({n, dist});
			else
				q.push({board[n], dist});
		}
	}
	return qnode.second;
}




int main() {
    int N = 36;	
	vector<int> board(N, -1);
	
    // Ladders - chnaged 1-36 indexing to 0-35 indexing
    board[1] = 14;
    board[4] = 6;
    board[8] = 26;
    board[17] = 28;
	board[24] = 34;
 
    // Snakes
	board[33] = 11;
	board[31] = 29;
    board[23] = 15;
    board[19] = 5;
    board[16] = 3;
	
	//print_board(board, 6);
 
    int m =  getMinDiceThrows(board);
	cout << "Min Dice throws required is : " << m << endl;
    return 0;
}