#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 32050;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n,m;
	int temp1, temp2;
	vector<int> order[MAX_N];
	vector<int> degree(MAX_N);
	//vector<int> answer;
	priority_queue<int,vector<int>,greater<int>> Q;
	
	cin>>n>>m;
	
	for(int i = 1; i <= m; i++) {
		cin >>temp1>>temp2;
		order[temp1].emplace_back(temp2);
		degree[temp2]++;
	}
	
	for(int i = 1; i<=n; i++) {
		if(degree[i]==0) Q.push(i);
	}
	
	while(!Q.empty()) {
		int cur = Q.top();
		cout<<cur<<" ";
		Q.pop();
		for(int i = 0; i< order[cur].size(); i++) {
			int next = order[cur][i];
			degree[next]--;
			if(degree[next]==0) Q.push(order[cur][i]);
		}
	}
	
	cout<<'\n';
	return 0;
}