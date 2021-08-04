#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
vector<pair<int,int>> line;

int main (void ) {
	freopen("/workspace/PS_Git/BOJ/2170/input.txt", "r", stdin) ;
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	
	int n,temp1,temp2;
	pair<int,int> cur;
	ll sum = 0;

	cin>>n;
	for(int i =0;i<n;i++) {
		cin>>temp1>>temp2;
		line.emplace_back(make_pair(temp1,temp2));
	}
	sort(line.begin(), line.end());
	
	cur = line[0];
	for(int i =0; i<n; i++) {
		if(line[i].first <= cur.second)	
			cur.second=max(cur.second,line[i].second);
		else {
			sum+= cur.second-cur.first;
			cur=line[i];
		}
		cout<<cur.first<<" "<<cur.second<<endl;
	}
	sum+=cur.second-cur.first;
	
	cout<<sum<<'\n';
	
	return 0;
}