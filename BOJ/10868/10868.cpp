#include <iostream>
#include <math.h>
#include <vector>
#define MAX 2000000000

using namespace std;

const int max_n = 100500;
vector<int> arr={0};
vector<int> tree(max_n*2);

int init(int start, int end, int node) {
	if(start==end) return tree[node] = arr[start];
	int mid = (start+end)/2;
	return tree[node] = min(init(start,mid,node*2),init(mid+1,end,node*2+1));
}

int query(int start, int end, int node, int left, int right) {
	if(start>=left && end <= right) return tree[node];
	if(end<left || start > right) return MAX;
	int mid = (start+end)/2;
	return min(query(start,mid,node*2, left,right),query(mid+1,end,node*2+1,left,right));
}

int main ( void ) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	
	freopen("/workspace/PS_Git/BOJ/10868/input.txt","r",stdin);
	int n, m, temp1, temp2;
	cin>>n>>m;
	for(int i = 1; i<= n;i++) {
		cin>>temp1;
		arr.emplace_back(temp1);
	}
	
	init(1,n,1);
	for(int i = 1; i<= m; i++) {
		cin>>temp1>>temp2;
		cout<<query(1,10,1,temp1,temp2)<<'\n';
	}
}