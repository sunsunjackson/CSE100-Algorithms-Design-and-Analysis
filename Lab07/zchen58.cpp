#include <iostream>
#include <limits.h>

using namespace std;

// int max(int a, int b) {
//     if (a > b) {
//         return a;
//     }
//     else
//     {
//         return b;
//     }
// }

// int bottomUp(int p[], int n) {
//     int q;
//     int *arr;
//     arr = new int[n];
//     arr[0] = 0;
//     for(int j = 1; j < n; j++) {
//         q = INT_MIN;
//         for (int i = 0; i < j; i++) {
//             q = max(q, p[i] + arr[j - i]);
//         }
//         arr[j] = q;
//     }
//     return arr[n];
// }

// void printCutRod(int p[], int n) {
//     int *r;
//     int *s;
//     // r = new int[n + 1];
//     // s = new int[n + 1];
//     // cout << r[n] << endl;
//     // cout << "hello" << endl;

//     while(n >> 0) {
//         cout << s[n] << " ";
//         n = n - s[n];
//     }
// }

int bottomUpCut(int p[], int n) {
    int q;
    int *r;
    int *s;
    r = new int[n + 1];
    s = new int[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        q = INT_MIN;
        for (int i = 0; i < j; i++) {

            if (q < p[i] + r [j - i - 1]) {
                s[j] = i + 1;
                q = p[i] + r[j - i - 1];
                
            }
        
        }
        r[j] = q;
    }

    cout << r[n] << endl;
    // cout << "hello" << endl;

    while(n >> 0) {
        cout << s[n] << " ";
        n = n - s[n];
    }
    
    // printCutRod(p, n);

    cout << -1 << endl;
    return *r, *s;
}



int main(int argc, char **argv) {
    int n;
    cin >> n;

    // int *p = new int[n];
    

    int *arr;
    arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    int cut = bottomUpCut(arr, n);
    // printArray(arr, n);
    // cout << cut;
}