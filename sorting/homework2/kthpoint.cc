#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

struct point {
	int x;
	int y;
	point(int x1, int y1): x(x1), y(y1) {}
	void operator=(const point& other) {
		x = other.x;
		y = other.y;
	}
	int sqrdist(const point& other) {
		return (x-other.x) * (x-other.x) + (y-other.y)* (y-other.y);
	}
};

struct node {
    point p;
	int distance;
	node(point p1, int dist): p(p1), distance(dist) {}
	void operator=(const node& other) {
		p = other.p;
		distance = other.distance;
	}
};


void swap(vector<node>& arr, int pos1, int pos2) {
	node temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(vector<node>& arr, int st, int end) {
	int low = st+1;
	int high = st+1;
	while (high <= end) {
		// node comparison needed
		if (arr[high].distance < arr[st].distance) {
			swap(arr, low, high);
			low++;
		}
		high++;
	}
	swap(arr, low-1, st);
	return low-1;
}

/*

		if (pivot == k) {
			return arr[pivot];
		}
		else if (pivot > k) {
			return findk(arr, st, pivot-1, k);
		}
		else {
			return findk(arr, pivot+1, end, k);
		}

*/
void findkpoints(vector<node>& arr, int st, int end, int k) {
	//cout << "findk: " << st << " : " << end << " : " << k << endl;
	if (end >= st) {
		int pivot = partition(arr, st, end);
		if (pivot >= k) {
			findkpoints(arr, st, pivot-1, k);
		}
		else {
			findkpoints(arr, pivot+1, end, k);
		}
			//}
	}
}

void print_points_with_dist(vector<node>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << "(" << arr[i].p.x << ", " << arr[i].p.y << ") - " << arr[i].distance << endl;
	}
}


void print_points(vector<point>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << "(" << arr[i].x << ", " << arr[i].y << ")" << endl;
	}
}

int main() {
    vector<point> arr =  { {92, 45}, {67, 41}, {74, 28}, {87, 8}, {67, 15}, {59, -1} };
    //print_points(arr);
	
	vector<node> anodes;
	for (int i = 0; i < arr.size(); i++) {
		// arr[i] is a point
		int dist = arr[i].sqrdist(point(66, 14));
		anodes.push_back(node(arr[i], dist));
	}

    //print_points_with_dist(anodes);
    int rank = 2;
    findkpoints(anodes, 0, anodes.size()-1, rank-1);
	//print_points_with_dist(anodes);
	for (int i=0; i<rank; i++) {
		cout << "(" << anodes[i].p.x << "," << anodes[i].p.y << ")" << endl;
	}

    return 0; 
}