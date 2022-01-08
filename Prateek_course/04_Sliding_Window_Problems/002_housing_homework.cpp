#include<iostream>
#include<vector>

using namespace std;

void getSmallestWindowIndexes(vector<int> input, int sum) {

	int start = 0, end = 0, currSum = 0, window = INT_MAX;
	int smallestStart = 0, smallestEnd = 0;
	int size = input.size();

	while ((start != size) && (end != size)) {
	
		if (currSum > sum) {
			currSum -= input[start++];
		} else if (currSum == sum) {
			if (end-1-start <= window){
				window = end-1-start;
				smallestStart = start;
				smallestEnd = end-1;
			}
			currSum -= input[start++];
		} else {
			currSum += input[end++];
		}
	}
	cout << smallestStart << "-" << smallestEnd << endl;
}

void getSmallestIndexesWithNegativeNumbers(vector<int> input, int sum) {

	int start = 0, end = 0, window = INT_MAX, currSum = 0;
	int smallestStart = 0, smallestEnd = 0;
	int size = input.size();

	while ((start != size) && (end != size)) {
		if (currSum > sum) {
			currSum -= input[start++];
		} else if (currSum <= 0) {
			start = end;
			currSum = input[end++];
		} else if (currSum == sum) {
//			cout << "here: " << start << ", " << end << endl;
			if (end - 1 - start <= window) {
				window = end - 1 - start;
				smallestStart = start;
                smallestEnd = end-1;
			}
			currSum -= input[start++];
		} else {
			currSum += input[end++];
		}
	}

	cout << smallestStart << "-" << smallestEnd << endl;
	
}

int main() {

	vector<int> input = {1,3,2,1,4,1,3,2,1,1,2};
	getSmallestWindowIndexes(input, 8);

	vector<int> input2 = {1,-3,2,6,4,1,3,2,1,1,2};
	getSmallestIndexesWithNegativeNumbers(input2, 8);
	return 0;
}

