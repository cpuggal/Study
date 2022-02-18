#include<iostream>
#include<vector>

using namespace std;


int partition(vector<int> &array, int start, int end) {

	int i = start - 1;
	int pivotElem = array[end];

	for (int j = start; j < end; j++) {
		if (array[j] < pivotElem) {
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[end]);
	return i+1;
}

void quickSort(vector<int> &array, int start, int end) {
	// base
	if (start >= end)
		return;

	int p = partition(array, start, end);
	quickSort(array, start, p-1);
	quickSort(array, p+1, end);
}

int main() {

    vector<int> array = {1,4,0,9,10,2,3};
    for (auto x: array)
        cout << x << " ";
    cout << endl;

    quickSort(array, 0, array.size()-1);

    for (auto x: array)
        cout << x << " ";
    cout << endl;

    array = {1,2,3,4,5,6};
    for (auto x: array)
        cout << x << " ";
    cout << endl;

    quickSort(array, 0, array.size()-1);

    for (auto x: array)
        cout << x << " ";
    cout << endl;
	

	return 0;
}
