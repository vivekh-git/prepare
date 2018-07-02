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

// 1->2->3->4->5->6->Null
// 1->3->5->Null
// 2->4->6->Null
LinkedListNode* altnodesplit(LinkedListNode* pList) {
	if (!pList) return NULL;
	LinkedListNode* pList2 = pList->next;
	LinkedListNode* p1 = pList;
	LinkedListNode* p2 = pList2;
	while (p1 && p1->next) { // check for nulls
		p1->next = p1->next->next; // // check for nulls
		if (p2->next) p2->next = p2->next->next;
		p1 = p1->next;
		p2 = p2->next;
	}
	
	if (p2) {
		p2->next = NULL;
	}
	return pList2;
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

    LinkedListNode* alt = altnodesplit(pList);

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
