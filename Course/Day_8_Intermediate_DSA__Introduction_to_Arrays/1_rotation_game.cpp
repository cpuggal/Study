/*
You are given an integer array A and an integer B. 
You have to print the same array after rotating it B times towards right.

NOTE: You can use extra memory.

Problem Constraints

1 <= |A| <= 106
1 <= A[i] <= 109
1 <= B <= 109


Input Format:
First line begins with an integer |A| denoting the length of array, and then |A| integers denote the array elements.
Second line contains a single integer B

Output Format:
Print an array of integers which is the Bth right rotation of input array A, on a separate line.

Example Input

Input 1:
 4 1 2 3 4
 2

Input 2:
 3 1 2 2
 3


Example Output

Output 1:
 3 4 1 2

Output 2:
 1 2 2


Example Explanation

Explanation 1:
 [1,2,3,4] => [4,1,2,3] => [3,4,1,2]

Explanation 2:
 [1,2,2] => [2,1,2] => [2,2,1] => [1,2,2]

*/


#include<iostream>

using namespace std;

void reverse(int *a, int size, int s, int e) {
    int temp;
    while(s < e) {
        temp = a[s];
        a[s] = a[e];
        a[e] = temp;
        s++; e--;
    }

    // for (int i = 0; i < size; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output

    int size, a[1000000];
    int k;

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    cin >> k;

    k = k % size;

    reverse(a, size, 0, size-1);
    reverse(a, size, 0, k-1);
    reverse(a, size, k, size-1);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
