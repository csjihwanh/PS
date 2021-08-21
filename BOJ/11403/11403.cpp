#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define D cout<<"hello"<<endl;

using namespace std;
const int MAX_N=105;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n;
	int adj[MAX_N][MAX_N], clos[MAX_N][MAX_N];
	
	cin>>n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin>>adj[i][j];
			clos[i][j]=adj[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				clos[j][k] |= clos[j][i]&clos[i][k];
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout<<clos[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}