#include <iostream>
#include <list>

using namespace std;

#include <bits/stdc++.h>

using namespace std;
class LinkedListNode {
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
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

// handled
// 1-2-3-4-5->NULL
// s=1, f=1
// s=2, f=3
// s=3, f=5
// return 3 // end of first list - make 3-> next = null, make 3->next - start of second list


// 1-2-3-4-5-6->NULL
// s=1, f=1
// s-2, f-3
// s-3, f=5 // end of first list
// s-4, f=NULL // 
LinkedListNode* nodesplit(LinkedListNode* pList) {
	LinkedListNode* slowprev = pList;
	LinkedListNode* slow = pList;
	LinkedListNode* fast = pList;
	while (fast != NULL) {
		if (! fast->next) { // reached end of list
			LinkedListNode* h = slow->next;
			slow->next = NULL;
			return h;
		}
		slowprev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow) {
		slowprev->next = NULL;
		return slow;
	}
	else return NULL;
}


int main()
{
    LinkedListNode* res;
    int pList_size = 0;

    LinkedListNode* pList = NULL;
    LinkedListNode* pList_tail = NULL;

    cin >> pList_size;

    for(int i = 0; i < pList_size; i++) {
        int pList_item;
        cin >> pList_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pList_tail = _insert_node_into_singlylinkedlist(pList, pList_tail, pList_item);

        if(i == 0) {
            pList = pList_tail;
        }
    }

    LinkedListNode* alt = nodesplit(pList);

    cout << "first list" << endl;
    while (pList != NULL) {
        cout << pList->val << endl;
        pList = pList->next;
    }


    cout << "second list" << endl;
    while (alt != NULL) {
        cout << alt->val << endl;
        alt = alt->next;
    }

    return 0;
}