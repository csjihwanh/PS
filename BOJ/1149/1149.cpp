#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, r, g, b;
	int dp[1050][4]={{0,0,0,0}};
	
	cin>>n;
	for(int i =1; i <= n; i++) {
		cin>>r>>g>>b;
		dp[i][1] = min(dp[i-1][2],dp[i-1][3])+r;
		dp[i][2] = min(dp[i-1][1],dp[i-1][3])+g;
		dp[i][3]=min(dp[i-1][1],dp[i-1][2])+b;
	}
	cout<<min(min(dp[n][1],dp[n][2]),dp[n][3])<<endl;
	return 0;
}