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

// Push
// MoveNode
// FrontBackSplit
// ShuffleMerge
// altnodesplit
// mergesort_ll
// quicksort_ll
void Push(LinkedListNode* &head, int val) {
	LinkedListNode* newNode = new LinkedListNode(val);
	newNode->next = head;
	head = newNode;
}

void MoveNode(LinkedListNode* &dest, LinkedListNode* &src) {
	if (src) {
		LinkedListNode* newNode = src;
		src = src->next;
		newNode->next = dest;
		dest = newNode;
	}
}


void FrontBackSplit(LinkedListNode* &source, LinkedListNode* &front, LinkedListNode* &back) {
	if (source) {
		LinkedListNode* slow = source;
		LinkedListNode* fast = source->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		front = source;
		back = slow->next;
		slow->next = NULL;
	}
	else {
		front = NULL; back = NULL;
	}
}

LinkedListNode* SortedMerge(LinkedListNode* &a, LinkedListNode* &b) {
	LinkedListNode dummy(-1); LinkedListNode* tail = &dummy;
	while (a && b) {
		if (a->val <= b->val) {
			MoveNode(tail->next, a);
			tail = tail->next;
		}
		else {
			MoveNode(tail->next, b);
			tail = tail->next;
		}
	}
	if (a) {tail->next = a;}
	else if (b) {tail->next = b;}
	return dummy.next;
}

void mergesort(LinkedListNode* &head) {
	if (!head || !head->next) return;
	LinkedListNode* front = NULL;
	LinkedListNode* back = NULL;
	FrontBackSplit(head, front, back);
	mergesort(front);
	mergesort(back);
	head = SortedMerge(front, back);
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
	
    LinkedListNode* curr = pList;	
    cout << "input list" << endl;
    while (curr != NULL) {
        cout << curr->val << endl;
        curr = curr->next;
    }
    

    //LinkedListNode* alt = altnodesplit(pList);
	mergesort(pList);

    cout << "sorted list" << endl;
    while (pList != NULL) {
        cout << pList->val << endl;
        pList = pList->next;
    }


    return 0;
}
