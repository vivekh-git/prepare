#include <bits/stdc++.h>

using namespace std;

void print_map(unordered_map<char, int>& hash) {
	for (auto it = hash.begin(); it != hash.end(); it++) {
		cout << it->first << "->" << it->second << endl;
	}
}

string MinWindow(string& text, string& pattern) {
    pair<int, int> result = {INT_MIN, INT_MAX};
    unordered_map<char, int> control; int missing = 0;
    for (int i = 0; i < pattern.length(); i++) {
		if (control.count(pattern[i]) == 0 || control[pattern[i]] == 0) {
			missing++;
        	control[pattern[i]] = 1;
		}
		else {
			control[pattern[i]]++;
		}
    }
	print_map(control);
	cout << "missing - " << missing << endl;
    int left = 0;
    unordered_map<char, int> seen;
    // find first eligible left
    for (left = 0; left < text.length(); left++) {
        if (control.count(text[left]) != 0) break;
    }
    seen[text[left]] = 1;
	cout << "Seen" << endl; print_map(seen);
	if (seen[text[left]] == control[text[left]]) {
    	missing--;
		cout << "decrementing missing, missing - " << missing << endl;
	}
    // now expand to find right
    for (int right = left+1; right < text.length(); right++) {
        char r = text[right];
        if (control.count(r) == 0) continue;
        if (seen.count(r) == 0 || seen[r] == 0) {
            seen[r] = 1;
        }
        else {
            seen[r]++;
        }
		cout << "Seen" << endl; print_map(seen);
		if (seen[r] == control[r]) {
			missing--;
			cout << "decrementing missing, missing - " << missing << endl;
		}
        if (missing != 0) continue;
        // first window found
        if (result.first == INT_MIN || right-left < result.second-result.first) {
           result.first = left;
           result.second = right;
        }

        // Now shrink from left & optimize
        for (; missing <= 0; left++) {
            char l = text[left];
            if (seen.count(l) == 0) continue;
            seen[l]--;
			cout << "Seen" << endl; print_map(seen);
            if (seen[l] < control[l]) missing++;
        }
        if (right-left+1 < result.second-result.first) {
            result.first = left-1;
            result.second = right;
        }
    }
	if (result.first == INT_MIN) 
		return "";
	else
    	return text.substr(result.first, result.second-result.first+1);
}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strText;
    getline(cin, _strText);
    
    string _strCharacters;
    getline(cin, _strCharacters);
    
    res = MinWindow(_strText, _strCharacters);
    cout << res << endl;
    
    //fout.close();
    return 0;
}
