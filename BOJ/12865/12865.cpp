#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, k,tempw,tempv, max_value = -987654321;
	vector<int>w,v,dp(105000), prev(100500);
	w.push_back(0),v.push_back(0);
	
	cin>>n>>k;
	for(int i = 1; i <= n; i++) {
		cin>>tempw>>tempv;
		w.push_back(tempw);v.push_back(tempv);
	}
	
	for(int i = 1; i <= 105000; i++) dp[i]=-1;
	prev[0]=0;
	for(int i = 1; i <= n; i++ ) {
		for(int j =0; j<=100000;j ++) {
			prev[j]=dp[j];
		}
		for(int j=0;j<=100000;j++) {
			if(prev[j]==-1 || j +w[i] > k) continue;
			dp[j+w[i]] = max(prev[j+w[i]], prev[j]+v[i]);
		}
		
	}
	for(int i = 0; i <= k; i++) {
		max_value=max(max_value,dp[i]);
	}
	cout<<max_value;
	
	return 0;
}