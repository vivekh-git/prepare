#include <iostream>
#include <queue>
#include <functional>

using namespace std;




// 0, 1
// 0, 2
int main() {
	int a[] = { 0, 1, 0, 2};
	priority_queue<int, vector<int> , std::greater<int>> q(a,a+4);
	cout << q.top() << ", "; q.pop();
	
	//q.push(1);
	cout << q.top() << ", "; q.pop();
	
	//q.push(5);
	cout << q.top() << ", "; q.pop();
	cout << q.top() << ", "; q.pop();
	return 0;
}
