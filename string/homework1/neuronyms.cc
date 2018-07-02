#include <bits/stdc++.h>

using namespace std;
/*
L10n for Localization  is the neuronym
For nailed
- n4d, na3d, n3ed, n2led, na2ed, nai2d
For batch
- b3h, ba2h, b2ch
*/
/*
 * Complete the neuronyms function below.
 */
void neuronymsUtil(string& word, int b, int e, vector<string>& output) {
    if (e-b < 3) 
        return;
    string sub = word.substr(0, b+1) + to_string(e-b-1) + word.substr(e, word.length()-e);
    output.push_back(sub);
    neuronymsUtil(word, b+1, e, output);
    neuronymsUtil(word, b, e-1, output);
    neuronymsUtil(word, b+1, e-1, output);
    return;
}

vector<string> neuronyms(string word) {
    vector<string> output;
    neuronymsUtil(word, 0, word.length()-1, output);
    return output;
}


vector<string> neuronyms2(string word) {
	vector<string> result;
	for (int i = 0; i < word.length(); i++) {
		for (int j = word.length()-1; j >= 0; j--) {
			if (j-i < 3)
				break;
			string sub = word.substr(0, i+1) + to_string(j-i-1) + word.substr(j, word.length()-j);
			result.push_back(sub);
		}
	}
	return result;
}

int main() {
    // ofstream fout(getenv("OUTPUT_PATH"));

    string word;
    getline(cin, word);

    vector<string> res = neuronyms2(word);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        cout << res[res_itr];

        if (res_itr != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

    return 0;
}