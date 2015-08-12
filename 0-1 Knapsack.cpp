#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define i64 long long
#define MAX_N 100
#define MAX_W 1000
using namespace std;

int n;
int dp[MAX_N+1][MAX_W+1];
int weight[MAX_N+1];
int cost[MAX_N+1];
int CAP;

int func(int i, int w)
{
    if(i==n+1) return 0; // সবকিছু নেয়া হয়ে গেছে
    if(dp[i][w]!=-1) return dp[i][w];
        int profit1 = 0, profit2 = 0;
        if(w+weight[i]<=CAP)
            profit1 = cost[i]+func(i+1, w+weight[i]); //যদি i তম জিনিসটা নেয়া যায় তাহলে লাভের পরিমাণ profit1
        profit2= func(i+1, w); //যদি জিনিসটা না নেই তাহলে profit2
     dp[i][w]=max(profit1, profit2); //বেশী লাভ যেটায় হয় সেটাই আমরা নিবো
     return dp[i][w];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &CAP);
    for(int i=1; i<=n; i++){
        scanf("%d %d\n", &weight[i], &cost[i]);
    }

    printf("%d\n", func(1, 0));
}

