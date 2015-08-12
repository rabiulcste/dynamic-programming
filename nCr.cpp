#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define i64 long long
#define MAX 100
using namespace std;
i64 dp[MAX][MAX];
i64 nCr(int n, int r)
{
    if(r == 1) return n;
    if(r == n) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    else{
        dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
        return dp[n][r];
    }
}
int main()
{
    int n, r;
    cin>>n>>r;
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            dp[i][j] = -1;
    cout<<nCr(n, r)<<endl;
}
