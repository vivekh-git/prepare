#include <bits/stdc++.h>
using namespace std;


// Complete the findMaxPossibleArea function below.
long findMaxPossibleArea2(vector<long> heights, int l, int r) {
    long max = 0;
    for (int i = l; i <= r; i++) {
        int left = i-1; int right = i+1;
        while (left >=0 && heights[left] >= heights[i])
            left--;
        while (right < heights.size() && heights[right] >= heights[i])
            right++;
        left++; right--;
        if (left < 0) left = 0;
        if (right == heights.size()) right = heights.size()-1;
        int sub = (right-left+1) * heights[i];
        if (sub > max) max = sub;
    }
    return max;
}


long findMaxPossibleArea(vector<long> heights, int l, int r) {
	stack<int> st; long maxarea = 0;
	int i, left, right, topofstack, width, area;
	for (i=l; i <=r; ) {
		if (st.empty() || heights[st.top()] <= heights[i]) {
			// larger items are pushed on top in stack
			st.push(i);
			i++;
		}
		else {
			// when new item is smaller - that item i is the right bound.
			right = i;
			topofstack = st.top(); st.pop();
			left = st.empty() ? -1 : st.top();
			width = right - left - 1;
			area = heights[topofstack] * width;
			if (area > maxarea)
				maxarea = area;
		}
	}
	while (!st.empty()) {
		right = i;
		topofstack = st.top(); st.pop();
		left = st.empty() ? -1 : st.top();
		width = right - left - 1;
		area = heights[topofstack] * width;
		if (area > maxarea)
			maxarea = area;
	}
	return maxarea;
}


int largestRectangleArea(vector<int>& heights) {
	stack<int> st; int maxarea = 0;
	int topofstack, width;
	for (int i=0; i < heights.size(); i++) {
		if (st.empty() || heights[st.top()] <= heights[i]) {
			st.push(i);
		}
		else {
			// when new item is smaller - that item i is the right bound.
			topofstack = st.top(); st.pop();
			width = st.empty() ? i : i - st.top() - 1;
			maxarea = max(maxarea, heights[topofstack] * width);
			i--;
		}
	}
	while (!st.empty()) {
		topofstack = st.top(); st.pop();
		width = st.empty() ? heights.size() : heights.size() - st.top() - 1;
		maxarea = max(maxarea, heights[topofstack] * width);
	}
	return maxarea;
}


// Segment Tree implementation
struct node {
	int data;
	int start;
	int end;
	node* left;
	node* right;
	node(int d, int l, int r) {
		data = d; start = l; end = r;
		left = right = NULL;
	}
};


node* buildSTreeUtil(vector<long>& heights, int left, int right) {
	if (left > right) return NULL;
	if (left == right) {
		node* n = new node(left, left, right);
		return n;
	}
	int mid = left + (right - left)/2;
	node* lnode = buildSTreeUtil(heights, left, mid);
	node* rnode = buildSTreeUtil(heights, mid+1, right);
	int index = (heights[lnode->data] < heights[rnode->data]) ? lnode->data : rnode->data;
	node* n = new node(index, left, right);
	n->left = lnode;
	n->right = rnode;
	return n;
}

void printTree(node* root) {
	if (! root) {
		//cout << "root null" << endl;
		return;
	}
	printTree(root->left);
	cout << "root-data - " << root->data << ", root-start - " << root->start << ", root-end - " << root->end << endl;
	printTree(root->right);
	
}


node* buildSegmentTree(vector<long>& heights) {
	return buildSTreeUtil(heights, 0, heights.size()-1);
}


int query(vector<long>& heights, node* root, int left, int right) {
	if (!root || left > root->end || right < root->start) {
		return -1;
	}
	if (left <= root->start && right >= root->end)
		return root->data;
	int leftminindex = query(heights, root->left, left, right);
	int rightminindex = query(heights, root->right, left, right);
	if (leftminindex == -1) return rightminindex;
	if (rightminindex == -1) return leftminindex;
	return (heights[leftminindex] < heights[rightminindex]) ? leftminindex : rightminindex;
}

long maxAreaUtil(node* root, vector<long>& heights, int start, int end) {
	if (start > end) return -1;
	if (start == end) return heights[start];
	int minheightindex = query(heights, root, start, end);
	int leftarea = maxAreaUtil(root, heights, start, minheightindex-1);
	int rightarea = maxAreaUtil(root, heights, minheightindex+1, end);
	int area = heights[minheightindex] * (end-start + 1);
	return max(area, max(leftarea, rightarea));
}

long maxArea(vector<long>& heights) {
	if (heights.size() == 0) return 0;
	node* root = buildSegmentTree(heights);
	return maxAreaUtil(root, heights, 0, heights.size()-1);
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
	/*
    int heights_count;
    cin >> heights_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long> heights(heights_count);

    for (int heights_itr = 0; heights_itr < heights_count; heights_itr++) {
        long heights_item;
        cin >> heights_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        heights[heights_itr] = heights_item;
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i)
    {
        int l;
        cin >> l;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int r;
        cin >> r;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long res = findMaxPossibleArea(heights, l, r);

        cout << res << "\n";
    }

    //fout.close();
	*/
	vector<long> hist = {6, 2, 5, 4, 5, 1, 6};
	cout << "Maximum area is " << findMaxPossibleArea(hist, 0, hist.size()-1) << endl;
	cout << "MaxArea - " << maxArea(hist) << endl;

	vector<long> h = {1,1,1, 10, 1,1,1};
	cout << "Maximum area is " << findMaxPossibleArea(h, 0, h.size()-1) << endl;
	cout << "MaxArea - " << maxArea(h) << endl;
	
	//int res2 = maxArea(h, 2, 2);
	//cout << "res2 - " << res2 << endl;

    return 0;
}