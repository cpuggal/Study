#include<iostream>
#include<string>
#include<cstring>
#include<map>

using namespace std;

string getUniqueSeq(string str) {

	int start = 0, end = 0, size = str.length();
	map<char, int> mp;
	int maxLen = 0, temp = 0, maxStart;
	string res;
	char ch;

	while(end != size) {
		ch = str[end];
		if ((mp.find(ch) != mp.end()) && mp[ch] >= start) {
			start = mp[ch] + 1;
		}
		
		if (end - start + 1 > maxLen) {
			maxLen = end - start + 1;
			maxStart = start;
		}
		mp[ch] = end;
        end++;
	}
	
	res = str.substr(maxStart, maxLen);
	return res;
}

int main() {

	string input;
	cin >> input;
	cout << getUniqueSeq(input) << endl;

	return 0;
}
