#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef long long int ll;
typedef struct Edge_s_s {
	int u, v, cost;
}Edge_s;

const ll INF = 98765432198;
const int start = 1;

void init(vector<ll>& dist) {
	for(int i = 1; i < dist.size(); i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
}


bool Bellman_Ford(vector<Edge_s>&edge, vector<ll>&dist) {
	init(dist);
	
	for(int i = 1; i < dist.size(); i++)
		for(int j = 1; j < edge.size(); j++)
			if(dist[edge[j].v] > dist[edge[j].u]+edge[j].cost && dist[edge[j].u]!=INF)
				dist[edge[j].v] = dist[edge[j].u]+edge[j].cost;
	
	for(int i = 1; i < edge.size(); i++)
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].cost && dist[edge[i].u] != INF) 
			return false;

	return true;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, m;
	Edge_s temp;
	vector<Edge_s> edge;
	vector<ll> dist;
	memset(&temp, 0, sizeof(Edge_s));
	edge.emplace_back(temp);
	
	cin>>n>>m;
	edge.resize(m+1); dist.resize(n+1);
	for(int i = 1; i <= m; i++) {
		cin>>temp.u>>temp.v>>temp.cost;
		edge.emplace_back(temp);
	}
	
	if(!Bellman_Ford(edge, dist)) {
		cout<<-1;
		return 0;
	}
	for(int i = 2; i <= n; i ++) {
		cout<<(dist[i]==INF? -1:dist[i])<<'\n';
	}
	
	return 0;
}