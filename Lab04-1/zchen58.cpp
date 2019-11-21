#include <iostream>

using namespace std;


void Heapify(int arr[], int n, int i, int heapSize) {
    int left;
    int right;
    int largest;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left <= heapSize && arr[left] > arr[i]) {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right <= heapSize && arr[right] > arr[largest]) {
        /* code */
        largest = right;
    }
    if (largest != i) {
        /* code */
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest, heapSize);
    }
    
}

int buildHeap(int arr[], int n) {
    //cout << "Entered BuildHeap" << endl;
    int heapSize;
    heapSize = n - 1;
    //cout << "Enter BuildHeap For Loop" << endl;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        //cout << "Iteration: " << i << endl;
        Heapify(arr, n, i, heapSize);
    }
    // for (int i = n - 1; i >= 0; i--) {
    //     swap(arr[0], arr[i]);
    //     Heapify(arr, i, 0);
    // }
    return heapSize;
}

void heapSort(int arr[], int n) {
    int heapSize = buildHeap(arr, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapSize--;
        Heapify(arr, n, 0, heapSize);

    }
}
// void print(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << ";";
//     }
// }

int main(int argc, char **argv) {
    int n = 0;
    // int heapSize = 0;
    cin >> n;
    // heapSize = n;

    int *arr;
    arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Heapify(arr, n, i);

    // cout << "Entering BuildHeap" << endl;
    // buildHeap(arr, n);
    heapSort(arr, n);

    //print(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }

}