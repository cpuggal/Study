#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int> &array, int start, int mid, int end) {
	
	int i = start, j = mid+1;
	vector<int> temp;
	int count = 0;
	// Compare and merge the two divided array	
	while(i <= mid && j <= end) {
		if (array[i] < array[j]) {
			temp.push_back(array[i++]);
		} else {
			temp.push_back(array[j++]);
			count += mid - i + 1;
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
	return count;
}

int mergeSort(vector<int> &array, int start, int end) {
	if (start >= end)
		return 0;

	int mid = (start + end) / 2;
	int l = mergeSort(array, start, mid);
	int r = mergeSort(array, mid+1, end);

	return l + r + merge(array, start, mid, end);
}

int main() {

	vector<int> array = {1,4,0,9,10,2,3};
	for (auto x: array)
        cout << x << " ";
    cout << endl;
	
	cout << "Invesions: " << mergeSort(array, 0, array.size()) << endl;
	
	for (auto x: array)
		cout << x << " ";
	cout << endl;
	return 0;
}

