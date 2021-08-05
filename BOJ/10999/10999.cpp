#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
const int maxN = 1000500;
vector<ll> arr;
vector<ll> tree(maxN*4), lazy(maxN*4);

ll init(int left, int right, int node) {
	if(left==right) return tree[node]=arr[left];
	int mid= (left+right)/2;
	return tree[node] = init(left,mid,node*2) + init(mid+1,right,node*2+1);
}

void propagation(int left, int right, int node) {
	if(lazy[node]!=0){
		tree[node]+=(right-left+1) * lazy[node];
		if(left!=right) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node]=0;
	}
}

void update(int left, int right, int node, int uleft, int uright, ll diff) {
	 propagation(left,right,node);
	
	if(uright<left || right<uleft) return;
	
	if(uleft<=left && right<=uright) { 
		lazy[node]=diff;
		propagation(left,right,node);
		return;
	}
	int mid = (left+right)/2;
	update(left,mid,node*2,uleft,uright,diff);
	update(mid+1,right,node*2+1,uleft,uright,diff);
	tree[node]= tree[node*2]+tree[node*2+1];
}

ll query(int left, int right, int node, int qleft, int qright) {
	propagation(left,right,node);
	if(qleft > right || qright < left) return 0;
	if(left>=qleft && right<=qright) return tree[node];
	int mid = (left+right)/2;
	return query(left,mid,node*2,qleft,qright)+query(mid+1,right,node*2+1,qleft,qright);
}


int main ( void ) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/10999/input.txt","r",stdin);
	
	int n,q;
	ll temp1,temp2;
	int range1, range2;
	
	cin>>n>>temp1>>temp2;
	q=temp1+temp2;
	
	arr.emplace_back(0);
	for(int i = 1; i<=n; i++) {
		cin>>temp1;
		arr.emplace_back(temp1);
	}
	init(1,n,1);
	
	for(int i =1; i<=q; i++) {
		cin>>temp1;
		if(temp1==1) {
			cin>>range1>>range2>>temp1;
			update(1,n,1,range1,range2,temp1);
		}
		else if(temp1==2) {
			cin>>temp1>>temp2;
			cout<<query(1,n,1,temp1,temp2)<<'\n';
		}
		
	}
	return 0;
}