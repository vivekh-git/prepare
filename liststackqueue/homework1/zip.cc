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

/*
1->2->3->4->NULL
// r(null, 4) // make head point to prev head -> 4
// r(4,3). // 4->3
// r(3,2). // 3->2
// r(2,1)  // 2->1
// r(1,1). // 1->null
// recurse (null, 4) = 4
// recurse(4, 3)
//      p = recurse(null, 4) = 4
//      4->next = prev;  4->next = 3
//.     return 4
// recurse (3, 2)
//.     p = recurse(4, 3) = 4
//.     4->next = 2

node* recurse(node* head, node* prev) {
   if (!head) return prev;
   node* p = recurse(head->next, head);
   p->next = prev
   return p;
}


*/
LinkedListNode* reverselist(LinkedListNode* head, LinkedListNode* prev) {
	if (!head)  {
		// prev is the head of reversed list - return and store as new head
		return prev;
	}   
	LinkedListNode* rhead = reverselist(head->next, head);
	head->next = prev;
	if (prev) { // prev cannot become null
		prev->next = NULL;
	}
	return rhead;
}	



// 1->2->3->4->5->6
// 1->6->2->5->3->4
LinkedListNode* Zip(LinkedListNode* pList) {
	LinkedListNode* pList2 = nodesplit(pList);
	LinkedListNode* rList2 = reverselist(pList2, pList2);
	

	LinkedListNode* p1 = pList;
	LinkedListNode* p2 = rList2;

	// interspersing the 2 lists
	LinkedListNode* ret = pList;
	while (pList && rList2) { // check these conditions later
		LinkedListNode* temp1 = pList->next;
		LinkedListNode* temp2 = rList2->next;
		pList->next = rList2;
		rList2->next = temp1;
		pList = temp1;
		rList2 = temp2;
	}
	
	return ret;
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

    LinkedListNode* res = Zip(pList);
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }

    //fout.close();
    return 0;
}