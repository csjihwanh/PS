#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long int ll;

vector<pair<int,int>> mat;
ll dp[550][550];
const ll MAX = 98765432198;

ll calc(int s, int e) {
	if(dp[s][e] != 0) return dp[s][e];
	if(s==e) return dp[s][e]=0;
	ll min_value = MAX;
	for(int i = 0; i < (e-s); i++) {
		ll sum = calc(s,s+i)+calc(s+i+1,e)+(mat[s].first*mat[s+i].second*mat[e].second);
		min_value = min(min_value, sum);
	}
	return dp[s][e]=min_value;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);

	int temp1, temp2, n;
	
	cin>>n;
	mat.push_back(make_pair(0,0));
	for(int i = 1; i <= n; i++) {
		cin>>temp1>>temp2;
		mat.push_back(make_pair(temp1,temp2));
	}
	
	cout<<calc(1,n)<<'\n';
	
	return 0;
}