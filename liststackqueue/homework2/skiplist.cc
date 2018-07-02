#include <bits/stdc++.h>

using namespace std;
class LinkedListNode {
public:
    int val;
    LinkedListNode *next;
	LinkedListNode *down;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
		down = NULL;
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


LinkedListNode*  insert(LinkedListNode*  n, int v) {
    LinkedListNode*  prev = traverse(n, v);
    if (prev.down == NULL) {
      return insert(prev, v);
    } else {
      LinkedListNode*  inserted = insert(prev, v);
      if (inserted != null && flipCoin()) {
        return insert(prev, v);
      }
      return prev;
    }
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