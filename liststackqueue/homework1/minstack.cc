#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class MinStack {
private:
  stack<int> _st;
  stack<int> _minst;

public:
  void push(int n) {
	  _st.push(n);
	  if (_minst.size() == 0 || n <= _minst.top())
		  _minst.push(n);
  }
 
  int top() {
      if (_st.size() > 0) return _st.top();
	  else return -1;
  }

  void pop() {
	  if (_st.size() > 0) {
		  if (_st.top() == _minst.top()) {
			  _st.pop(); _minst.pop();
		  }
		  else {
			  _st.pop();
		  }
	  }
  }

  int getMin() {
	  if (_minst.size() > 0)
		  return _minst.top();
	  else
		  return -1;
  }
};


int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	string str;
	
	getline(cin, str);

    vector<int> vect;
    stringstream ss(str);

    int i;
    while (ss >> i) {
		vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    MinStack ms;
    for (i=0; i< vect.size(); i++)
        ms.push(vect.at(i));
	
	
	fout << ms.getMin() << endl;
	fout.close();
	return 0;
}

/*
int main() {
  MinStack ms;
  cout << "empty stack, min - " << ms.getMin() << endl;
  int input;
  cin >> input;
  ms.push(input);
  cin >> input;
  ms.push(input);
  cout << "4, 1 in stack, min - " << ms.getMin() << endl;
  ms.push(2);
  ms.push(1);
  cout << "4, 1, 2, 1 in stack, min - " << ms.getMin() << endl;
  ms.push(3);
  cout << "4, 1, 2, 1, 3 in stack, min - " << ms.getMin() << endl;
  ms.pop();
  ms.pop();
  cout << "4, 1, 2 in stack, min - " << ms.getMin() << endl;
  ms.pop();
  ms.pop();
  cout << "4 in stack, min - " << ms.getMin() << endl;
  ms.pop();
  cout << "empty stack, min - " << ms.getMin() << endl;
  return 0;
}*/



