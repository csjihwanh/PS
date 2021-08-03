#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxN = 55;
vector<int> child[maxN];
vector<int> parent;
vector<int> root;
int n, cnt=0;

void DFS(int node) {
	if(child[node].empty()) cnt++;
	for(int i = 0; i<child[node].size(); i++) {
		cout<<"from "<<node<<"to"<<child[node][i]<<'\n';
		DFS(child[node][i]);
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/1068/input.txt","r",stdin);
	
	int temp;
	
	cin>>n;
	for(int i =0; i<n; i++) {
		cin>>temp;
		parent.emplace_back(temp);
	}
	
	cin>>temp;//to clear;
	for(int i = 0; i<n; i++) {
		if(i==temp) continue;
		if(parent[i]!=-1)child[parent[i]].emplace_back(i);
		else root.emplace_back(i);
	}
	
	for(int i =0; i<root.size(); i++) {
		DFS(root[i]);
	}
	
	cout<<cnt<<'\n';
	
	return 0;
}