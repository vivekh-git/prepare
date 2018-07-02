#include <iostream>
#include <stack>


class Queue {
private:
	stack<int> main;
	stack<int> buffer;
public:
	void enqueue();
	int dequeue();
	int size();
	int peek();
};






int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(3);
	int d1 = q.dequeue();
	cout << "d1 - " << d1 << endl
	
	q.enqueue(4);
	q.enqueue(7);
	int d2 = q.dequeue();
	cout << "d2 - " << d2 << endl	
	return 0;	
}