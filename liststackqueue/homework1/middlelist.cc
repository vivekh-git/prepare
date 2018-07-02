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
// slow and fast pointer
int findMiddleNode(LinkedListNode* pList) {
	LinkedListNode* slow = pList;
	LinkedListNode* fast = pList;
	while (fast != NULL) {
		if (! fast->next) return slow->val;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow) return slow->val;
	else return -1;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int res;
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


    res = findMiddleNode(pList);
    fout << res << endl;

    fout.close();
    return 0;
}
