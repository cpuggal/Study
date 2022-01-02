#include<iostream>
#include<cstring>

using namespace std;

/*
	remember:
		1. strtok uses char array and not string
		2. User input for char array is taken using cin.getline(charArray, size)
		3. strtok maintains internal state of char array using static variable.
		4. strtok returns NULL when there is no more tokenization possible.
		5. strtok can only delimite for a char using double quotes -> ""

*/

void stringToken() {

	char input[10000];
	cin.getline(input, 10000);

	char* token = strtok(input, " ");

	while(token) {
		cout << token << endl;
		token = strtok(NULL, " ");
	}

}

int main() {

	stringToken();	
	return 0;
}
