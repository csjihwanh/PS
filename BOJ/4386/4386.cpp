#include <queue>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

typedef pair<double,pair<int,int>> Route;
typedef struct {
	bool operator()(Route a, Route b) {
		return a.first > b.first;
	}
}RouteComp;


const int MAX_N = 105;
vector<pair<float,float>> star;
priority_queue<Route,vector<Route>,RouteComp> edge;
vector<int> uf_parent;
double cost_sum = 0;
int n;

int uf_find(int a) {
	if(uf_parent[a]==a) return a;
	else return uf_find(uf_parent[a]);
}

void uf_union(int a, int b) {
	int root_a = uf_find(a);
	int root_b = uf_find(b);
	if(root_a == root_b) return;
	uf_parent[root_b] = root_a;
	uf_parent[b] = root_a;
}

bool uf_check() {
	for(int i = 0 ; i< n; i++) {
		if(uf_find(i) != uf_find(0)) 
			return false;
	}
	return true;
}


int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	float temp1,temp2;
	double cost;
	
	cin>>n;
	for(int i = 0; i < n; i ++) {
		cin>>temp1>>temp2;
		star.push_back(make_pair(temp1,temp2));
		uf_parent.push_back(i);
	}
	
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j++) {
			if(i==j) continue;
			cost = sqrt(pow(star[i].first- star[j].first,2) + pow(star[i].second - star[j].second, 2) );
			edge.push(make_pair(cost, make_pair(i,j)));
		}
	}
	
	while(!edge.empty()) {
		Route current = edge.top();
		edge.pop();
		if(uf_find(current.second.first) == uf_find(current.second.second)) continue;
		cost_sum += current.first;
		uf_union(current.second.first, current.second.second);
		if(uf_check()) break;
	}
	cout<< cost_sum;
	
	return 0;
}