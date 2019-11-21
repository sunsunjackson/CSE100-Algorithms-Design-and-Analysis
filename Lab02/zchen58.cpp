#include <iostream>
#include <limits.h>

using namespace std;

//resources: textbook p.31 & 34 - mergesort

void merging(int arr[], int p, int q, int r) {
    //p is the left most
    //q is the mid point
    //r is the right most point
    int n1, n2;
    int *left;
    int *right;
    
    n1 = q - p + 1;
    n2 = r - q;

    // int left[n1 + 1];
    // int right[n2 + 1];
    
    left = new int[n1 + 1];
    right = new int [n2 + 1];

    for(int i = 0; i < n1; i++) {
        left[i] = arr[p + i];
    }

    for(int j = 0; j < n2; j++) {
        right[j] = arr[q + j + 1];
    }

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++){
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        
    }
    //print
    // for (int i = 0; i <= j; i++) {
    //         cout << arr[i] << ';';
    //     }
    //     cout << endl;
}
void mergeSort(int arr[], int p, int r) {
    //r is the right most point
    //intial case p is always 0, r is always the array size
    int q;
    if(p < r) {
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merging(arr, p, q, r);
    }
}

void printArray(int arr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << ";";
    }
    // cout << endl;
}

int main(int argc, char **argv) {
    int p, r;
    int n = 0;
	cin >> n;
    p = 0;
    r = n - 1;
	int *arr;
    arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    mergeSort(arr, p, r);
    printArray(arr, n);

}
