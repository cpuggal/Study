#include<iostream>
#include<string>

using namespace std;

/*
input:
	chandan
	cdn
o/p
	Yes

input:
	chandan
	chnn
o/p 
	Yes

input:
	chandan
	cdnn
o/p
	No


*/

string isSubset(string s1, string s2) {
	int j = 0;
	for (int i = 0 ; i < s1.length(); i++) {
		if (s1[i] == s2[j])
			j++;
		if (j == s2.length())
			return "Yes";
	}

	return "No";
}

int main() {
	
	string ip1;
	string ip2;
	cin >> ip1 >> ip2;
	cout << isSubset(ip1, ip2) << endl;
	return 0;
}
