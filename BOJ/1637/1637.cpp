#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 20050;
int n;
long long int a[maxN], c[maxN], b[maxN];

bool isOdd(long long int x) {
	if(x%2==1) return true;
	return false;
}

long long int floor(int i, long long int lim) {
	return ((lim-a[i])/b[i])*b[i]+a[i];
}

long long int countRange(long long int left, long long int right) {
	long long cnt = 0;
	long long int lVal, rVal;
	long long int lLim, rLim;
	for(int i = 1; i <= n; i++) {
		                     
		lLim = max(left, a[i]); rLim = min(right,floor(i,c[i]));
		lVal = floor(i, lLim);
		if(lVal<left) lVal+=b[i];
		rVal = floor(i,rLim);
		
		if(rVal >= lVal && rLim >= lLim) cnt+=(rVal-lVal)/b[i]+1;
		
	}
	return cnt;
}

int main ( void ) {
	
	long long int left=2147483648, right=0, mid;
	
	scanf("%d", &n);
	for(int i=1; i <=n; i++) {
		scanf("%lld %lld %lld", &a[i], &c[i], &b[i]);
		left=min(left,a[i]);
		right=max(right,c[i]);
	}
	
	if(!isOdd(countRange(left,right))) {
		printf("NOTHING\n");
		return 0;
	}
	mid=(left+right)/2;
	
	while(left!=right) {
		
		if(isOdd(countRange(left,mid))) {
			right=mid;
			mid=(left+right)/2;
		}
		else {
			left=mid+1;
			mid=(left+right)/2;
		}
	}
	
	cout<<left<<" "<<countRange(left,right)<<endl;
	
}