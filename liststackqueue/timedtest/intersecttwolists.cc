#include <bits/stdc++.h>
#include <unordered_map>

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
// use count arrays
int find_intersection(LinkedListNode* l1, LinkedListNode* l2) {
	unordered_map<LinkedListNode*, bool> mnodes1;
	unordered_map<LinkedListNode*, bool> mnodes2;
	while (l1 || l2) { // check this condition
		// add l1 to hash
		if (l1) mnodes1[l1] = true;
		if (l2) mnodes2[l2] = true;
		// check for l2 nodes in hash
		if (l2 && mnodes1.count(l2) != 0) {
			// l2 node exists in hash
			//l2 node is the intersection
			return l2->val;	
		}
		else if (l1 && mnodes2.count(l1) != 0) {
			return l1->val;
		}
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
    return -1;
}




int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

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

    //fout.close();
    return 0;
}

