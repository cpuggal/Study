#include<iostream>
#include<vector>

using namespace std;

/* Mistakes
* 1. out of order was not implemented outside main for loop. Keep it out eased the logic
  2. Using for loop where while is short for traversing in single direction of array (left, right computation)
  3. for edge case (0, size-1) indexes, we should directly return contion only for ease of code.

*/
bool isOutOfOrder(vector<int> nums, int index) {

	if (index == 0)
		return (nums[index] > nums[index + 1]);
	if (index == nums.size() - 1)
		return (nums[index] < nums[index - 1]);
	
	if ((nums[index] > nums[index + 1]) || (nums[index-1] > nums[index]))
		return true;
	else 
		return false;
}

vector<int> getSubArrayIndexes(vector<int> nums) {
	vector<int> result;
	int size = nums.size();
	if (size < 2)
		return result;

	int smallest = INT_MAX;
	int largest = INT_MIN;
	for (int i = 0; i <= size-1; i++)	{
		if (isOutOfOrder(nums, i)) {
//			cout << i << endl;
			smallest = min (smallest, nums[i]);
			largest = max (largest, nums[i]);
		}
	}

	cout << "smallest: " << smallest << ", largest: " << largest << endl;

	int left = 0, right = size - 1;
	while(nums[left] < smallest)
		left++;

	result.push_back(left);

	while(nums[right] > largest)
		right--;

	result.push_back(right); 

	return result;
}

int main() {

	vector<int> nums {1,2,3,4,5,8,6,7,9,10};
	vector<int> result = getSubArrayIndexes(nums);
	for (int i = 0; i <= result.size() - 1; i++) {
		cout << result[i] << endl;
	}
	return 0;
}

