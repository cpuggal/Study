#include<iostream>


using namespace std;

/* 
*	1. Char matching is always done with ' ' and not " "
*	2. Always terminate a token/substring with null '\0' so that it can be printed!!
*	3. For last string in input, make sure to update localStr so that last string is not printed infinite times
*/

char *myToken(char *input, char deliminetor) {

	static char *localStr = NULL;

	if (input != NULL)
		localStr = input;

	if (localStr == NULL)
		return NULL;


	//if (localStr == NULL)
	//	return NULL;

	char *token = new char[strlen(localStr) + 1];
	int i = 0;

	while(localStr[i] != '\0') {
		if (localStr[i] != deliminetor)
			token[i] = localStr[i];
		else {
			token[i] = '\0';
			localStr = localStr + i + 1;
			return token;
		}
		i++;
	}
	localStr = NULL;
	token[i] = '\0';
	return token;

}

int main() {
	
	char input[1000];
	cin.getline(input, 1000);
	
	char *token = myToken(input, ' ');

	while(token) {
		cout << token << endl;
		token = myToken(NULL, ' ');
	}

	return 0;
}


