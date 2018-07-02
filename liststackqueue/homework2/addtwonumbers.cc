#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class LinkedListNode{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* addNumbers(LinkedListNode* l1, LinkedListNode* l2) {
	// find the list the larger of the two
	int carry = 0;  
	LinkedListNode* _lsum = NULL; LinkedListNode* _lsum_tail = NULL;
	int i = 0;
	while (l1 || l2) {
		int sumdigit = 0; // resetting
		int digit = 0;
		if (l1) sumdigit += l1->val;
		if (l2) sumdigit += l2->val;
		sumdigit += carry;
		cout << "sumdigit - " << sumdigit << endl;
		digit = sumdigit % 10;
		carry = sumdigit / 10;
		// add this to the longer of 2 lists;
		if (i == 0) {
			_lsum = _insert_node_into_singlylinkedlist(_lsum, _lsum_tail, digit);
			_lsum_tail = _lsum;
		}
		else {
			_lsum_tail = _insert_node_into_singlylinkedlist(_lsum, _lsum_tail, digit);
		}
		i++;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;		
	}
	if (carry) {
		_lsum_tail = _insert_node_into_singlylinkedlist(_lsum, _lsum_tail, carry);
	}
    return _lsum;
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    
    int _l1_size = 0;
    int _l1_item;
    LinkedListNode* _l1 = NULL;
    LinkedListNode* _l1_tail = NULL;
    cin >> _l1_size;
    int _l1_i;
    for(_l1_i = 0; _l1_i < _l1_size; _l1_i++) { 
        cin >> _l1_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        if(_l1_i == 0) {
    		_l1 = _insert_node_into_singlylinkedlist(_l1, _l1_tail, _l1_item);
    		_l1_tail = _l1;
    	}
        else {
    	    _l1_tail = _insert_node_into_singlylinkedlist(_l1, _l1_tail, _l1_item);
        }
    }
    
    
    int _l2_size = 0;
    int _l2_item;
    LinkedListNode* _l2 = NULL;
    LinkedListNode* _l2_tail = NULL;
    cin >> _l2_size;
    int _l2_i;
    for(_l2_i = 0; _l2_i < _l2_size; _l2_i++) { 
        cin >> _l2_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        if(_l2_i == 0) {
    	_l2 = _insert_node_into_singlylinkedlist(_l2, _l2_tail, _l2_item);
    	_l2_tail = _l2;
    	}
        else {
    	    _l2_tail = _insert_node_into_singlylinkedlist(_l2, _l2_tail, _l2_item);
        }
    }
    
    LinkedListNode* res = addNumbers(_l1, _l2);
    while (res != NULL) {
        cout << res->val << endl;
        
        res = res->next;
    }
    
    //fout.close();
    return 0;
}
