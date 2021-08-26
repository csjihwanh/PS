#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include<cstring>

using namespace std;
const int MAX_V = 55;

typedef struct edge_s{
	int flow,capacity;
}Edge_s;

int maxFlow = 0;
Edge_s pipe[MAX_V][MAX_V] ;
vector<bool> visited(MAX_V);

int ctoi(char x) {
	if(x >= 'A' && x <= 'Z')
		return x-'A'+1;
	else return x-'a'+1+26;
}

bool DFS(int node) {
	if(node == ctoi('Z')) return true;
	for(int i = 0 ; i< MAX_V; i++) {
		if(pipe[node][i].capacity-pipe[node][i].flow>0 && visited[i]==false) {
			visited[i]=true;
			if(DFS(i)) {
				pipe[node][i].flow++;
				pipe[i][node].flow--;
				visited[i]=false;
				return true;
			}
			visited[i]=false;
		}
	}
	return false;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n,u_int,v_int,capacity;
	char u_char, v_char;
	memset(pipe,0,sizeof(pipe));
	
	cin>>n;
	for(int i = 1; i<=n;i++) {
		cin>>u_char>>v_char>>capacity;
		u_int = ctoi(u_char); v_int = ctoi(v_char);
		pipe[u_int][v_int].capacity += capacity;
		pipe[v_int][u_int].capacity += capacity;
	}
	
	int start = ctoi('A');
	
	visited[start]=true;
	while(DFS(start)){maxFlow++;};
	cout<<maxFlow;
	
	return 0;
}