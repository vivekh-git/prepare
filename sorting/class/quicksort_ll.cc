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

LinkedListNode* getTail(LinkedListNode* head) {
	LinkedListNode* curr = head;
	while (curr && curr->next) {
		curr = curr->next;
	}
	return curr;
}

/*
int partition2(vector<int>& arr, int start, int end) {
	int lo = start;
	int hi = start;
	int pivot = arr[end];
	while (hi <= end-1) {
		if (arr[hi] < pivot) {
			swap(arr, lo, hi);
			lo++; hi++;
		}
		else {
			hi++;
		}
	}
	swap(arr, end, lo);
	return lo;
}
*/
LinkedListNode* partition(LinkedListNode* &head, LinkedListNode* &prev, LinkedListNode* &end) {
	LinkedListNode* pivot = end;
	LinkedListNode* curr = head; LinkedListNode* next;
	LinkedListNode* newHead = NULL; LinkedListNode* newEnd = pivot;
	while(curr && curr != pivot) {
		next = curr->next;
		if (curr->val > pivot->val) {
			if (prev) prev->next = next;
			newEnd->next = curr; curr->next = NULL; newEnd = curr;
			curr = next;
		}
		else {
			if (!newHead) newHead = curr;
			prev = curr;
			curr = next;
		}
	}
	if (!newHead) newHead=pivot;
	head = newHead;
	end = newEnd;
	return pivot;
}


void _quicksort(LinkedListNode* &head, LinkedListNode* &end) {
	if (head && head != end) {
		LinkedListNode* prepivot = NULL;
		LinkedListNode* pivot = partition(head, prepivot, end);
		if (head != pivot) {
			prepivot->next = NULL;
			_quicksort(head, prepivot);
			prepivot->next = pivot;
		}
		_quicksort(pivot->next, end);
	}
}

/*
void _qsort(vector<int>& arr, int start, int end) {
	if (end > start) {
		int pivot = partition2(arr, start, end);
		_qsort(arr, start, pivot-1);
		_qsort(arr, pivot+1, end);
	}
}
*/
void quicksort(LinkedListNode* &head) {
	LinkedListNode* end = getTail(head);
	_quicksort(head, end);
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
	quicksort(pList);

    cout << "sorted list" << endl;
    while (pList != NULL) {
        cout << pList->val << endl;
        pList = pList->next;
    }


    return 0;
}
