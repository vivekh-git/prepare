#include <bits/stdc++.h>

using namespace std;

class Maxheap {
private:
	vector<pair<char, int>> harr;
	unordered_map<char, int> pos;
	void swap(vector<pair<char, int>>& harr, int pos1, int pos2) {
		pair<char, int> tmp = harr[pos1];
		harr[pos1] = harr[pos2];
		harr[pos2] = tmp;
	}
	void heapify_down(int i) {
		//if (i >= harr.size()) { cout << "invalid i in heapify_down" << endl; return;}
		int left = 2*i+1;
		int right = 2*i+2;
		int largest = i;
		if (left < harr.size() && harr[left].second > harr[i].second)
			largest = left;
		if (right < harr.size() && harr[right].second > harr[i].second)
			largest = right;
		if (largest != i) {
			// swap largest and i
			pos[harr[largest].first] = i;
			pos[harr[i].first] = largest;
			swap(harr, i, largest);
			heapify_down(largest);
		}
	}
	void heapify_up(int i) {
		int parent = (i-1)/2;
		if (i && harr[i].second > harr[parent].second) {
			// swap parent and i
			pos[harr[i].first] = parent;
			pos[harr[parent].first] = i;
			swap(harr, parent, i);
			heapify_up(parent);
		}
	}
public:
	bool empty() { return harr.empty(); }
	void insert(char ch, int val) {
		harr.push_back({ch, val});
		pos[ch] = harr.size()-1;
		heapify_up(harr.size()-1);
	}
	void increaseKey(char ch) {
		if (pos.count(ch) == 0 || pos[ch] >= harr.size()) { cout << "invalid ch in increaseKey" << endl; return ;}
		int i = pos[ch];
		pair<char, int> node = harr[i];
		int newval = node.second +1;
		harr[i] = {node.first, newval};
		heapify_up(i);
	}
	pair<char, int> extractMax() {
		if (empty()) return {'0', 0};
		pair<char, int> root = harr[0];
		// swap 0 and last element size()-1
		pos[harr[0].first] = harr.size()-1;
		pos[harr.back().first] = 0;
		harr[0] = harr.back();
		harr.pop_back();
		heapify_down(0);
		return root;
	}
};

class Util {
public:
	void encode(string& str, int d) {
		unordered_set<char> dict;
		Maxheap heap;
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			if (dict.count(ch) == 0) {
				dict.insert(ch);
				//cout << "inserting into heap, " << ch << " -- 1 " << endl;
				heap.insert(ch, 1);
			}
			else {
				heap.increaseKey(ch);
			}
			str[i] =  ' ';
		 }
		 int start = 0;
		 //cout << "str length" << str.length() << endl;
		 
		 while (!heap.empty()) {
			 while (str[start] != ' ') start++;
			 pair<char, int> node = heap.extractMax();
			 //cout << "str - " << str << endl;
			 //cout << "start - " << start << endl;
			 //cout << "node pair - " << node.first << " -- " << node.second << endl;
			 for (int i = 0; i < node.second; i++) {
				 if (start + i*d >= str.length()) {
					 str = ""; return;
				 }
				 str[start + i*d] = node.first;
			 }
			 //cout << "str - " << str << endl;
			 start++;
		 }
	}
};


// Driver program to test above function
int main() {
    string str = "daaaaddbfaffd";
 	//string str = "daaaaddbfaffda";
	int d = 3;
	cout << "str - " << str << endl;
	Util util;				
    util.encode(str, d);
	cout << "encoded str - " << str << endl;
    return (0);
}