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

class mycompare {
public:
  bool operator() (LinkedListNode* lhs, LinkedListNode* rhs)  {
      if (lhs && rhs)
          return (lhs->val > rhs->val);
      else
          return false;
  }
};


LinkedListNode* mergeKLists(vector<LinkedListNode*>& lists) {
        if (lists.empty()) return NULL;
        priority_queue<LinkedListNode*, vector<LinkedListNode*>, mycompare> q;
        
        for (int i = 0; i < lists.size(); i++) {
            // lists[i] is the head of sublists
			if (lists[i])
            	q.push(lists[i]);
        }
        
		if (q.empty()) return NULL;
        LinkedListNode* head = q.top(); q.pop();
        LinkedListNode* node = head;
        if (head->next) q.push(head->next);
        while(!q.empty()) {
            LinkedListNode* qnode = q.top(); q.pop();
            node->next = qnode;
            node = node->next;
            if (qnode->next) q.push(qnode->next);
        }
        return head;
}

/*
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    vector<vector<int>> arr = {{1,4,5}, {1,3,4}, {2,6}};
	vector<LinkedListNode*> input;

    for(int i = 0; i < arr.size(); i++) {
	    LinkedListNode* pList = NULL;
	    LinkedListNode* pList_tail = NULL;
		for (int j = 0; j < arr[i].size(); j++) {
        	pList_tail = _insert_node_into_singlylinkedlist(pList, pList_tail, arr[i][j]);
        	if(j == 0) {
            	pList = pList_tail;
        	}
		}
		input.push_back(pList);
    }
	
	for (int i = 0; i < input.size(); i++) {
		LinkedListNode* n = input[i];
		while (n != NULL) {
			cout << n->val << " ";
			n = n->next;
		}
		cout << endl;
	}


    LinkedListNode* res = mergeKLists(input);
        //LinkedListNode* res = pList;
    cout << "main: result" << endl;
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }

    //fout.close();
    return 0;
}
