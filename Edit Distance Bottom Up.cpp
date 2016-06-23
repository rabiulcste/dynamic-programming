#include <bits//stdc++.h>
using namespace std;

int dp[2010][2010];

int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int main()
{
    int m, n;
    char a[2010], b[2010];

    scanf("%s %s", &a, &b);
    m = strlen(a);
    n = strlen(b);

    for(int i=0; i<m; i++) dp[i][0] = i;
    for(int j=0; j<n; j++) dp[0][j] = j;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    cout << dp[m][n] << endl;
}
