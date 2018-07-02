#include <bits/stdc++.h>

using namespace std;

void MoveOld(int num, char src, char dest, char helper) {
	if (num == 1) {
		cout << "Internal Move disk " << num << " from " << src << " -> " << dest  << endl;
		return;
	}
	MoveOld(num-1, src, helper, dest);
	cout << "External Move disk " << num << " from " << src << " -> " << dest << endl;
	MoveOld(num-1, helper, dest, src);
	return;
}

void PrintStacks(stack<int> src, stack<int> dest, stack<int> helper, int step) {
	cout << "step: " << step << endl;
	for (int i=0; i<src.size(); i++) {
		cout << "[" << src.top() << ",";
		src.pop();
	}
	cout << "]" << endl;
	for (int i=0; i<dest.size(); i++) {
		cout << "[" << dest.top() << ",";
		dest.pop();
	}
	cout << "]" << endl;
	for (int i=0; i<helper.size(); i++) {
		cout << "[" << helper.top() << ",";
		helper.pop();
	}
	cout << "]" << endl;
}

void MoveDisk(stack<int>& src, stack<int>& dest) {
	int n = src.top(); src.pop();
	dest.push(n);
}

void Move(stack<int>& src, stack<int>& dest, stack<int>& helper, int& step) {
	if (src.size() == 1) {
		++step;
		MoveDisk(src, dest);
		PrintStacks(src, dest, helper, step);
		return;
	}
	if (src.size() !=  1) {
		int pop = src.top(); src.pop();
		Move(src, helper, dest, step);
	}
	MoveDisk(src, dest);
	PrintStacks(src, dest, helper, step);
	Move(helper, dest, src, step);
	return;
}

void towerofhanoi(int num) {
	stack<int> s1, s2, s3;
	for (int i = 0; i < num; i++) {
		s1.push(num-i);
	}
	int step = 0;
	PrintStacks(s1,s2,s3, step);
	Move(s1, s2, s3, step);
}


int main () {
	int num;
	cin >> num;
	//towerofhanoi(num);
	MoveOld(num, 'A', 'C', 'B');
	return 0;
}
