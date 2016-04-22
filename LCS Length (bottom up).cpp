#include <bits//stdc++.h>
using namespace std;

#define MX 500
int dp[MX][MX];
char a[MX], b[MX];

int LCSLength(int m , int n){
	int i, j;

	for (i = 0; i <= m; ++i)
		dp[i][0] = 0;

	for (j = 0; j <= n; ++j)
		dp[0][j] = 0;

	for (i = 1; i <= m; ++i){
		for (j = 1; j <= n; ++j){
			if (a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else if (dp[i-1][j] >= dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	return dp[m][n];
}

int main()
{
    int m, n;
    while(gets(a))
    {
        // loop breaks when input is '#'
        if(strcmp(a, "#")==0) break;
        gets(b);
        m = strlen(a);
        n = strlen(b);
        LCSLength(m, n);
        printf("%d\n", dp[m][n]);
    }
    return 0;
}
