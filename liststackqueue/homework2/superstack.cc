#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
void superStack(vector <string> operations) {

}


int main()
{
    int operations_size = 0;
    cin >> operations_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> operations;
    for(int i = 0; i < operations_size; i++) {
        string operations_item;
        getline(cin, operations_item);
        operations.push_back(operations_item);
    }

    superStack(operations);
    
    return 0;
}


