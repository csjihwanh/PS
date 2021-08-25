#include <iostream>
#include<math.h>

using namespace std;
int arr[4];
int min_dp[4], max_dp[4], prev_min[4], prev_max[4];
void swap(int* now, int* prev) {
	for(int i = 1; i<=3; i++) prev[i]=now[i];
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j<=3; j++)cin>>arr[j];
		swap(min_dp,prev_min);
		swap(max_dp,prev_max);
		min_dp[1] = min(prev_min[1],prev_min[2])+arr[1];
		min_dp[2] = min(min(prev_min[1],prev_min[2]),prev_min[3])+arr[2];
		min_dp[3]=min(prev_min[2],prev_min[3])+arr[3];
		max_dp[1]=max(prev_max[1],prev_max[2])+arr[1];
		max_dp[2]=max(max(prev_max[1],prev_max[2]),prev_max[3])+arr[2];
		max_dp[3]=max(prev_max[2],prev_max[3])+arr[3];
		
	}
	cout<<max(max(max_dp[1],max_dp[2]),max_dp[3])<<" "<<min(min(min_dp[1],min_dp[2]),min_dp[3]);
	return 0;
}