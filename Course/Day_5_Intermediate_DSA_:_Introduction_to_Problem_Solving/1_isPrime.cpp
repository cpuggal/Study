/*
Problem Description

Given an integer A, you have to tell whether it is a prime number or not.
A prime number is a natural number greater than 1 which is divisible only by 1 and itself.

Problem Constraints

1 <= A <= 106

Input Format
First and only line of the input contains a single integer A.

Output Format
Print YES if A is a prime, else print NO.

Example Input
Input 1:
 3

Input 2:
 4 

Example Output
Output 1:
 YES
 
Output 2:
 NO 

Example Explanation
Explanation 1:
 3 is a prime number as it is only divisible by 1 and 3.
Explanation 2:

 4 is not a prime number as it is divisible by 2.

*/


#include<iostream>
#include<cmath>

using namespace std;

void isPrime(int num) {

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int num;
    cin >> num;
    isPrime(num);
    return 0;
}


