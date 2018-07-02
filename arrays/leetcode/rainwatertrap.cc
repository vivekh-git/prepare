#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
}

int trap(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        vector<int> leftmax(heights.size(), 0);
        vector<int> rightmax(heights.size(), 0);
        int rmax = 0;
        for (int j = heights.size()-1; j >= 0; j--) {
            if (j == heights.size()-1) {
				cout << "j is M-1" << endl;
                rightmax[j] = 0; 
                rmax = heights[j];
				cout << "rmax - " << rmax << endl;
            }
            else if (rmax > heights[j]) {
				cout << "rmax greter" << endl;
                rightmax[j] = rmax;
            }
            else {
				cout << "rmax smaller" << endl;
                rmax = heights[j];
                rightmax[j] = 0;
				cout << "rmax - " << rmax << endl;
            }
        }
        int lmax = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (i == 0) {
                leftmax[i] = 0; 
                lmax = heights[i];
            }
            else if (lmax > heights[i]) {
                leftmax[i] = lmax;
            }
            else {
                lmax = heights[i];
                leftmax[i] = 0;
            }
        }
        vector<int> area(heights.size(), 0);
        for (int i = 0; i < heights.size(); i++) {
			int m = min(leftmax[i], rightmax[i]);
            area[i] =  (m == 0) ? 0 : (m - heights[i]) * 1;
        }
        print_arr(heights);
        print_arr(leftmax);
        print_arr(rightmax);
        print_arr(area);
        
        int areasum = 0;
        for (int i = 0; i < heights.size(); i++)
            areasum += area[i];
        return areasum;
}

int main() {
	vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << "area - " << trap(arr) << endl;
	
}