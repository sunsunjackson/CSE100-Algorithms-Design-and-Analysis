#include <iostream>
#include <limits.h>

using namespace std;

//sources: textbook p.71 && p.72 find-max-crossing-subarray and
//find-maximum-subarray

int crossSubarray (int arr[], int low, int mid, int high){
    int leftSum, rightSum, sum;
    int maxLeft;
    leftSum = INT_MIN;
    sum = 0;

    for(int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if(sum > leftSum) {
            leftSum = sum;
            //maxLeft = i;
        }
    }
    rightSum = INT_MIN;
    sum = 0;

    int maxRight;
    for(int j = mid + 1; j <= high; j++) {
        sum = sum + arr[j];
        if(sum > rightSum) {
            rightSum = sum;
            //maxRight = j;
        }
    }
    return (leftSum + rightSum);
}

int maxSubarray (int arr[], int low, int high) {
    int mid;
    int leftLow, leftHigh, leftSum;
    int rightLow, rightHigh, rightSum;
    int crossLow, crossHigh, crossSum;

    if(high == low) {
        return arr[low];
    }
    else
    {
        mid = ((low + high) / 2);
        leftSum = maxSubarray(arr, low, mid);
        rightSum = maxSubarray(arr, mid + 1, high);
        crossSum = crossSubarray(arr, low, mid, high);

        if(leftSum >= rightSum && leftSum >= crossSum) {
            return leftSum;
        }
        else if(rightSum >= leftSum && rightSum >= crossSum) {
            return rightSum;
        }
        else
        {
            return crossSum;
        }
        
    }
    
}

void printArray(int arr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << ";";
    }
    // cout << endl;
}

int main(int argc, char **argv) {
    int n = 0;
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = maxSubarray(arr, 0, n - 1);
    int m = max;
    //printArray(arr, n);
    cout << m;
}