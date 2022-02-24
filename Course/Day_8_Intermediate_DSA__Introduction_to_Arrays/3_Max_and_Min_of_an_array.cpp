/*
Problem Description:
Write a program to print maximum and minimum elements of the input array A of size N where you have to take integer N and further N elements as input from user.


Problem Constraints

1 <= N <= 1000
1 <= A <= 1000

Input Format
A single line representing N followed by N integers of the array A

Output Format
A single line containing two space separated integers representing maximum and minimum elements of the input array.

Example Input

Input 1:
5 1 2 3 4 5

Input 2:
4 10 50 40 80


Example Output
Output 1:
5 1

Output 2:
80 10

*/

#include<iostream>

using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int size;
    int a[10000];

    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    cout << max <<" "<<min <<endl;

    return 0;
}
