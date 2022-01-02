#include<iostream>
#include<string>

using namespace std;

int main() {

	string para = "Hi STL, how are you STL and whre is STL in this STL para?";

	int index = -1;
	string str;

	getline(cin, str);
/*
	index = para.find(str, index);
	cout << index << endl;
	while(index != -1) {
		index = para.find(str, index+1);
		cout << index << endl;
	}
*/
	while(1) {
		index = para.find(str, index+1);
		if (index == -1)
			break;
	
		cout << index << endl;
	}

	return 0;
}
