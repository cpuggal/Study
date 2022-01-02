#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>
//#include<unordered_map>

using namespace std;

int largestBand(vector<int> nums) {
	if (nums.size() == 0)
		return 0;

	int result = 0, current = 0, temp = 0;
	int size = nums.size();
	//unordered_map<int, bool> numsMap;
	unordered_set<int> numSet;

	for (int i = 0; i < size; i++){
	//	numsMap.insert({nums[i], true});
		numSet.insert(nums[i]);
	}

	for (int i = 0; i < size; i++) {
		// Prev number is not found. That means its starting of the band
		// else ignore nums[i] and moveon
		if (numSet.find(nums[i] - 1) == numSet.end()) {
			temp = nums[i];
			current = 1;
			while(true) {
				if (numSet.find(temp+1) == numSet.end())
					break;
				else {
					current++; temp++;
				}
			}
			result = max(result, current);	
		}
	}

	return result;
}

int main() {

	vector<int> nums {1,9,3,0,18,5,4,2,10,7,12,6};
	cout << largestBand(nums) << endl;
	return 0;
}
