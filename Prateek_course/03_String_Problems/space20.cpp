#include<iostream>
#include<string>

using namespace std;

/* 
* remember:
	1. String should be null terminate with '\0'
	2. string size should be sufficent to accomodate replacements
	3. keep the track of newIndex = str.length() + spaceCnt * (repLen - 1)

*/


string replaceString(string str, string rep) {

	int repLen = rep.length();
	int spaceCnt = 0;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			spaceCnt++;
	}
	
	//cout << "space: " << spaceCnt << endl;
	int newLen = str.length() + spaceCnt * (repLen - 1);
	int oldIndex = str.length() - 1;
	int newIndex = newLen - 1;
	string strNew(newLen, 0);
	strNew[newLen] = '\0';
	while(newIndex != -1) {
		if (str[oldIndex] == ' ') {
			for (int j = repLen-1; j >= 0; j--) {
				strNew[newIndex] = rep[j];
				newIndex--;
			}
		} else {
			strNew[newIndex] = str[oldIndex];
			newIndex--;
		}
		oldIndex--;
//	cout << newIndex << " , " << oldIndex << endl;
	}

//	cout << newIndex << " , " << oldIndex << endl;

	return strNew;
}

int main() {
	
	//string input = "Hey how are you doing?";
	string input(10000, 0);
	getline(cin, input);
	string replacement = "%20";

	cout << replaceString(input, replacement) << endl;

	return 0;
}
