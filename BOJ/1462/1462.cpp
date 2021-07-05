#include <iostream>

using namespace std;

const int maxN = 500500;

int n, m;
int score[maxN], bonus[maxN];
int dp[maxN][3]; //i번째 문제까지 풀고 j개 coin을 갖고 있을 때의 점수의 max

int main ( void ) {
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &score[i]);
	for(int i= 1; i<=n; i++) scanf("%d", &bonus[i]);
	
	dp[1][0]=-score[1], dp[1][1] = score[1];
	for(int i= 2; i<=n; i++) {
		dp[i][0] = max(max(dp[i-1][0]-score[i], dp[i-1][1]-score[i]),dp[i-1][2]+score[i]+bonus[i]);
		dp[i][1] = dp[i-1][0]+score[i];
		dp[i][2] = dp[i-1][1]+score[i];
	}
	
	cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<endl;
	return 0;
}