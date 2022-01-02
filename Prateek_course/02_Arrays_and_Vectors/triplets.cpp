#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/* Appraches
*  1) O(n^3) by 3 loops
   2) for each number nums[i] calc pairs sum of targetSum - nums[i] for range of 
	  i+i to n. Complexity -> o(n^2) + Space -> o(n)
   3) For each number, take two pointer at i+1 and n to figure our targetSum - nums[i]
*/

vector<vector<int>> getTriplets(vector<int> nums, int targetSum) {

	sort(nums.begin(), nums.end());
	int j, k, currSum;
	vector<vector<int>> result;

	for (int i = 0; i < nums.size() - 3; i++) {
		j = i + 1;
		k = nums.size() - 1;
		while (j < k) {
			currSum = nums[i] + nums[j] + nums[k];
			if (currSum == targetSum) {
				result.push_back({nums[i], nums[j], nums[k]});
				j++; k--;
			} else if (currSum > targetSum) {
				k--;
			} else
				j++;
		}
	}
	return result;

}

int main() {
	
	vector<int> nums {1,2,3,4,5,6,7,8,9,15};
	vector<vector<int>> result = getTriplets(nums, 18);

	for (int i = 0; i < result.size(); i++) {
		cout << "{ ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << "}, " << endl;
	}
	
	return 0;
}
