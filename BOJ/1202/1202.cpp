#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef struct item_s {
	int mass, value; 
}ITEM_S;
typedef long long int ll;
struct comp_value {
	bool operator()(ITEM_S a, ITEM_S b) {
		return (a.value < b.value);
	}
};
bool comp_mass (ITEM_S a, ITEM_S b){
	return (a.mass < b.mass);
};

vector<ITEM_S> item;
vector<int> bag;
priority_queue<ITEM_S, vector<ITEM_S>, comp_value> ableItem;
int n,k;
ll answer = 0;

ITEM_S makeItem(int myMass, int myValue) {
	ITEM_S myItem;
	myItem.mass = myMass;
	myItem.value = myValue;
	return myItem;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int temp1, temp2;
	cin>>n>>k;
	for(int i = 1; i <= n; i++) {
		cin>>temp1>>temp2;
		item.push_back(makeItem(temp1,temp2));
	}
	for(int i = 1; i <= k; i++) {
		cin>>temp1;
		bag.push_back(temp1);
	}
	sort(bag.begin(),bag.end());
	sort(item.begin(), item.end(), comp_mass);
	
	int bagIdx = 0;
	for(int i = 0; i < k; i++) {
		int curBag = bag[i];
		for( ; bagIdx < item.size(); ) {
			if(item[bagIdx].mass <= curBag) ableItem.push(item[bagIdx++]);
			else break;
		}
		
		if(ableItem.size() <=0 ) continue;
		ITEM_S maxItem = ableItem.top();
		answer+= maxItem.value;
		ableItem.pop();
	}
	
	cout<<answer;
	
	return 0;
}