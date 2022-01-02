#include<iostream>
#include<algorithm>
#include<vector>
//#include<pair>

using namespace std;

int getMinSwaps(vector<int> nums) {
	int ans = 0;
	int size = nums.size();
	int currNode;
	pair<int, int> myPairs[size];

	for (int i = 0; i <= size-1; i++) {
//		myPairs.push_back(make_pair(nums[i],i));
		myPairs[i].first = nums[i];
		myPairs[i].second = i;
	}

	sort(myPairs, myPairs + size);
	vector<bool> visited(size, false);
	int currentCycle = 0;
	for (int i = 0; i <= size-1; i++) {
		currentCycle = 0;
		
		// already visited or already in correct position
		if ((visited[i] == true) || (myPairs[i].second == i))	
			continue;

		currNode = i;

		while(!visited[currNode]) {
			currentCycle++;
			visited[currNode] = true; 
			currNode = myPairs[currNode].second;
		}

		ans += currentCycle - 1;
	}

	return ans;
}

int main() {

	vector<int> nums {2,4,5,1,3};
	cout << getMinSwaps(nums) << endl;

	return 0;
}

