#include <iostream>
#include <vector>

using namespace std;


void CountingSort(vector< vector<int> > *arr, vector< vector<int> > *B, int k, int d, int n) {
	int i;
	int j;
	int* C;
	int p;
	k = 4;
	C = new int[5];

	for(i = 0; i < k + 1; i++){
		C[i] = 0;
	}
	for(j = 0; j <= n - 1; j++){
		C[(*arr)[j][d] ]++;
	}
	for(i = 1; i < k + 1; i++){
		C[i] = C[i] + C[i - 1];
	}
	// for(i = n - 1; n >= 0; i--) {
	// 	int Array_at_J = (*arr)[j][d];
	// 	int C_at_AJ = C[Array_at_J];
	// }
	for(j = n - 1; j > -1; j--){
		int Array_at_J = (*arr)[j][d];
		int C_at_AJ = C[Array_at_J];
		(*B)[C_at_AJ - 1][d] = Array_at_J;
		C[Array_at_J] = C_at_AJ - 1;

		for(p = 0; p <= d - 1; p++){
			(*B)[C[Array_at_J]][p] = (*arr)[j][p];
		}
		for(p = d + 1; p <= 9; p++){
			(*B)[C[Array_at_J]][p] = (*arr)[j][p];
		}
	}
	for(i = 0; i <= n - 1; i++){
		for(j = 0; j <= 9; j++){
			(*arr)[i][j] = (*B)[i][j];
		}
	}
}

int main(){
	int n;
	cin >> n;
 
	vector< vector<int> > *row = new vector< vector<int> >(n, vector<int>(10));
	vector< vector<int> > *result = new vector< vector<int> >(n, vector<int>(10));

	for(int i = 0; i <= n - 1; i++){
		for(int j = 0; j <= 9; j++){
			cin >> (*row)[i][j];
		}
	}

//Radix sort
	for(int j = 9; j > -1; j--){
		int column = j;
		int k = 0;
		int max_temp = 0;
		for(int i = 0; i < n; i++){
			max_temp = (*row)[i][j];
			if(max_temp > k){
				k = max_temp;
			}
		}
		CountingSort(row, result, k, column, n);
	}

//print function
	for (int i = 0; i <= (*row).size() - 1; i++){
		for (int j = 0; j < 10; j++){
			cout << (*row)[i][j] << ";";
		}
		cout << endl;
	}
}