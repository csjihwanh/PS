#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 55;

int n ;
double h[55];

int countForward(int stdIdx, double grad, int nowIdx) {
	
	if(nowIdx > n) return 0;
	
	if(h[nowIdx] > h[stdIdx] + grad*(nowIdx-stdIdx)) {
		//printf("you can see %d from %d\n", nowIdx, stdIdx);
		return countForward(stdIdx, (h[nowIdx]-h[stdIdx])/((double)(nowIdx-stdIdx)), nowIdx+1) +1;
	}
	else return countForward(stdIdx, grad, nowIdx+1);
	
}

int countBackward(int stdIdx, double grad, int nowIdx) {
	if(nowIdx < 1) return 0;
	
	if(h[nowIdx] > h[stdIdx] + grad*(stdIdx-nowIdx)) {
		//printf("you can see %d from %d\n", nowIdx, stdIdx);
		return countBackward(stdIdx, (h[nowIdx]-h[stdIdx])/((double)(stdIdx-nowIdx)), nowIdx-1) +1;
	}
	else return countBackward(stdIdx, grad, nowIdx-1);
	
}

int main ( void ) {
	freopen("/workspace/PS_Git/BOJ/1027/input.txt", "r", stdin);
	
	int maxVal = 0, sum;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lf", &h[i]);
	
	for(int i = 1; i <= n; i++) {
		sum = countForward(i, (h[i+1]-h[i]) -1, i+1) + 		countBackward(i, (h[i-1]-h[i])-1, i-1);
		//printf("%d's sum = %d\n", i, sum);
		maxVal = max(maxVal, sum);
	}
	printf("%d", maxVal);
}