#include<iostream>

using namespace std;

int f(int a, int b) {
	if (b== 0)
		return a;
	else
		return f(b, a%b);
}

int main() {
	int x  = 100, y = 2000;
	cout << f(x, y) << endl;
	return 0;
}
