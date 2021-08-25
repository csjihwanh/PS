#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector<vector<ll>> Matrix_s;
const ll MOD = 1e6;

Matrix_s matrixMulti(Matrix_s& a, Matrix_s& b) {
	Matrix_s answer;
	int n = a.size()-1;
	answer.resize(n+1,vector<ll>(n+1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ll sum = 0;
			for(int k = 1; k <= n; k++)
				sum += a[i][k]*b[k][j];
			answer[i][j] =sum%MOD;
		}
	}
	return answer;
}

Matrix_s matrixPower(Matrix_s&matrix, ll times, int n) {
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
	//freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	ll n=2,b;
	Matrix_s matrix, answer;
	
	cin>>b;
	matrix.resize(n+1,vector<ll>(n+1)), answer.resize(n+1, vector<ll>(n+1));
	matrix={{0,0,0},{0,1,1},{0,1,0}};
	
	if(b<=1) {
		cout<<b;
		return 0;
	}
	answer = matrixPower(matrix,b-1,n);
	
	cout<<answer[1][1]%MOD;
	return 0;
}