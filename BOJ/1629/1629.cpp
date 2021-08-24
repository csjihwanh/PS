#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long int ll;
ll n, m, c;

ll mod(ll a) {
	return a%c;
}

ll power(ll a, ll b) {
	if(b==1) return a;
	
	ll value = power(a,b/2);
	if(b%2 != 0) {
		return mod(mod(value*value)*a);
	}
	return mod(value*value);
}

int main(void) {
	cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
	//freopen("/workspace/PS_Git/BOJ/input.txt","r",stdin);
	
	cin>>n>>m>>c;
	cout<<mod(power(n,m));
	return 0;
}