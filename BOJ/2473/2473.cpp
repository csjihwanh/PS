#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 5555555555

using namespace std;

typedef long long int ll;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/2473/input.txt","r",stdin);
	
	int n, left, right;
	ll best[3], bestSum=MAX, sum, temp;
	vector<ll> value;
	
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>temp;
		value.emplace_back(temp);
	}
	sort(value.begin(),value.end());
	
	for(int i = 0 ; i<n-2; i++) {
		left = i+1, right = n-1;
		while(left<right) {
			sum = value[i]+value[left]+value[right];
			
			if(abs(sum)< abs(bestSum) ) {
				bestSum=sum;
				best[0]=value[i],best[1]=value[left],best[2]=value[right];
			}
			if(sum>=0) right--;
			else if(sum<0) left++;
		}
	}
	for(int i = 0; i<3; i++) cout<<best[i]<<" ";
	
	return 0;
}