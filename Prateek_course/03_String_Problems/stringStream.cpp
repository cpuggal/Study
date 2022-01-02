#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

void tryStringStream() {
	string input;
	getline(cin, input);

	stringstream ss(input);

	string token;
	vector<string> vectTokens;

	while(getline(ss, token, ' ')) {
		vectTokens.push_back(token);
	}

	for (auto token: vectTokens)
		cout << token << endl;

}

int main() {
	
	tryStringStream();
	return 0;
}
