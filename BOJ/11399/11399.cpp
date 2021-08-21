#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	int n, temp, answer=0;
	vector<int> arr;
	
	cin>>n;
	for(int i = 0; i < n;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	
	for(int i = 0; i < n;i++) {
		answer+= arr[i] * (n-i);
	}
	cout<<answer;
	return 0;
}