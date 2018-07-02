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
	LinkedListNode *arbit;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
		arbit = NULL;
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

/* go through the list, create a clone and store a map of orig to clone
 * go through list again and create next / arbit pointers for clone
 */
LinkedListNode* clone2(LinkedListNode* head) {
	unordered_map<LinkedListNode*, LinkedListNode*> origclonemap;
	LinkedListNode* curr = head;
	while (curr) {
		LinkedListNode* newNode = new LinkedListNode(curr->val);
		origclonemap[curr] = newNode;
		curr=curr->next;
	}
	curr = head;
	while(curr) {
		origclonemap[curr]->next = origclonemap[curr->next];
		origclonemap[curr]->arbit = origclonemap[curr->arbit];
		curr=curr->next;
	}
	return origclonemap[head];
}


/* O(1) space and O(n) time complexity
 * create a clone node and make it next of each orig node
 *
 */ 
LinkedListNode* clone(LinkedListNode* head) {
	LinkedListNode* curr = head; 
	LinkedListNode* temp;
	// create a clone node and make it next of each orig node
	while (curr) {
		temp = curr->next;
		curr->next = new LinkedListNode(curr->val);
		curr->next->next = temp;
		curr = temp;
	}
	// adjust arbit pointers
	curr = head;
	while (curr) {
		// curr->next-arbit = curr->arbit->next sets the arbit for clone nodes
		if (curr->arbit) curr->next->arbit = curr->arbit->next;
		curr = (curr->next) ? curr->next->next : curr->next;
	}
	// adjust next pointers
	curr = head; LinkedListNode* clone = curr->next; LinkedListNode* clone_head= clone;
	while (curr) {
		curr->next = (curr->next) ? curr->next->next : curr->next;
		clone->next = (clone->next) ? clone->next->next: clone->next;
		curr=curr->next; clone=clone->next;
	}
	return clone_head;
}


void print(LinkedListNode* head)
{
    LinkedListNode* curr = head;
    while (curr)
    {
        cout << "val = " << curr->val << ", arbit  = "
             << curr->arbit->val << endl;
        curr = curr->next;
    }
}

int main()
{
    LinkedListNode* head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = new LinkedListNode(5);
 
    // 1's arbit points to 3
    head->arbit = head->next->next;
 
    // 2's arbit points to 1
    head->next->arbit = head;
 
    // 3's and 4's arbit points to 5
    head->next->next->arbit =
                    head->next->next->next->next;
    head->next->next->next->arbit =
                    head->next->next->next->next;
 
    // 5's arbit points to 2
    head->next->next->next->next->arbit =
                                      head->next;
 
    cout << "Original list : \n";
    print(head);
 
    cout << "\nCloned list : \n";
    LinkedListNode* cloned_list = clone(head);
    print(cloned_list);
 
    return 0;
}