#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
int n,t;
int minCnt = 987654321;
vector<int>order(25);

void move(int left, int right, int cnt, int idx) {
	if(left==right) return;
	if(idx > t) {
		minCnt = min(minCnt, cnt); 
		return;
	}
	if(order[idx]<left) move(order[idx],right,cnt+left-order[idx],idx+1);
	else if(order[idx]>right) move(left, order[idx], cnt+order[idx]-right,idx+1);
	else { // left <= order[idx] <= right
		move(order[idx],right,cnt+order[idx]-left,idx+1);
		move(left,order[idx],cnt+right-order[idx],idx+1);
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/2666/input.txt","r",stdin);
	
	int left, right;
	cin>>n>>left>>right>>t;

	for(int i = 1; i <=t ; i++) cin>>order[i];
	
	move(min(left, right),max(left,right), 0, 1);
	cout<<minCnt<<'\n';
	return 0;
}