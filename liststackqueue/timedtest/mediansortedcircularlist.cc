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
int find_median(LinkedListNode* ptr) {
	if (!ptr) return -1;
	vector<int> countarr (20);
	
	LinkedListNode* runner = ptr;
	countarr[runner->val] = countarr[runner->val] + 1;
	
	runner = runner->next;
	while (runner != ptr) {
	 	countarr[runner->val] = countarr[runner->val] + 1;
		runner = runner->next;
	}

	
	int numelements = 0;
	for (int i = 0; i< countarr.size(); i++) {
		numelements += countarr[i];
	}
	
	if (numelements % 2 != 0) {
		// odd number of elements
		int pos = numelements / 2 + 1;
		int mediansum = 0; int i = 0;
		for (int i = 0; i< countarr.size(); i++) {
			mediansum += countarr[i];
			if (mediansum == pos) {
				// i is the median
				return i;
			}
		}
	}
	else {
		// even number of elements
		int pos1 = numelements / 2;
		int mediansum = 0; int i=0;
		for (i = 0; i< countarr.size(); i++) {
			mediansum += countarr[i];
			if (mediansum == pos1) {
				// i is the median
				break;
			}
		}
		int j = i+1;
		while (true) {
			if (countarr[j] != 0) {
				break;
			}
			j++;
		}
		return (i+j)/2;
	}
	return -1;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    int ptr_size = 0;

    LinkedListNode* ptr = NULL;
    LinkedListNode* ptr_tail = NULL;

    cin >> ptr_size;

    for(int i = 0; i < ptr_size; i++) {
        int ptr_item;
        cin >> ptr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ptr_tail = _insert_node_into_singlylinkedlist(ptr, ptr_tail, ptr_item);

        if(i == 0) {
            ptr = ptr_tail;
        }
    }

    //----added manually----
    ptr_tail->next = ptr;															// Till now it was linear, now join tail to head and make it circular. 
    // Now we have got circular linked list but ptr will be the first element, but we need to give arbitrary node. 
    // Value of arbitrary_shift will be [0, ptr_size). 
    int arbitrary_shift;                 											 
    scanf("%d", &arbitrary_shift);
    while (arbitrary_shift--)
    {
        ptr = ptr->next;
    }
    //--------

    res = find_median(ptr);
    cout << res << endl;

    //fout.close();
    return 0;
}