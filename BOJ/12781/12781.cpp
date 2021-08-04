#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 100050;
vector<int> child[maxN], parent;
queue<int> q;
bool visited[maxN];

int main(void ) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/12781/input.txt","r",stdin);
	int n , cur;
	int temp1, temp2;
	
	cin>>n;
	parent.resize(n+1);
	for(int i = 1; i <  n; i++) {
		cin>>temp1>>temp2;
		child[temp1].emplace_back(temp2);
		child[temp2].emplace_back(temp1);
	}
	
	q.push(1);
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		for(int i = 0; i < child[cur].size(); i++) {
			if(visited[child[cur][i]])continue;
			q.push(child[cur][i]);
			parent[child[cur][i]]=cur;
			visited[child[cur][i]]=true;
		}
	}
	
	for(int i = 2; i<=n; i++) cout<<parent[i]<<'\n';
	
	return 0;
	
}