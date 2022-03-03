#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>> p(25);
vector<bool> chk(25);
double minDist = 9876543219;

double dist(pair<int,int> a, pair<int,int> b) {
	return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

void combinationDist(int pair, double sumDist,int n) {
	if(pair==n) {
		minDist = min(minDist , sumDist);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(chk[i]==false) {
			chk[i]=true;
			for(int j = i+1; j <= n; j++) {
				if(chk[j]==false) {
					chk[j]=true;
					cout<<"comb "<<pair<<" "<<i<<" "<<j<<endl;
					combinationDist(pair+2, sumDist+ dist(p[i],p[j]),n);
					chk[j]=false;
				}
			}
			chk[i]=false;
		}
	}
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	cout<<fixed;
	cout.precision(12);
	
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i =1; i<= n; i++) cin>>p[i].first>>p[i].second;
		
		double answer = 0;
		minDist = 9876543219;
		
		combinationDist(0,0,n);
		answer = minDist;
		cout<<answer<<'\n';
	}
	return 0;
}