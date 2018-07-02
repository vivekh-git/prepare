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

// swapping node1 and node2

void swapnode(LinkedListNode*& head, LinkedListNode* prev1, LinkedListNode* node1, LinkedListNode* prev2, LinkedListNode* node2) {
	if (!node1 || !node2) return;
	
    if(!prev1)
    {
        head = node2;
    } else {
        prev1->next = node2;
    }

    if (!prev2)
    {
        head = node1;
    } else {
        prev2->next = node1;
    }
    
    LinkedListNode* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
	
}


LinkedListNode* swapNodes(LinkedListNode* pList, int iK) {
	
	if (!pList || iK < 0) {
		//cout << "pList null - " << iK << endl;
		return NULL;
	}

	// save the head
	LinkedListNode* head = pList;
	/*
    cout << "swapNodes: result1" << endl;
	LinkedListNode* res1 = head;
    while (res1 != NULL) {
        cout << res1->val << endl;
        res1 = res1->next;
    }*/
	
	LinkedListNode* sourceprev = NULL;
	
	// move iK-1 postion to find firstNode;
	for (int i=0; i< iK-1; i++) {
		sourceprev = pList;
		pList = pList->next;
	}
	LinkedListNode* source = pList;
	
	
	LinkedListNode* p1 = head;
	// use p2 as pList
	LinkedListNode* destprev = NULL;
	LinkedListNode* dest = head;
	while (pList && pList->next) { // check pList or pList->null
		destprev = dest;
		dest = dest->next;
		pList = pList->next;
	}
	
	// swap source and dest
    swapnode(head, sourceprev, source, destprev, dest);
	
	/*
    cout << "swapNodes: result2" << endl;
	LinkedListNode* res = head;
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }*/
    return head;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    
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

    LinkedListNode* res = swapNodes(pList, iK);
	//LinkedListNode* res = pList;
    cout << "main: result3" << endl;
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }

    //fout.close();
    return 0;
}