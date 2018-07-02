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
int listlen(LinkedListNode* head) {
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

LinkedListNode* moveNode(LinkedListNode* curr, int dist) {
    while (dist) {
        curr = curr->next;
		dist--;
	}
	return curr;
}

int find_intersection(LinkedListNode* l1, LinkedListNode* l2) {
    if (!l1 || !l2) return -1;
    int len1 = listlen(l1);
	cout << "len1 - " << len1 << endl;
    int len2 = listlen(l2);
	cout << "len2 - " << len2 << endl;
    int dist = abs(len1-len2);
	cout << "dist - " << dist << endl;
    LinkedListNode* curr = NULL;
    if (len2 > len1) {
        curr = l2;
        curr = moveNode(curr, dist);
		cout << "data after move - " << curr->val << endl;
        while (curr && l1) {
            if (curr && l1 && curr == l1)
                return curr->val;
            curr = curr->next;
            l1 = l1->next; 
        }
        return -1;
    }
    else {
        curr = l1;
        curr = moveNode(curr, dist);
		cout << "after move node" << endl;
        while (curr && l2) {
            if (curr && l2 && curr == l2)
                return curr->val;
			cout << "inside while, curr - " << curr->val << ", l2 - " << l2->val << endl;
            curr = curr->next;
            l2 = l2->next;
        }
        return -1;
    }
}


int main()
{
    //ostream &fout = cout;

    int res;
    int l1_size = 0;

    LinkedListNode* l1 = NULL;
    LinkedListNode* l1_tail = NULL;

    cin >> l1_size;

    for(int i = 0; i < l1_size; i++) {
        int l1_item;
        cin >> l1_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item);

        if(i == 0) {
            l1 = l1_tail;
        }
    }


    int l2_size = 0;

    LinkedListNode* l2 = NULL;
    LinkedListNode* l2_tail = NULL;

    cin >> l2_size;

    for(int i = 0; i < l2_size; i++) {
        int l2_item;
        cin >> l2_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item);

        if(i == 0) {
            l2 = l2_tail;
        }
    }

    //----added manually----
    int merge_at;
    cin >> merge_at;
    LinkedListNode* l1_temp = l1;
    for (int i = 0; i < merge_at; i++)
    {
        l1_temp = l1_temp->next;        
    }
    if (l2_tail == NULL)
    {
        l2 = l1_temp;
    }
    else
    {
        l2_tail->next = l1_temp;     
    }
    //--------
    
    res = find_intersection(l1, l2);
    cout << res << endl;

    
    return 0;
}
