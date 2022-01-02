#include<iostream>
#include<string>
#include<vector>

using namespace std;

void getAllStringInternal(string str, string curr, int idx, vector<string> &res) {
	if (idx == str.length()) {
//		cout << curr << endl;
		res.push_back(curr);
		return;	
	}
//	cout << str << endl;
//	for (int i = idx; i < str.length(); i++) {
		// not take curr char
		getAllStringInternal(str, curr, idx+1, res);
		// take curr char
//		cout << curr + str[i] << endl;
		getAllStringInternal(str, curr + str[idx], idx+1, res);
//	}
}

vector<string> getAllStrings(string input) {
	vector<string> result;
	getAllStringInternal(input, "", 0, result);
	return result;
}

bool comparatorFunc(string s1, string s2) {

	if (s1.length() == s2.length())
		return s1 < s2;
	else 
		return s1.length() < s2.length();
		/*
		return true;
	else
		return false;//s1 < s2;
		*/
}

int main() {
	
	string input;
	cin >> input;

	vector<string> allStrings = getAllStrings(input);
	
	sort(allStrings.begin(), allStrings.end(), comparatorFunc);
	for (auto str: allStrings)
		cout << str << ", ";
	cout << endl;
	return 0;
}

