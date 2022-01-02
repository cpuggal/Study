#include<iostream>
#include<vector>

using namespace std;

int maxTrappedWater(vector<int> nums) {
	if (nums.size() == 0)
		return 0;
	vector<int> lMax(nums.size(),0), rMax(nums.size(),0);
	int ans = 0, left = 0, right = 0, size = nums.size();

	lMax[0] = nums[0];
	rMax[size-1] = nums[size-1];

	for (int i = 1; i <= size - 1; i++) {
		lMax[i] = max(lMax[i-1], nums[i]);
		rMax[size-1-i] = max(rMax[size-i], nums[size-1-i]);
	}

/*
	for (int i = size - 2; i >= 0; i--) {
		right = i+1;
		rMax[i] = max(rMax[right], nums[i]);	
	}
*/

/*
	for (int i = 0; i <= nums.size() - 1; i++) {
		cout << lMax[i] << ", " << rMax[i] << endl;
	}
*/
	for (int i = 0; i <= nums.size() - 1; i++) {
		ans += min(lMax[i], rMax[i]) - nums[i];
	}
	return ans;
}

int main() {
	vector<int> nums {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << maxTrappedWater(nums) << endl;

	return 0;
}
