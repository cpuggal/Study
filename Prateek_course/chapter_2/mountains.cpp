#include<iostream>
#include<vector>


using namespace std;

int getMaxMountainSize(vector<int> nums) {

	if (nums.size() == 0)
		return 0;
	int result = 0;
	int currMax = 0;

	for (int i = 1; i <= nums.size() - 1;) {
		// check for peak
		if ((nums[i] > nums[i-1]) && 
			(i+1 <= nums.size()-1) &&
			(nums[i] > nums[i+1])) {
				int backwardLen = 0; 
				int forwardLen = 0;
				int temp = i;

				while ((temp > 0) && (temp <=nums.size()-1) && (nums[temp] > nums[temp-1])) {
					temp--; backwardLen++;
				}

				temp = i;
				while ((temp >= 0) && (temp < nums.size()-1) &&nums[temp] > nums[temp+1]) {
					temp++; forwardLen++;
				}

				if (result < backwardLen + forwardLen + 1)
					result = backwardLen + forwardLen + 1;

				i = temp;
		} else
			i++;
	}

	return result;
}

int main() {

	vector<int> nums {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	cout << getMaxMountainSize(nums) << endl;
	return 0;
}
