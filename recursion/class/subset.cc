#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_arr(vector<int>& output, int odx) {
	//cout<< "print_arr - " << odx << endl;
	for (int i = 0; i < odx; i++) {
		cout << output[i] << ", ";
	}
	cout << endl;
}

/*
f(idx, oparr, opidx)
if (idx == len) 
  print output until opidx
else
  f(idx+1, oparr, opidx)
  oparr[opidx] = input[idx]
  f(idx+1, oparr, opidx+1)


*/
// passing by value so that original stack is not popped
void print_stack(stack<int> st) { 
	while (! st.empty()) {
		cout << st.top() << ", ";
		st.pop();
	}
	cout << endl;
}

void subsets2(vector<int>& arr, int idx, stack<int>& st) {
	if (idx == arr.size()) {
		print_stack(st);
	}
	else {
		subsets2(arr, idx+1, st);
		st.push(arr[idx]);
		subsets2(arr, idx+1, st);
		st.pop();
	}
}


void printsubsets2(vector<int>& arr) {
	stack<int> output;
	subsets2(arr, 0, output);
}

void subsets(vector<int>& arr, int idx, vector<int>& output, int odx) {
	//cout <<  "printsubsets - " << idx << ", " << arr.size() << ", " << odx << endl;
	if (idx == arr.size()) {
		// print all elements in output upto odx
		print_arr(output, odx);
	}
	else {
		subsets(arr, idx+1, output, odx);
		output[odx] = arr[idx];
		subsets(arr, idx+1, output, odx+1);
	}
}


void printsubsets(vector<int>& arr) {
	vector<int> output(arr.size());
	subsets(arr, 0, output, 0);
}


int main() {
	vector<int> input = {1, 2, 3};
	printsubsets(input);
	printsubsets2(input);
	return 0;
}