#include <bits/stdc++.h>
using namespace std;

struct Point {
	int entering;
	int id;
	int x;
	int h;
	Point(int enter, int i, int xwidth, int height) {
		entering = enter;
		id = i;
		x = xwidth;
		h = height;
	}
	bool operator<(const Point& rhs) const {
		if (x == rhs.x) 
			return (entering * h > rhs.entering * rhs.h);
		return (x < rhs.x);
	}
};

class Maxheap {
private:
	vector<pair<int, int>> harr; // height, index
	unordered_map<int, int> pos;
	void swap(vector<pair<int, int>>& harr, int pos1, int pos2) {
		pair<int, int> tmp = harr[pos1];
		harr[pos1] = harr[pos2];
		harr[pos2] = tmp;
	}
	void heapify_down(int i) {
		int left = 2*i+1;
		int right = 2*i+2;
		int largest = i;
		if (left < harr.size() && harr[largest].first < harr[left].first)
			largest = left;
		if (right < harr.size() && harr[largest].first < harr[right].first)
			largest = right;
		if (largest != i) {
			pos[harr[largest].second] = i;
			pos[harr[i].second] = largest;
			swap(harr, largest, i);
			heapify_down(largest);
		}
	}
	void heapify_up(int i) {
		int parent = (i-1)/2;
		if (i && harr[parent].first < harr[i].first) {
			pos[harr[parent].second] = i;
			pos[harr[i].second] = parent;
			swap(harr, i, parent);
			heapify_up(parent);
		}
	}
public:
	int max() {
		return (harr.size() == 0) ? 0 : harr[0].first;
	}
	void insert(int height, int index) {
		harr.push_back({height, index});
		pos[index] = harr.size()-1;
		heapify_up(harr.size()-1);
	}
	void increaseKey(int index, int new_height) {
		if (pos.count(index) == 0 || pos[index] >= harr.size()) {
			cout << "invalid index" << endl;
			return;
		}
		int i = pos[index];
		harr[i] = {new_height, index};
		heapify_up(i);
	}
	void remove(int index) {
		increaseKey(index, INT_MAX);
		extractMax();
	}
	int extractMax() {
		if (harr.size() == 0) return 0;
		pair<int, int> root = harr[0];
		pos[harr[0].second] = harr.size()-1;
		pos[harr.back().second] = 0;
		harr[0] = harr.back();
		pos.erase(harr.back().second);
		harr.pop_back();
		heapify_down(0);
		return root.first;
	}
};

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
	vector<Point> points;
	for (int i = 0; i < buildings.size(); i++) {
		points.push_back(Point(1, i, buildings[i][0], buildings[i][2]));
		points.push_back(Point(-1, i, buildings[i][1], buildings[i][2]));
	}
	sort(points.begin(), points.end());
	
	Maxheap heap;
	vector<pair<int, int>> result;
	for (auto p: points) {
		if (p.entering == 1) { // entering point
			if (p.h > heap.max()) 
				result.push_back({p.x, p.h});
			heap.insert(p.h, p.id);
		}
		else { // leaving point
			heap.remove(p.id);
			if (p.h > heap.max())
				result.push_back({p.x, heap.max()});
		}
	}
	return result;
}


void print_arr(vector<pair<int, int>>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << "{" << arr[i].first << ", " << arr[i].second << "}, ";
	cout << endl;
}

int main() {
	vector<vector<int>> buildings = {
		{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}	
	};
	vector<pair<int, int>> res = getSkyline(buildings);
	vector<pair<int, int>> testresult = {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0} };
	if (res == testresult)
		cout << "test passed" << endl;
	else
		cout << "test failed" << endl;
	print_arr(res);
	return 0;
}