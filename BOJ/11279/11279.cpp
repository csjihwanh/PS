#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

struct comp {
	bool operator()(int a, int b) {	
		if(abs(a)!=abs(b))return abs(a)>=abs(b);
		else return a>b;
	}
};
int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	priority_queue<int,vector<int>,comp> heap;
	int n, opt, temp;
	
	cin>>n;
	while(n--) {
		cin>>opt;
		if(opt==0) {
			if(heap.empty()) {
				cout<<0<<'\n';
				continue;
			}
			temp = heap.top();
			heap.pop();
			cout<<temp<<'\n';
		}
		else {
			heap.push(opt);
		}
	}
	
	return 0;
}