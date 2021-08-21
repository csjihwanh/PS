#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, t,temp, a, b;
	vector<int> arr, dp;
	arr.push_back(0); dp.push_back(0);
	
	cin>>n>>t;
	for(int i = 1; i <= n; i++ ){
		cin>>temp;
		arr.push_back(temp);
		dp.push_back(dp[i-1]+temp);
	}
	
	while(t--) {
		cin>>a>>b;
		cout<<dp[b]-dp[a-1]<<'\n';
	}
	
	return 0;
}