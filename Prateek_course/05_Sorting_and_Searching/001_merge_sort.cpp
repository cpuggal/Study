#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &array, int start, int mid, int end) {
	
	int i = start, j = mid+1;
	vector<int> temp;

	// Compare and merge the two divided array	
	while(i <= mid && j <= end) {
		if (array[i] < array[j]) {
			temp.push_back(array[i++]);
		} else {
			temp.push_back(array[j++]);
		}
	}
	
	// Copy the left over elements of first half (if any) to temp
	while(i <= mid) {
		temp.push_back(array[i++]);
	}

    // Copy the left over elements of second half (if any) to temp
	while(j <= end) {
        temp.push_back(array[j++]);
    }

	// Copy back values from temp to original array
	int k = 0;
	for (int i = start; i <= end; i++) {
		array[i] = temp[k++];
	}
}

void mergeSort(vector<int> &array, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	mergeSort(array, start, mid);
	mergeSort(array, mid+1, end);

	merge(array, start, mid, end);
}

int main() {

	vector<int> array = {1,4,0,9,10,2,3};
	for (auto x: array)
        cout << x << " ";
    cout << endl;
	
	mergeSort(array, 0, array.size());
	
	for (auto x: array)
		cout << x << " ";
	cout << endl;
	return 0;
}

