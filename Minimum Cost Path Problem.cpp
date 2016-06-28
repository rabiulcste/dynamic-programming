#include <bits//stdc++.h>
using namespace std;
#define MAX 1000

int c[MAX][MAX], m, n;

int min(int a, int b, int c)
{
    if(a < b)
        return (a < c)? a : c;
    else
        return (b < c)? b : c;
}

int minCost()
{
    int i, j;
    int dp[m+1][n+1];

    dp[0][0] = c[0][0];

    // First column initialization
    for(i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + c[i][0];

    // First row initialization
    for(i = 1; i < n; i++)
        dp[0][i] = dp[0][i-1] + c[0][i];

    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
            dp[i][j] = c[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
    return dp[m-1][n-1];
}

int main()
{
    int i, j;

    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> c[i][j];

    int res = minCost();
    cout << res << endl;

    return 0;
}
