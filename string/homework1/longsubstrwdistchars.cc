#include <bits/stdc++.h>

using namespace std;


// time complexity - O(n)
string longestSub(string strText) {
    pair<int, int> result = {INT_MAX, INT_MIN};
    int size = 0;
    unordered_map<char, int> seen;
    int left = 0; char l = strText[left]; seen[l] = 1; size++;
    for (int right = left+1; right < strText.length(); right++) {
        // expand right
        char r = strText[right];
        if (seen.count(r) == 0 || seen[r] == 0) {
            seen[r] = 1;
            size++;
        }
        else {
            seen[r]++;
            // dup of already seen character
        } 
        if (size < 2) continue;
        // size == 2, first eligible window
        if (size == 2 && right-1-left > result.second - result.first) {
            result.first = left;
            result.second = right-1;
        }
        
        // Now shrink from left
        for (; size > 2; left++) {
            char ch = strText[left];
            if (seen[ch] == 1) {
                seen[ch] = 0;
                size--;
            }
            else {
                seen[ch]--;
            }
        }
        if (right-left > result.second - result.first) {
            result.first = left;
            result.second = right;
        }
        // go back and expand
    }
    if (result.first != INT_MAX)
        return strText.substr(result.first, result.second-result.first+1);
    else
        return "";
}

/*
int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if ( n == 0 ) return n;
        int i = 0, j = 0;
        int len = 0, ans = 0;
        int cnt[256]; memset(cnt, 0, sizeof(cnt));
        while ( i < n )
        {
            if ( cnt[s.at(i)] == 0 )
                len++;
            cnt[s.at(i)]++;
            while ( len > k )
            {
                cnt[s.at(j)]--;
                if ( cnt[s.at(j)] == 0 )
                    len--;
                j++;
            }
            if ( len <= k )
                ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }


*/

/*

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty()) return 0;
        int maxlen = 0;
        unordered_map<char, int> seen; 
        int left = 0; int right; int uniqchars = 0;
        seen[s[left]] = 1; 
        uniqchars++; 
        if (uniqchars <= k) {
            maxlen = 1;
        }
        for (right = left+1; right < s.length(); right++) {
            char r = s[right];
            if (seen.count(r) == 0 || seen[r] == 0) {
                seen[r] = 1;
                uniqchars++;
            }
            else {
                seen[r]++;
            }            
            // now shrink
            for (; uniqchars > k; left++) {
                char l = s[left];
                seen[l]--;
                if (seen[l] == 0) {
                    uniqchars--;
                }
            }
            if (uniqchars <= k)
                maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }

*/

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strText;
    getline(cin, _strText);
    
    res = longestSub(_strText);
    cout << res << endl;
    
    //fout.close();
    return 0;
}





