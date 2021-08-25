#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

struct comp{
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second >= b.second;
	}
};

const int MAX = 987654321;
const int MAX_N = 1050;
vector<vector<pair<int,int>>> map;
vector<int> minCost(MAX_N);
priority_queue<pair<int,int>,vector<pair<int,int>>,comp> unvisited;
vector<int> previ(MAX_N);
vector<bool> visited(MAX_N);

void init(int n) {
	for(int i = 0; i <= n; i++) {
		minCost[i]= MAX;
		visited[i]=false;
		previ[i]=i;
	}
}

void dijkstra(int s, int n) {
	init(n);
	minCost[s] = 0;
	unvisited.push(make_pair(s,0));
	
	while(!unvisited.empty()) {
		pair<int,int>cur= unvisited.top();
		unvisited.pop();
		if(visited[cur.first]) continue;
		visited[cur.first] = true;
		for(int i = 0; i < map[cur.first].size(); i++) {
			pair<int,int>next= map[cur.first][i];
			if(minCost[cur.first]+next.second < minCost[next.first]) {
				previ[next.first]=cur.first;
				minCost[next.first] = minCost[cur.first]+next.second;
				unvisited.push(make_pair(next.first,minCost[next.first]));
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, e, u,v, v1, v2;
	long long cost;
	cin>>n>>e;
	map.resize(n+1);
	for(int i =1 ; i <= e; i++) {
		cin>>u>>v>>cost;
		map[u].emplace_back(make_pair(v,cost));
	}
	cin>>v1>>v2;
	
	dijkstra(v1,n);
	
	cout<<minCost[v2]<<'\n';
	
	int track = v2;
	vector<int> trackVert;
	while(track!=previ[track]) {
		trackVert.push_back(track);
		track= previ[track];
	}
	trackVert.push_back(previ[track]);
	cout<<trackVert.size()<<endl;
	
	for(int i = trackVert.size()-1; i >=0; i--)cout<<trackVert[i]<<" "; 

	return 0;
}