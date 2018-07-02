#IFNDEF
#DEF CUSTOM_PRINT_H_

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



#END_IF
