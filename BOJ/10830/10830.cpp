#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector<vector<ll>> Matrix_s;

Matrix_s matrixMulti(Matrix_s& a, Matrix_s& b) {
	Matrix_s answer;
	int n = a.size()-1;
	answer.resize(n+1,vector<ll>(n+1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ll sum = 0;
			for(int k = 1; k <= n; k++)
				sum += a[i][k]*b[k][j];
			answer[i][j] =sum%1000;
		}
	}
	return answer;
}

Matrix_s matrixPower(Matrix_s&matrix, int times, int n) {
	if(times == 1) return matrix;
	
	Matrix_s subMatrix(n+1,vector<ll>(n+1));
	subMatrix= matrixPower(matrix, times/2, n);
	if(times%2 == 1) {
		Matrix_s sumMatrix(n+1,vector<ll>(n+1));
		sumMatrix= matrixMulti(subMatrix,subMatrix);
		return matrixMulti(sumMatrix,matrix);
	}
	return matrixMulti(subMatrix,subMatrix);
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n,b;
	Matrix_s matrix, answer;
	
	cin>>n>>b;
	matrix.resize(n+1,vector<ll>(n+1)), answer.resize(n+1, vector<ll>(n+1));
	for(int i =1; i<= n; i++) {
		for(int j = 1; j<=n; j++) cin>>matrix[i][j];
	}
	
	answer = matrixPower(matrix,b,n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout<<answer[i][j]%1000<<" ";
		}
		cout<<'\n';
	}
	return 0;
}