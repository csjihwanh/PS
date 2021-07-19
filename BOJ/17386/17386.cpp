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
	ca.x= a.x-c.x, ca.y= a.y-c.y;
	cb.x= b.x-c.x, cb.y= b.y-c.y;
	return (crossProduct(ca, cb)>0)? 1: -1;
}

bool lineSegIntersect(Vector* p) {
	if(direction(p[1],p[2],p[3])*direction(p[1],p[2],p[4]) < 0 && direction(p[3],p[4],p[1]) * direction(p[3],p[4],p[2]) <0) return true;
	return false;
}

int main( void ) {
	//freopen("/workspace/PS_Git/BOJ/17386/input.txt","r", stdin);
	Vector p[5];
	
	for(int i = 1; i <= 4; i++) scanf("%d %d", &p[i].x, &p[i].y);
	
	printf("%d", lineSegIntersect(p));
	return 0;
	
}
