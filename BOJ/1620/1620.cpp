#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include<map>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	map<int,string> is_map;
	map<string,int> si_map;
	int n,m, code;
	string name;
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>name;
		is_map.insert(make_pair(i,name));
		si_map.insert(make_pair(name,i));
	}
	
	while(m--) {
		cin>>name;
		if(name.at(0) >= 'A' && name.at(0) <= 'Z') {
			cout<<si_map[name]<<'\n';
		}
		else {
			code = stoi(name);
			cout<<is_map[code]<<'\n';
		}
	}
	
	return 0;
}