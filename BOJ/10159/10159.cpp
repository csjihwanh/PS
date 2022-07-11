#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>
#define D cout<<"whyme\n";

using namespace std;

const int max_n = 105;
int n, m;
vector<vector<int>> in_map(max_n), out_map(max_n);
bool visit[max_n];

void initVisit() {
	for(int i = 1; i <= n; i++) 
		visit[i]=false;
}

int BFS(vector<vector<int>> map, int start) {
	queue<int> q;
	int cnt = 0;
	q.push(start);
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		cnt++;
		for(int i = 0 ; i < map[current].size(); i++) {
			if(visit[map[current][i]]) continue;
			q.push(map[current][i]);
			visit[map[current][i]] = true;
		}
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);

	int temp1, temp2;
	
	cin>>n>>m;
	for(int i = 1; i <= m; i++) {
		cin>>temp1>>temp2;
		out_map[temp1].push_back(temp2);
		in_map[temp2].push_back(temp1);
	}
	
	for(int i = 1; i <= n; i++) {
		
		int cnt = 0; 
		initVisit();
		cnt+= BFS(out_map, i);
		cnt+= BFS(in_map, i);
		
		cout<<n-cnt+1<<'\n';
	}
	
	
	return 0;
}