#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
    map<int, int> _booking;
public:
    MyCalendar() : _booking() {
		cout << "constructor" << endl;
    }
    
    void print() {
        for (map<int,int>::iterator it=_booking.begin(); it!=_booking.end(); ++it)
            cout << it->first << " => " << it->second << '\n';
        cout << endl;
    }
    
    // [[],[10,20],[15,25],[20,30]] - t, f, t
    // 10,20
    // 15,25 -> low->end(), high->end()
    bool book(int start, int end) {
		cout << "book" << endl;
        map<int,int>::iterator next = _booking.upper_bound(start);
		// 47-50
		// 33-41, pre-47, 50 <= 33
		map<int,int>::iterator pre = next;
		if (next != _booking.begin())
			pre--;	
        if ((pre == _booking.end() || pre->second <= start || pre->first >= end) &&
		     (next == _booking.end() || next->second <= start || next->first >= end)) {
            // all elements have first less than start & elements smaller than start either do not exist.
            // or check for one before (prev) second < start
            _booking[start] = end;
            print();
            return true;
        }
		return false;
    }
};


int main() {
	MyCalendar obj;
	// ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
    // [47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
	cout << "47,50" << obj.book(47,50) << endl;
	cout << "33,41" << obj.book(33,41) << endl;
	cout << "39,45" << obj.book(39,45) << endl;
	cout << "33,42" << obj.book(33,42) << endl;
	cout << "25,32" << obj.book(25,32) << endl;
	cout << "25,32" << obj.book(26,35) << endl;
	cout << "19,25" << obj.book(19,25) << endl;
	cout << "3,8" << obj.book(3,8) << endl;
	cout << "8,13" << obj.book(8,13) << endl;
	cout << "18,27" << obj.book(18,27) << endl;
	return 0;
}