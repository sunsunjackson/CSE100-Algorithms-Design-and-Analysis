#include <iostream>

using namespace std;

//resources: textbook p.18 - insertion sort

void insertionSort(int arr[], int arraySize) {
    int key;
    for (int j = 1; j < arraySize; j++) {
        key = arr[j];//value marker
        int i = j - 1;//index marker
        while(i > -1 && arr[i] > key) { //responsible 4 swap
            arr[i + 1] = arr[i];
            i = i - 1;
            //swaps
        }
        arr[i + 1] = key;
        //swaps value
        //print here
        for (int i = 0; i <= j; i++) {
            cout << arr[i] << ';';
        }
        cout << endl;
    }
} 

int main(int argc, char **argv) {
    int n = 0;
	cin >> n;
	int *arr;
    arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    insertionSort(arr, n);
    // array(arr, n);

}

// int main() {
    
// }
// void array(int arr[], int arraySize) {
// 	for (int i = 0; i < arraySize; i++) {
// 		cout << arr[i] << ";" <<endl;
// 	}
// }

