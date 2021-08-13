#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX_N = 500500;
int n,m;
vector<int> troop(MAX_N);
vector<int> tree(MAX_N*4);

int init(int left, int right, int node) {
	if(left==right) return tree[node]=troop[left];
	int mid=(left+right)/2;
	return tree[node]=init(left,mid,node*2)+init(mid+1,right,node*2+1);
}

void update(int left, int right, int node, int index, int diff) {
	if(index < left || index > right) return;
	if(index == left && index == right) {
		tree[node]+=diff;
		return;
	}
	int mid = (left+right)/2;
	update(left,mid,node*2,index,diff);
	update(mid+1,right,node*2+1,index,diff);
	tree[node]=tree[node*2]+tree[node*2+1];
}

int query(int left, int right, int node, int thres, int sum) {
	if(left==right) return left;
	int mid = (left+right)/2;
	if(sum+tree[node*2]>=thres) return query(left,mid,node*2,thres,sum);
	else return query(mid+1, right, node*2+1, thres, sum+tree[node*2]);
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	int option,target,diff;
	
	cin>>n;
	
	troop.emplace_back(0);
	for(int i = 1 ; i <= n; i++) cin>>troop[i];
	
	init(1,n,1);
	
	cin>>m;
	
	for(int i = 1; i<=m; i++) {
		cin>>option;
		if(option==1) {
			cin>>target>>diff;
			update(1,n,1,target,diff);
		}
		else if(option==2) {
			cin>>target;
			cout<<query(1,n,1,target,0)<<'\n';
		}
	}
	
	return 0;
}