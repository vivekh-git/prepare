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


LinkedListNode* reverseK(LinkedListNode* &head, int iK) {
	if (! head) return NULL;
	LinkedListNode* current = head;
	LinkedListNode* prev = NULL;
	LinkedListNode* next = NULL;
	int count = 0;
	while (current && count < iK) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	// iK elements are reversed
	// recurse for next iK elements
	if (next) {
		// return prev and assign to head->next
		head->next = reverseK(current, iK);
	}
	return prev;
}

/*
LinkedListNode* reverseK(LinkedListNode* head, int iK) {
	if (! head) return NULL;
	LinkedListNode* current = head;
	LinkedListNode* next = NULL;
	LinkedListNode* prev = NULL;
	int count = 0;
	while (current && count < iK) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	// iK elements are reversed
	// recurse for next iK elements
	if (next) {
		// return prev and assign to head->next
		head->next = reverseK(next, iK);
	}
	return prev;
}
*/

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

    LinkedListNode* res = reverseK(pList, iK);
	//LinkedListNode* res = pList;
    cout << "main: result3" << endl;
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }

    //fout.close();
    return 0;
}