#include <iostream>
#include <math.h>
#include <vector>
#define MAX 2000000000
#define MIN -2000000000

using namespace std;

const int max_n = 100500;
vector<int> arr={0};
vector<int> treeMin(max_n*4), treeMax(max_n*4);

int initMin(int start, int end, int node) {
	if(start==end) return treeMin[node] = arr[start];
	int mid = (start+end)/2;
	return treeMin[node] = min(initMin(start,mid,node*2),initMin(mid+1,end,node*2+1));
}

int initMax(int start, int end, int node) {
	if(start==end) return treeMax[node] = arr[start];
	int mid = (start+end)/2;
	return treeMax[node] = max(initMax(start,mid,node*2),initMax(mid+1,end,node*2+1));
}

int queryMin(int start, int end, int node, int left, int right) {
	if(start>=left && end <= right) return treeMin[node];
	if(end<left || start > right) return MAX;
	int mid = (start+end)/2;
	return min(queryMin(start,mid,node*2, left,right),queryMin(mid+1,end,node*2+1,left,right));
}

int queryMax(int start, int end, int node, int left, int right) {
	if(start>=left && end <= right) return treeMax[node];
	if(end<left || start > right) return MIN;
	int mid = (start+end)/2;
	return max(queryMax(start,mid,node*2, left,right),queryMax(mid+1,end,node*2+1,left,right));
}

int main ( void ) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	
	freopen("/workspace/PS_Git/BOJ/2357/input.txt","r",stdin);
	int n, m, temp1, temp2;
	cin>>n>>m;
	for(int i = 1; i<= n;i++) {
		cin>>temp1;
		arr.emplace_back(temp1);
	}
	
	initMin(1,n,1);
	initMax(1,n,1);
	for(int i = 1; i<= m; i++) {
		cin>>temp1>>temp2;
		cout<<queryMin(1,n,1,temp1,temp2)<<" "<<queryMax(1,n,1,temp1,temp2)<<'\n';

	}
}