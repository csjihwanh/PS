#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 5555555555

using namespace std;

typedef long long int ll;
int n;
vector<ll> value;

int binarySearch(int start, ll cur) {
	ll sum=MAX;
	int left= start, right = n, mid=(left+right)/2;
	while(left<=right) {
		mid=(left+right)/2;
		if(abs(value[mid-1]+cur)< abs(value[mid]+cur)) right=mid-1; 
		else if(abs(value[mid+1]+cur)<abs(value[mid]+cur)) left=mid+1;
		else break;
	}
	return mid;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/2470/input.txt","r",stdin);
	
	int left, right;
	ll best[2], bestSum=MAX, sum, temp;
	
	cin>>n;
	value.emplace_back(0);
	for(int i = 0; i<n; i++) {
		cin>>temp;
		value.emplace_back(temp);
	}
	sort(value.begin()+1,value.end());
	
	value.emplace_back(MAX);
	
	for(int i = 1; i <=n-1; i++) {
		int bestIdx = binarySearch(i+1, value[i]);
		sum = abs(value[i]+value[bestIdx]);
		if(sum < bestSum) {
			bestSum= sum;
			best[0] = value[i], best[1] = value[bestIdx];
		}
	}
	cout<<best[0]<<" "<<best[1]<<'\n';
	
	return 0;
}