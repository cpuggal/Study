#include<iostream>
#include<vector>
#include<map>
//#include<bits/stdc++.h>
// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

using namespace std;

void getPair(vector<int> nums, int sum) {
    
    for (int i = 0; i < nums.size(); i++){
        for (int j = i+1; i < nums.size(); j++) {
            if (nums[i] + nums[j] == sum) {
		cout << nums[i] << ", " << nums[j] << endl;
		return;
	    }
	}
    }

}

void getPairMaps(vector<int> nums, int sum) {
    map<int, bool> hashMap;

    for (int i = 0; i < nums.size(); i++) {
	if (hashMap.find(sum - nums[i]) == hashMap.end()) {
		hashMap.insert(make_pair(nums[i], true));
	} else {
	    cout << nums[i] << ", " << sum - nums[i] << endl;
	    return;
	}
    }
}

int main() {
    vector<int> num{ 10, 5, 2, 3, -6, 9, 11 };
    getPair(num, 4);
    return 0;
}
