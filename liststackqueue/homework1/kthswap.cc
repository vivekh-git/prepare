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
LinkedListNode* swapNodes(LinkedListNode* pList, int iK) {
	// save the head
	LinkedListNode* head = pList;
	// move iK-1 postion to find firstNode;
	for (int i=0; i< iK-2; i++) {
		pList = pList->next;
	}
	// pList points to one node before source pointer
	LinkedListNode* sourceprev = pList;
	pList = pList->next;
	LinkedListNode* source = pList;
	LinkedListNode* p1 = head;
	// use p2 as pList
	LinkedListNode* destprev = p1;
	while (pList && pList->next) { // check pList or pList->null
		destprev = p1;
		p1 = p1->next;
		pList = pList->next;
	}
	// p1 is at destination
	LinkedListNode* dest = p1;
	
	// swap source and dest
	LinkedListNode* temp = dest->next;
	sourceprev->next = dest;
	if (dest != source->next) {
		dest->next = source->next; // loop
		destprev->next = source;
		source->next = temp;
	}
	else {
		dest->next = source;
		source->next = temp;
	}
    return head;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

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


    int iK;
    cin >> iK;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = swapNodes(pList, iK);
    cout << "result" << endl;
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }

    //fout.close();
    return 0;
}