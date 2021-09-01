#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 1e6;
int dp[MAX_N+5000], track[MAX_N+5000];
vector<int> back;
queue<int> q;

void pushQ(int next, int cur) {
	if(cur<0) return;
	if(dp[next]==0) {
		dp[next] = dp[cur]+1;
		track[next]=cur;
		q.push(next);
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, cur, next;
	cin>>n;
	q.push(n);
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		if(cur==1) break;
		pushQ(cur-1,cur);
		if(cur%2==0) pushQ(cur/2,cur);
		if(cur%3==0) pushQ(cur/3,cur);
	}
	
	cout<<dp[1]<<'\n';
	while(cur!=n) {
		back.push_back(cur);
		cur= track[cur];
	}
	
	cout<<n<<" ";
	for(int i = back.size()-1; i>=0; i--) cout<<back[i]<<" ";
	
	
	return 0;
}