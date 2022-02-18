#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string isPerfect(int num) {
    int count = 1;
    int sq = sqrt(num);
    //cout << " sq:" << sq << endl;
    for (int i = 2; i <= sq; i++ ) {
        if (num % i == 0) {
            if (i == num/i)
                count = count + i;
            else
                count = count + i + num/i;
        }
    }

    //count -= 1;

    //cout << "here: " <<  count << endl;

    if (count == num)
        return "YES";
    else
        return "NO";
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int n;
    cin >> n;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << isPerfect(num) << endl;
    }
    return 0;
}
