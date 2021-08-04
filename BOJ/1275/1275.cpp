#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
const int maxN = 1000500;
vector<ll> arr;
vector<ll> tree(maxN*4);

ll init(int left, int right, int node) {
	if(left==right) return tree[node]=arr[left];
	int mid= (left+right)/2;
	return tree[node] = init(left,mid,node*2) + init(mid+1,right,node*2+1);
}

void update(int left, int right, int node, ll diff, int index) {
	if(index<left || index > right) return;
	tree[node] +=diff;
	if(left==right) return;
	int mid = (left+right)/2;
	update(left,mid,node*2,diff,index);
	update(mid+1,right,node*2+1,diff,index);
}

ll query(int left, int right, int node, int qleft, int qright) {
	if(qleft > right || qright < left) return 0;
	if(left>=qleft && right<=qright) return tree[node];
	int mid = (left+right)/2;
	return query(left,mid,node*2,qleft,qright)+query(mid+1,right,node*2+1,qleft,qright);
}

void swap(ll* a, ll* b) {
	ll temp;
	if(*a > *b) {
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main ( void ) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/1275/input.txt","r",stdin);
	
	int n,q;
	ll temp1,temp2;
	
	cin>>n>>q;
	
	arr.emplace_back(0);
	for(int i = 1; i<=n; i++) {
		cin>>temp1;
		arr.emplace_back(temp1);
	}
	init(1,n,1);
	
	for(int i =1; i<=q; i++) {
		cin>>temp1>>temp2;
		swap(&temp1,&temp2);
		cout<<query(1,n,1,temp1,temp2)<<'\n';
		cin>>temp1>>temp2;
		update(1,n,1,temp2-arr[temp1],temp1);
		arr[temp1]= temp2;
	}
	return 0;
}