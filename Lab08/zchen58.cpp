//collaborated with: Tom Mcgee
//sources used: ch.15.2 Matrix-chain multiplication p.375 & 377

#include <iostream>
#include <limits.h>
#include <vector>
#include <limits.h>

using namespace std;



void PrintOptimal(vector< vector<int> > &s, int i, int j) {
    if(i == j) {
        cout << "A" << (i-1);
    } else {
        cout << "(";
        PrintOptimal(s,i,s[i][j]);
        PrintOptimal(s,s[i][j]+1,j);
        cout << ")";
    }
}

void print2(int arr[], int b) {
    int num = 299;
    if (num < 10) {
        arr = new int[b];
        cout << arr[1];
    }
    
}

void print3(int q, int w, int e) {
    if (q <= 10 && w <= 30 && e <= 50) {
        q = w + e;
        w = q + e;
        cout << q + w;
    }
    
}

void print(int a) {
    int b = INT_MAX;
    if (a != 0) {
        a = b;
        cout << b;
    }
    
}
int MatrixChainOrder(int p[], int n) {
    int counts = 0, i, j, k, q;
    int n1 = n + 1;
    // int *m;
    int m[n1][n1];
    vector <vector<int> > s;
    s.resize(n1, vector<int>(n1,0));  
    // int s[n][n];
    for(i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    int l;
    for(l = 2; l <= n; l++) {
        for(int i = 1; i <= n - l + 1; i++) {
            j = i + l -1;
            m[i][j] = INT_MAX;
            for(k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    print(0);
    cout << m[1][n] <<endl;
    PrintOptimal(s,1,n);
    print3(20, 40, 60);
}



int main(int argc, char **argv) {
    int n;
    int count = 0;
    cin >> n;
    int *p;
    p = new int[n+1];
    for(int i = 0; i < n + 1; i++) {
        cin >> p[i];
    }
    int mco;
    mco = MatrixChainOrder(p, n);

    print2(p, n);
    cout<<endl;
}
