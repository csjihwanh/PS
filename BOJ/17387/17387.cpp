#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int x, y;
}Vector;

typedef long long int ll;

ll crossProduct(Vector a, Vector b) {
	return (((ll)a.x*b.y)-((ll)a.y*b.x));
}

int direction(Vector a, Vector b, Vector c) {
	Vector ca, cb;
	ll value;
	ca.x= a.x-c.x, ca.y= a.y-c.y;
	cb.x= b.x-c.x, cb.y= b.y-c.y;
	value = crossProduct(ca, cb);
	return (value >0)? 1 : (value<0? -1 : 0);
}

bool onSegment(Vector a, Vector b, Vector c) {
	if(c.x >= min(a.x, b.x) && c.x <= max(a.x,b.x) && c.y >= min(a.y,b.y) && c.y <= max(a.y,b.y)) return true;
	return false;
}

bool segmentIntersect(Vector* p) {
	int d1, d2, d3, d4;
	d1 = direction(p[3],p[4],p[1]);
	d2 = direction(p[3],p[4],p[2]);
	d3 = direction(p[1],p[2],p[3]);
	d4 = direction(p[1],p[2],p[4]);
	if(d1*d2<0 && d3*d4<0) return true;
	else if(d1==0 && onSegment(p[3],p[4],p[1])) return true;
	else if(d2==0 && onSegment(p[3],p[4],p[2])) return true;
	else if(d3==0 && onSegment(p[1],p[2],p[3])) return true;
	else if(d4==0 && onSegment(p[1],p[2],p[4])) return true;
	return false;
}

int main( void ) {
	//freopen("/workspace/PS_Git/BOJ/17386/input.txt","r", stdin);
	Vector p[5];
	
	for(int i = 1; i <= 4; i++) scanf("%d %d", &p[i].x, &p[i].y);
	
	printf("%d", segmentIntersect(p));
	return 0;
	
}
