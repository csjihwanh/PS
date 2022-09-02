#include <stdio.h>
#pragma warning(disable:4996)

int score[10500];
int dp[10500][3];
int n;
int Max = 0;
int Max_log = 0;

int max(int a, int b) {

	if (a > b) return a;
	return b;

}

int main(void) {

	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {

		scanf("%d", &score[i]);

	}

	dp[1][1] = score[1];

	for (i = 2; i <= n; i++) {

		Max_log = max(dp[i - 2][1], Max_log);
		Max_log = max(dp[i - 2][2], Max_log);


		dp[i][1] = Max_log + score[i];
		dp[i][2] = dp[i - 1][1] + score[i];

		Max = max(dp[i][1], Max);
		Max = max(dp[i][2], Max);
		

	}

	printf("%d", Max);

	return 0;

}