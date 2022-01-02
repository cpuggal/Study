#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

/*
input
	3
	92 022
	82 12
	77 13
	2 false numeric

output
	82 12
    77 13
    92 022

intput2:
	3
    92 022
    82 12
    77 13
    2 false lexo

output:
    92 022
    82 12
    77 13

*/

/*
*	1. Break the problem into sub-problems and try to solve one at a time
*	2. test each and every sub function for various assumptions given in questions to ensure correct output
*	3. strtok take char* and returns the same. Hence use c_str() to convert to char* and (string) to typecast to string in this case
*	4. comparator function always return in increasing order if return is of type => a < b
*/

using namespace std;

string extractedStringAtKey(string str, int key) {
	char* result;

	result = strtok((char *)str.c_str(), " ");
	key --;

	while(key != 0) {
		result = strtok(NULL, " ");
		key--;
	}
	return (string)result;
}

int convertStringToInt(string str) {
	int result = 0;
	int pow = 1, num;
	for (int i = str.length() - 1; i >= 0; i--) {
		num = str[i] - '0';
		result += num * pow;
		pow = pow * 10;
	}
	return result;
}

bool numericComparatorFunc(pair<string, string> pair1, pair<string, string> pair2) {
	string key1 = pair1.first;
	string key2 = pair2.first;
		
	int intKey1 = convertStringToInt(key1);
	int intKey2 = convertStringToInt(key2);
	return intKey1 < intKey2;
}

bool lexographicalComparatorFunc(pair<string, string> pair1, pair<string, string> pair2) {
	string key1 = pair1.first;
    string key2 = pair2.first;

    return key1 < key2;
} 

int main() {

	int n;
	cin >> n;
	cin.get();
	string temp;

	vector<string> v;
	for (int i = 0; i < n ; i++) {
		getline(cin, temp);
		v.push_back(temp);
	}
	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering; 

	vector <pair<string,string>> vp;

	// 1. Extract
	for (int i = 0; i < v.size(); i++) {
		vp.push_back(make_pair(extractedStringAtKey(v[i], key), v[i]));
	}

	// 2. Sort
	if (ordering=="numeric")
		sort(vp.begin(), vp.end(), numericComparatorFunc);
	else
		sort(vp.begin(), vp.end(), lexographicalComparatorFunc);

	//3. Reversal
	if (reversal == "true")
		reverse(vp.begin(), vp.end());

	//4. Printing
	for (auto v: vp)
		cout << v.second << endl;

	return 0;
}


