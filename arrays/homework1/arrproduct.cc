#include <bits/stdc++.h>
using namespace std;

vector<int> getProductArray(vector<int> nums) {
    vector<int> result(nums.size(), 0);
    int sz = nums.size();
    result[0] = 1; result[sz-1] = 1;
    for (int j=sz-2; j >= 0; j--) {
        result[j] = nums[j+1] * result[j+1];
    }
    int t1 = 1;
    for (int i=1; i < sz; i++) {
        t1 = t1 * nums[i-1];
        result[i] = result[i] * t1;
    }
    return result;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int nums_size;
    cin >> nums_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> nums(nums_size);
    for (int nums_i = 0; nums_i < nums_size; nums_i++) {
        int nums_item;
        cin >> nums_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        nums[nums_i] = nums_item;
    }

    vector<int> res = getProductArray(nums);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        cout << res[res_itr];

        if (res_itr != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}