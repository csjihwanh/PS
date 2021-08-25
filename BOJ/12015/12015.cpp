#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long int ll;

const ll MAX_N=1000500;
vector<ll> tree(MAX_N*4); //the maximum length with that number
vector<ll> arr(MAX_N);

ll query(int left, int right, int node, int qleft, int qright) {
	//cout<<left<<" "<<right<<" "<<qleft<<" "<<qright<<endl;
	if(qleft > right || qright < left) return 0;
	if(qleft <= left && right <= qright) return tree[node];
	int mid = (left +right)/2;
	return max(query(left,mid,node*2,qleft,qright),query(mid+1,right,node*2+1,qleft,qright));
}

void update(int left, int right, int node, int index, ll modi) {
	if(index < left || index > right) return;
	tree[node] = max(tree[node],modi);
	if(index == left && index ==right) return ;
	int mid = (left +right)/2;
	update(left, mid, node*2, index, modi);
	update(mid+1, right, node*2+1 ,index, modi);
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n,temp;
	ll answer=0;
	cin>>n;
	
	arr.emplace_back(0);
	for(int i = 1; i <=n; i++) cin>>arr[i];
	
	for(int i = 1; i <= n; i++) {
		
		ll maxLen = query(1,MAX_N,1,1,arr[i]-1);
		update(1,MAX_N,1,arr[i],maxLen+1);
		answer=max(answer,maxLen+1);
	}
	
	cout<<answer<<'\n';
	
	return 0;
}