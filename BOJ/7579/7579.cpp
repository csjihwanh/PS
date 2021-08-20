#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n,m,temp, answer=-1;
	vector<int> cost, mem;
	int dp[105][10050];
	cost.emplace_back(-1); mem.emplace_back(-1);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>temp;
		mem.emplace_back(temp);
	}
	for(int i = 1; i <= n; i++) {
		cin>>temp;
		cost.emplace_back(temp);
	}
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= 10000; j++) 
			dp[i][j]=-1;

	dp[0][0]=0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0 ; j <= 10000; j++) {
			if(dp[i-1][j]==-1)	continue;
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
			dp[i][j+cost[i]]=max(dp[i][j+cost[i]],dp[i-1][j]+mem[i]);
			dp[i][j+cost[i]]=max(dp[i][j+cost[i]],dp[i-1][j+cost[i]]);
		}
	}
	
	for(int i = 1; i <= 10000; i++) {
		if(dp[n][i]>=m) {
			answer = i;
			break;
		}
	}
	cout<<answer;
	return 0;
}