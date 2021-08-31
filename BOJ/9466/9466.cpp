#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 100500;
const int UNVISITED = 0;
const int CYCLE = 1;
const int NO_CYCLE = 2;

int parent[MAX_N];
vector<bool> route(MAX_N);
vector<int> visited(MAX_N);
int t,n;

void init() {
	for(int i = 0; i < MAX_N; i++) {
		visited[i]=false;
		parent[i]=0;
		route[i]=false;
	} 
}

void foundCycle(int node) {
	visited[node]= CYCLE;
	if(visited[parent[node]]) return;
	foundCycle(parent[node]);
}

int DFS(int node, int start) {
	if(route[node] || parent[node]==node) {
		foundCycle(node);
		route[node]=false;
		return NO_CYCLE;
	}
	
	route[node] = true;
	
	if(visited[parent[node]]) return visited[node]=NO_CYCLE;
	
	int res = DFS(parent[node],start);
	
	if(!visited[node]) visited[node]=res;
	
	route[node] =false;
	return res;
}
	

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);

	cin>>t;
	while(t--) {
		init();
		cin>>n;
		
		for(int i = 1; i <= n; i++)	cin>>parent[i];
		
		for(int i = 1; i<=n; i++) {
			if(visited[i]) continue;
			DFS(i,i);
		}
		int answer= 0;
		for(int i = 1; i <=n ;i++) {
			if(visited[i]!=1)answer++;
		}
		cout<<answer<<'\n';
	}
	
	return 0;
}