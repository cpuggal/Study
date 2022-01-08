#include<iostream>
#include<vector>

using namespace std;

void getAllIndexes(vector<int> input, vector<pair<int,int>> &result, int sum) {

	int start = 0, end = 0;
	int currSum = 0;
	int size = input.size();
	
	while ((start != size) && (end != size)) {
		//currSum += input[end];
		if (currSum == sum) {
			result.push_back(make_pair(start, end-1));
			currSum -= input[start];
			start++;
		} else if (currSum > sum) {
			currSum -= input[start];
			start++;
		} else {
			currSum += input[end];
			end++;
		}
	}
}

int main() {

	vector<int> input = {1,3,2,1,4,1,3,2,1,1,2};
	int sum  = 8;
	vector<pair<int,int>> result;
	getAllIndexes(input, result, sum);

	for (auto res: result) {
		cout << res.first << ", " << res.second << endl;
	}	
	return 0;
}

