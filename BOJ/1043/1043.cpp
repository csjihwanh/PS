#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
int n;
vector<int> people;
vector<bool> truth;

void Init() {
	for(int i = 1; i <= n; i++ ){
		people[i]=i;
		truth[i]=false;
	}
}

void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Find(int node) {
	if(people[node]==node) return node;
	return people[node]=Find(people[node]);
}

void Union(int node1, int node2) {
	if(node1>node2) Swap(&node1, &node2);
	int root1, root2;
	root1 = Find(node1), root2 = Find(node2);
	people[root2]=people[root1];
}


int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int num_party,t, temp, node, answer = 0;
	vector<vector<int>> party;
	
	cin>>n>>num_party;
	cin>>t;
	truth.resize(t+1); people.resize(n+1);
	party.resize(num_party+1);
	
	Init();
	
	for(int i = 1; i <=t ; i++) {
		cin>>temp;
		truth[temp]=true;
	}
	for(int i = 1; i <= num_party; i++) {
		cin>>temp;
		party[i].emplace_back(0);
		for(int j = 1; j <= temp; j++) {
			cin>>node;
			party[i].emplace_back(node);
			Union(party[i][1],node);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if((truth[i]==true)) truth[Find(i)]=true;
	}
	
	for(int i = 1; i <= num_party; i++) {
		if(truth[Find(party[i][1])]==false) {
			answer++; 
		}
	}
	
	cout<<answer<<'\n';
	return 0;
}