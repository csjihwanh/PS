#include <iostream>
#include <vector>

using namespace std;

const int max_n = 10050;

int dp[max_n][2], wine[max_n];
int n, cur_max=0, val_max = 0;

int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i = 1; i <= n;i++) {
        cin>>wine[i];
    }
    
    for(int i = 1; i<=n;i++) {
        if(i>=3) cur_max = max(cur_max,max(dp[i-2][0], dp[i-2][1]));
        dp[i][0] = cur_max + wine[i];
        if(i>=2) dp[i][1] = dp[i-1][0]+wine[i];
        val_max = max(val_max, max(dp[i][0], dp[i][1]));
    }

    cout<<val_max<<'\n';
    return 0;
}