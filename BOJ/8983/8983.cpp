#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef struct {
	int x, y;
}Point;

vector<int> shoot = {0};

int nearestShoot(int x, int m) {
	int left=1, right=m, mid=(left+right)/2;
	while(true) {
		if(mid>1 && abs(shoot[mid-1]-x)<abs(shoot[mid]-x)) {
			right = mid-1;
		}
		else if(mid<m && abs(shoot[mid+1]-x) < abs(shoot[mid]-x)) left= mid+1;
		else break;
		mid=(left+right)/2;
	}
	return mid;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/8983/input.txt","r",stdin);
	int m, n, l, sum=0;
	int temp1, temp2;
	ll dist;
	vector<Point> animal = {{0,0}};
	
	cin>>m>>n>>l;
	for(int i = 1; i <=m; i++) {
		cin>>temp1;
		shoot.push_back(temp1);
	}
	sort(shoot.begin()+1, shoot.end());
	shoot.push_back(0); //overflow 방지용
	
	for(int i = 1; i <=n;i++) {
		cin>>temp1>>temp2;
		animal.push_back({temp1,temp2});
	}
	
	for(int i = 1; i <= n; i++) {
		dist = abs(animal[i].x - shoot[nearestShoot(animal[i].x,m)]) + animal[i].y;
		if(dist <= l) sum++;
	}
	cout<<sum<<'\n';
	
	return 0;
}