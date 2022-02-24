/*
Problem Description:
You are given an integer T (Number of test cases). For each test case, you are given array A and an integer B. You have to tell whether B is present in array A or not.


Problem Constraints

1 <= T <= 10
1 <= |A| <= 105
1 <= A[i], B <= 109

Input Format
First line of the input contains a single integer T.
Next, each of the test case consists of 2 lines:
First line begins with an integer |A| denoting the length of array, and then |A| integers denote the array elements.
Second line contains a single integer B


Output Format
For each test case, print on a separate line 1 if the element exists, else print 0.


Example Input
Input 1:
 1 
 5 4 1 5 9 1
 5

Input 2:
 1
 3 7 7 2
 1 

Example Output
Output 1:
 1 

Output 2:
 0 

Example Explanation
Explanation 1:
  B = 5  is present at position 3 in A 

Explanation 2:
  B = 1  is not present in A. 

*/

#include<bits/stdc++.h>
using namespace std;

int ans() {

    int size;
    long long a[100000];

    cin >> size;
    
    for (int i = 0; i < size; i++)
        cin >> a[i];

    long long B;
    cin >> B;

    for (int i = 0; i < size; i++) {
        if (a[i] == B)
            return 1;
    }
    return 0;
}

int main(){
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int T, size;
    cin >> T;

    for (int j = 0; j < T; j++) {
        cout << ans() << endl;
    }
    return 0;
}

