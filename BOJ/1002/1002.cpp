#include <iostream>
#include <math.h>

using namespace std;

typedef struct circle {
	int x, y, r;
}Circle;

int crossPoint(Circle a, Circle b) {
	double dist = sqrt(pow(a.x-b.x,2) + pow(a.y-b.y, 2));
	if(dist==0 && a.r==b.r) return -1;
	
	if(dist > (a.r+b.r)) return 0;
	if(dist == (a.r+b.r)) return 1;
	if(dist < (a.r+b.r)) {
		if(dist+min(a.r,b.r)>max(a.r,b.r)) return 2;
		if(dist+min(a.r,b.r)==max(a.r,b.r)) return 1;
		if(dist+min(a.r,b.r)<max(a.r,b.r)) return 0;
	}
	return -2;
}

int main ( void ) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	
	freopen("/workspace/PS_Git/BOJ/1002/input.txt","r",stdin);
	Circle c[3];
	int t;
	
	cin>>t;
	for(int i = 1; i <= t; i++) {
		for(int j = 1; j<=2; j++) cin>>c[j].x>>c[j].y>>c[j].r;
		cout<<crossPoint(c[1],c[2])<<'\n';
	}
	return 0;
}