#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<double,double> pid;
vector<pid> dot;
double ans = 0;

double triangle(pid a, pid b, pid c) {
	pid dirA, dirB;
	dirA = make_pair(b.first-a.first, b.second-a.second);
	dirB = make_pair(c.first-a.first, c.second-a.second);
	cout<<(dirA.first*dirB.second - dirA.second*dirB.first)/2<<endl;
	return (dirA.first*dirB.second - dirA.second*dirB.first)/2;
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	cout<<fixed;
	cout.precision(1);
	int n;
	pid temp;
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>temp.first>>temp.second;
		dot.push_back(temp);
	}
	
	for(int i = 2; i < n; i++) {
		ans += triangle(dot[0],dot[i-1],dot[i]);
	}
	cout<<abs(ans);
	return 0;
}