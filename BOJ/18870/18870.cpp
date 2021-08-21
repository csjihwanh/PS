#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	vector<int> num, tempVec;
	map<int,int> match;
	int n, temp;
	
	num.push_back(0);
	cin>>n;
	for(int i = 1; i <=n ; i++ ){
		cin>>temp;
		num.push_back(temp);
	}
	
	tempVec.resize(num.size()+1);
	copy(num.begin(),num.end(),tempVec.begin());
	
	sort(tempVec.begin()+1, tempVec.end()-1);
	temp=0;
	match.insert(make_pair(tempVec[1],temp));
	for(int i = 2; i <= n; i++) {
		if(tempVec[i]!=tempVec[i-1]) match.insert(make_pair(tempVec[i],++temp));
	}
	
	for(int i = 1; i <= n; i++) cout<<match[num[i]]<<" ";
	
	return 0;
}