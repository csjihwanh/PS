#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
const int MAX_N = 100500;
const int MIN = -987654321;

typedef struct edge {
	int dest;
	int weight;
}Edge;

vector<bool> good(MAX_N);
vector<Edge> adj[MAX_N];
vector<bool> complex(MAX_N);
vector<bool> visited(MAX_N);

bool DFS(int node) {
	bool passComplex= false;
	for(int i = 0 ; i < adj[node].size(); i++) {
		if(visited[adj[node][i].dest]==false) {
			visited[adj[node][i].dest]=true;
			if(DFS(adj[node][i].dest)==true) passComplex=true;
		}
	}
	if(complex[node]==true) passComplex=true;
	return good[node]=passComplex;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, k;
	int temp1,temp2;
	int leastComplex=-1;
	int answer = 0;
	Edge tempEdge;
	cin>>n>>k;
	
	for(int i = 0 ; i < n-1; i ++ ) {
		cin>>temp1>>temp2>>tempEdge.weight;
		tempEdge.dest= temp2;
		adj[temp1].emplace_back(tempEdge);
		tempEdge.dest = temp1;
		adj[temp2].emplace_back(tempEdge);
	}
	
	for(int i = 0; i < k; i++ ){
		cin>>temp1;
		complex[temp1]=true;
		if(i==0)leastComplex=temp1;
	}
	
	visited[leastComplex]=1;
	DFS(leastComplex);
	
	
	for(int i = 1; i <= n; i++) answer+=good[i];
	cout<<answer<<'\n';
	
	return 0;
}