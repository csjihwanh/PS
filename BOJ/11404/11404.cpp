#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 987654321;

void init(vector<vector<int>>&dist, int n) {
	for(int i = 1; i <= n; i++) {
		dist[i].resize(n+1);
		for(int j = 1; j <= n; j++) {
			dist[i][j]=MAX;
		}
		dist[i][i]=0;
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, m,u,v,tempDist;
	vector<vector<int>> dist;
	
	cin>>n>>m;
	dist.resize(n+1);
	init(dist,n);
	for(int i =1 ; i <= m; i++) {
		cin>>u>>v>>tempDist;
		dist[u][v]=min(dist[u][v],tempDist);
	}
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout<<(dist[i][j]==MAX? 0:dist[i][j])<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}