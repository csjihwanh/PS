#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> prob;

struct comp2 {
    bool operator()(pair<int,int>a, pair<int,int>b) {
       return a.second<b.second;
	}
};

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first<b.first;
}

priority_queue<pair<int,int>, vector<pair<int,int>>, comp2> probAble;

int main ( void ) {
	freopen("/workspace/PS_Git/BOJ/1781/input.txt", "r", stdin);
	
	int temp1, temp2;
	int maxScore = 0;
	int maxTime = -1, curTime;
	int index, sum=0;
	prob.push_back(make_pair(0,0));
	
	scanf("%d", &n);
	for(int i =0 ; i<n; i++) {
		scanf("%d %d", &temp1, &temp2);
		prob.push_back(make_pair(temp1,temp2));
		maxTime = max(maxTime, temp1);
	}
	
	sort(prob.begin(),prob.end(), comp);
	index = n;
	
	for(curTime = maxTime; curTime > 0; curTime--) {
		while(prob[index].first >= curTime ) {
			probAble.push(prob[index]);
			index--;
		}
		if(probAble.empty()) continue;
		sum+= probAble.top().second;
		probAble.pop();
	}
	
	cout<<sum<<endl;
	return 0;
}