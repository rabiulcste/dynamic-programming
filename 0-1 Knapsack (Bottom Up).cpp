#include <bits//stdc++.h>
#define MAX_N 100+1
#define MAX_W 500+1
using namespace std;

int dp[MAX_N][MAX_W];
int wt[MAX_N+1];
int val[MAX_N+1];

int bottom_up(int n, int W){
        for(int i=0; i <= n; i++){
            for(int j=0; j <= W; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(j - wt[i-1] >= 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    return dp[n][W];
}

int main()
{
    int n, CAP;
    while(scanf("%d %d", &CAP, &n) == 2) {
        if(n == 0 && CAP == 0) break;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%d %d", &wt[i], &val[i]);
        int ans, re;
        ans = bottom_up(n, CAP);
        for(int i=0; i<=CAP; i++) {
            if(dp[n][i] == ans) {
                re = i;
                break;
            }
        }
        // total val and weight
        printf("%d %d\n", re, ans);

    }
    return 0;
}
