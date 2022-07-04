#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int num_range = 20050;

int tree[5*num_range];

void update(int start, int end, int node, int target) {
	if(target < start || end < target) return ;
	tree[node]++;
	//cout<<start-10000<<" "<<end-10000<<" updated to "<<tree[node]<<endl;
	if(start==end) return;
	
	int mid = (start+end)/2;
	update(start,mid,node*2,target);
	update(mid+1,end,node*2+1,target);
}

int find(int start, int end, int node, int target) {
	if(start==end) return start-10000;
	//cout<<"find "<<start<<" "<<end<<endl;
	
	int mid = (start+end)/2;
	if(tree[node*2] >= target) return find(start,mid,node*2, target);
	else return find(mid+1, end, node*2+1, target-tree[node*2]);
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	
	int n, temp;
	cin>>n;
	for(int i = 1; i <=n ; i++) {
		cin>>temp;
		temp+=10000;
		update(0,20000,1,temp);
		int mid = (i%2==1)? i/2+1 : i/2;
		cout<<find(0,20000,1,mid)<<'\n';
	}
	
	return 0;
}