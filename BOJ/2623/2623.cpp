#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_V = 1000;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, m, cnt, cur, next;
	vector<int> degree(MAX_V+50), ans;
	vector<vector<int>> parent(MAX_V+50);
	queue<int> q;
	
	cin>>n>>m;
	for(int i = 0 ;i < m; i++) {
		cin>>cnt>>cur;
		while(--cnt) {
			cin>>next;
			parent[cur].push_back(next);
			degree[next]++;
			cur=next;
		}
	}
	
	for(int i = 1 ; i<= n; i++) 
		if(!degree[i]) q.push(i);
	
	while(!q.empty()) {
		cur = q.front();
		ans.push_back(cur);
		q.pop();
		for(int i = 0; i < parent[cur].size(); i++) {
			cout<<cur<<" "<<parent[cur][i]<<endl;
			degree[parent[cur][i]]--;
			if(!degree[parent[cur][i]]) q.push(parent[cur][i]);
		}
	}
	
	if(ans.size() != n) {
		cout<<0;
		return 0;
	}
	for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
	
	return 0;
}