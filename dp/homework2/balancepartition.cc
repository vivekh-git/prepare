#include <bits/stdc++.h>

using namespace std;


void print_arr(vector<int>& table) {
	for (int i = 0; i < table.size(); i++) {
		cout << table[i] << " ";
	}
	cout << endl;
}
void print_arr(vector<bool>& table) {
	for (int i = 0; i < table.size(); i++) {
		cout << table[i] << " ";
	}
	cout << endl << endl;
}
void print_arr_arr(vector<vector<bool>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}
void print_arr_arr(vector<vector<int>>& table) {
	cout << "printing " << endl;
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}


/* Recurrence Relation
f(i, k) -> if (k == 0)
			return true;
		   else if (i == arr.size())
			return false;
		   else
			return f(i+1, k) || f(i+1, k-arr[i]);
*/
bool isPartitionSubsets(vector<int>& arr, int i, int k) {
	if (k == 0)
		return true;
	else if (i == arr.size())
		return false;
	else 
		return isPartitionSubsets(arr, i+1, k) || isPartitionSubsets(arr, i+1, k-arr[i]);
}


/* Recurrence Relation
f(i, k, arr,arr_arr) -> if (k == 0)
							arr_arr.push_back(arr);
							return true;
		   				else if (i == arr.size())
							return false;
		 	  			else
							f(i+1, k, arr, arr_arr);
							arr.push_back(inp[i]);
							f(i+1, k-inp[i], arr, arr_arr)
							arr.pop_back();
*/
bool isPartitionSubsets3(vector<int>& inp, int i, int k, vector<int>& arr, vector<vector<int>>& arr_arr) {
	if (k == 0) {
		arr_arr.push_back(arr);
		return true;
	}
	else if (i == inp.size()) {
		return false;
	}
	else {
		isPartitionSubsets3(inp, i+1, k, arr, arr_arr);
		arr.push_back(inp[i]);
		isPartitionSubsets3(inp, i+1, k-inp[i], arr, arr_arr);
		arr.pop_back();
		return false;
	}
}


bool isPartitionSubsets2(vector<int>& arr, int i, int k, vector<int>& out1, vector<int>& out2) {
	if (k == 0) {
		for (int l = i; l < arr.size(); l++)
			out2.push_back(arr[l]);
		print_arr(out1);
		print_arr(out2);
		return true;
	}
	else if (i == arr.size())
		return false;
	else {
		out2.push_back(arr[i]);
		if (isPartitionSubsets2(arr, i+1, k, out1, out2))
			return true;
		out2.pop_back();	
		out1.push_back(arr[i]);
		if (isPartitionSubsets2(arr, i+1, k-arr[i], out1, out2))
			return true;
		out1.pop_back();
		return false;
	}
}

bool balancePartition(vector<int>& inp) {
	int sum = 0;
	for (int i = 0; i < inp.size(); i++)
		sum += inp[i];
	if (sum % 2 != 0)
		return false;
	//vector<int> out1; vector<int> out2;
	//bool ret = isPartitionSubsets2(inp, 0, sum/2, out1, out2);
	vector<int> arr; vector<vector<int>> arr_arr;
	bool ret = isPartitionSubsets3(inp, 0, sum/2, arr, arr_arr);
	print_arr_arr(arr_arr);
	return ret;
}

/* Recurrence Relation
f(i, k, arr,arr_arr) -> if (k == 0)
							arr_arr.push_back(arr);
							return true;
		   				else if (i == arr.size())
							return false;
		 	  			else
							f(i+1, k, arr, arr_arr);
							arr.push_back(inp[i]);
							f(i+1, k-inp[i], arr, arr_arr)
							arr.pop_back();
*/
/*
 * Complete the function below.
 */
bool populateSubset(vector<vector<bool>>& table, vector<int>& inp, int i, int k, vector<int>& output) {
    // if i becomes inp.size()
    if (i == inp.size()-1 && k != 0 && table[0][k]) {
        output.push_back(inp[i]);
		print_arr(output);
		//cout << "first if loop" << endl;
        return true;
    }
    else if (i == inp.size()-1 && k == 0) {
		print_arr(output);
		//cout << "second if loop" << endl;
        return true;
    }
    if (table[i+1][k]) {
        // not adding the element to output
        vector<int> tmp = output;
        if (populateSubset(table, inp, i+1, k, output)) return true;
		//cout << "tmp" << endl;
		//print_arr(tmp);
    }
    if (k >= inp[i] && table[i+1][k-inp[i]]) {
        output.push_back(inp[i]);
		//print_arr(output);
        if (populateSubset(table, inp, i+1, k-inp[i], output)) return true;
    }
	return false;
}

/* Recurrence Relation
f(i, k) -> if (k == 0)
             return true;
           else if (i == inp.size())
             return false;
           else
             return f(i+1, k) || f(i+1, k-inp[i]);
*/
vector<int> balancePartition_DP(vector<int>& inp) {
    int sum = 0;
    vector<int> output;
    for (int i = 0; i < inp.size(); i++) {
        sum += inp[i];
    }
    if (sum % 2 != 0) {
        // not even 
        return output;
    }
    int halfsum = sum/2;
    vector<vector<bool>> table(inp.size()+1, vector<bool>(halfsum+1, false));
    for (int i = inp.size(); i >= 0; i--) {
        for (int k = 0; k < halfsum+1; k++) {
            if (k == 0)
                table[i][k] = true;
            else if (i == inp.size())
                table[i][k] = false;
            else if (k >= inp[i])
                table[i][k] = table[i+1][k] || table[i+1][k-inp[i]];
			else
				table[i][k] = table[i+1][k];
        }
    }
	print_arr_arr(table);
    // table[0][halfsum] stores status of if subset with halfsum is possible
    populateSubset(table, inp, 0, halfsum, output);
	//print_arr(output);
    return output;
}




bool balancePartition_DP2(vector<int>& arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;
	int halfsum = sum/2;
	//vector<vector<bool>> table(arr.size()+1, vector<bool>(halfsum+1, false));
	vector<bool> table(halfsum+1, false); 
	table[0] = true;
	for (int i = 0; i < arr.size(); i++) {
		for (int k = halfsum; k >= arr[i]; k--) {
			table[k] = table[k] || table[k-arr[i]];
		}
	}
	print_arr(table);
	return table[halfsum];
}


int main() {
  vector<int> inp = {9, 1, 5, 9, 12};
  /*
  if (balancePartition(inp) == true)
     cout << "Can be divided into two subsets of equal sum" << endl;
  else
     cout << "Can not be divided into two subsets of equal sum" << endl;
  */
  vector<int> out = balancePartition_DP(inp);
  print_arr(out);

  return 0;
}