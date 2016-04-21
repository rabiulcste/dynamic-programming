#include <bits//stdc++.h>
using namespace std;

long long dp[100000+10], last[200], mod = 1000000007;
char str[100000+10];

int main()
{
    int i, t, n;
    cin >> t;
    while(t--) {
        scanf("%s", str+1);

        memset(dp, 0, sizeof dp);
        memset(last, 0, sizeof last);
        dp[0] = 1;
        n = strlen(str+1);

        for(i = 1; i <= n; i++){
            dp[i] = (dp[i-1]*2) % mod;
            if(last[str[i]]) dp[i] = (dp[i] - dp[last[str[i]] - 1] + mod)%mod;
            last[str[i]] = i;
         }

         cout << dp[n] << endl;
    }
    return 0;
}
