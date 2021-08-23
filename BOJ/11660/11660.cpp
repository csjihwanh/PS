#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
int arr[1025][1025], dp[1025][1025];

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, m, a,b,c,d;
	cin>>n>>m;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++ ) {
			cin>>arr[i][j];
			dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
		}
	
	while(m--) {
		cin>>a>>b>>c>>d;
		cout<<dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1]<<'\n';
	}
	
	return 0;
}