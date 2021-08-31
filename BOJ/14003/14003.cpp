#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1e6;
const int MIN_NUM = -1*(1e9+7);
const int NEXT = -1;
vector<int> lis, arr(MAX_N+500), track(MAX_N+500), lisIdx, answer;
int recent;

int binarySearch(int value) {
	int left= 0, right = lis.size()-1, mid=(left+right)/2;
	
	while(left<=right) {
		mid = (left+right)/2;
		if((lis[mid-1]<value && value< lis[mid])||lis[mid]==value) return mid;
		else if(lis[mid] < value) left= mid+1;
		else right=mid-1;
	}
	return NEXT;
}

void LIS(int bound) {
	lis.clear();
	lis.push_back(MIN_NUM);
	lisIdx.push_back(0);
	track.push_back(0);
	
	for(int i = 1; i <= bound; i++) {
		int index = binarySearch(arr[i]);
		if(index==NEXT) {
			lis.push_back(arr[i]);
			track[i]=lisIdx.back();
			lisIdx.push_back(i);
		}
		else if(arr[i] < lis[index]) {
			lis[index] = min(lis[index],arr[i]);
			lisIdx[index] = i;
			track[i]=(lisIdx[index-1]);
		}
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>arr[i];
	
	LIS(n);
	cout<<lis.size()-1<<'\n';
	
	int cur = lisIdx.back();
	while(cur != 0) {
		answer.push_back(arr[cur]);
		cur = track[cur];
	}
	for(int i = answer.size()-1; i>=0; i--) {
		cout<<answer[i]<<" ";
	}
	
	return 0;
}