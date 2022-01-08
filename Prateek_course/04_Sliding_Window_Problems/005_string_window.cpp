#include<iostream>
#include<string>
#include<cstring>

using namespace std;

/* 
*	Remember: 
*		1. Reset the FP array after every successful iteration since that is where we know if count is success
*		2. set start to current index and count to 1 since this match could also lead to next successful shorter match like lakshya ha
*
*
*/

string getStringWithMinWindow(string s1, string s2) {

	char fp[256] = {0};
	char fs[256] = {0};
	for (int i = 0; i < s2.length(); i++) {
		fp[s2[i]]++;
	}
	int count = 0, start = 0;
	int window = 0, min_window = INT_MAX, min_start = -1;
	char ch;
	for (int i = 0; i < s1.length(); i++) {
		ch = s1[i];
		fs[ch]++;
		if ((fp[ch] != 0) && (fs[ch] <= fp[ch]))
			count++;

		// all char of pattern matches in current window
		if (count == s2.length()) {
			while((fp[s1[start]] == 0) || fs[s1[start]] > fp[s1[start]]) {
				fs[s1[start]]--;
				start++;
			}
//			cout << i << ", " << start << ", " << i - start + 1 << endl;
			window = i - start + 1;
			if (min_window > window) {
				min_window = window;
				min_start = start;
				memset(fs, 0, sizeof(fs));
			}
			start = i;
			count = 1;
		}
	}
//	cout << min_start << ", " << min_window << endl;
	if (min_start == -1)
		return "No match";
	else
		return s1.substr(min_start, min_window);
}

int main() {

	string s1 = "hello_world";	
	string s2 = "elo";

	cout << getStringWithMinWindow(s1, s2) << endl;

	s1 = "fizzbuzz";
	s2 = "fuzz";
	cout << getStringWithMinWindow(s1, s2) << endl;

	cout << getStringWithMinWindow("chandddaaan", "dan") << endl;
	cout << getStringWithMinWindow("lakshya", "ah") << endl;
	string s3, s4;
	cin >> s3 >> s4;
	cout << getStringWithMinWindow(s3, s4) << endl;
	return 0;
}
