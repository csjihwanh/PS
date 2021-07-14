#include <iostream>
#include <algorithm>
#include <vector>
#define NINF -98765432198

using namespace std;

typedef long long int ll;
const int maxN = 500500;
int n, m;
int score[maxN], bonus[maxN];
ll scoreAcc[maxN], zeroScore[maxN];

ll calcMaxScore() {
	ll bonusResult = 0;
	ll maxScore= 0;
	int maxIndex = 0;
	for(int i = 1; i<= n; i++) {
		if(i<m) bonusResult = NINF;
		else bonusResult = zeroScore[i-m]+scoreAcc[i]-scoreAcc[i-m]+bonus[i];
		zeroScore[i] = max(bonusResult, maxScore-score[i]);
		if(bonusResult>=maxScore+score[i]) {
			maxScore = bonusResult;
			maxIndex = 0;
		}
		else {
			maxScore += score[i];
			maxIndex++;
		}
	}
	return max(zeroScore[n],maxScore);
}

int main(void) {
	freopen("/workspace/PS_Git/BOJ/1462/input.txt", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);
		scoreAcc[i]=scoreAcc[i-1]+(ll)score[i];
	}
	for(int i = 1; i <= n; i++) scanf("%d", &bonus[i]);
	
	cout<<calcMaxScore()<<endl;
}