#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<int> uf_parent; 

int uf_find(int a) {
	if(uf_parent[a]==a) return a;
	else return uf_find(uf_parent[a]);
}

void uf_union(int a, int b) {
	int root_a = uf_find(a);
	int root_b = uf_find(b);
	if(root_a == root_b) return;
	uf_parent[root_b] = root_a;
	uf_parent[b] = root_a;
	uf_parent[a] = root_a;
}


int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int temp1, temp2;
	
	cin>>n>>m;
	
	for(int i = 0 ; i<n; i++) 
		uf_parent.push_back(i);
	
	for(int i = 0 ; i< m; i++) {
		cin>>temp1>>temp2;
		if(uf_find(temp1)==uf_find(temp2)) {
			cout<<i+1;
			return 0;
		}
		uf_union(temp1,temp2);
	}
	cout<<0;
	return 0;
	
}