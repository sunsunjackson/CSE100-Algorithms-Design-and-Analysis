#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int p, int r) {
    int x;
    int i;
    x = arr[r];
    i = p - 1;

    for (int j = p; j < r; j++){
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }

        
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

int ranPartition(int arr[], int p, int r) {

    srand(time(NULL));
    int i;
    i = p + rand() % (r - p);

    swap(arr[r], arr[i]);

    return partition(arr, p, r);
}

void ranQuicksort(int arr[], int p, int r) {
    int q;
    if (p < r) {
        q = ranPartition(arr, p, r);
        ranQuicksort(arr, p, q - 1);
        ranQuicksort(arr, q + 1, r);
    }
}

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

    ranQuicksort(arr, 0, n - 1);

    //print(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }

}