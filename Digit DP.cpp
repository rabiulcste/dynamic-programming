#include <bits//stdc++.h>
using namespace std;
 
#define ll long long
#define MX 50
#define pb push_back
 
int dig[MX];
ll dp[MX][MX];
 
ll dfs(int pos, int cnt, int ise, int first)
{
    if(!pos)
    {
        if(first) return (ll)1;
        return (ll)cnt;
    }
    if(!ise && !first && dp[pos][cnt] != -1)
        return dp[pos][cnt];
 
    ll re = 0;
 
    int n = ise?dig[pos]:9;
    for(int i = 0; i <= n; i++) {
        if(first)
            re += dfs(pos-1, 0, ise && i == n, first && i == 0);
        else {
            if(i == 0)
                re += dfs(pos-1, cnt + 1, ise && i == n, first && i == 0);
            else re += dfs(pos-1, cnt, ise && i == n, first && i == 0);
        }
    }
 
    if(!first && !ise)
        dp[pos][cnt] = re;
    return re;
}
 
ll sol(ll n)
{
    int len = 0;
    memset(dp, -1, sizeof dp);
    if(n == 0)
        dig[++len] = 0;
    while(n) {
        dig[++len] = n % 10;
        n /= 10;
    }
 
    return dfs(len, 0, 1, 1);
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   
    int test;
    scanf(" %d", &test);
   
    for(int ks = 0; ks < test; ks++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll ans = sol(b) - sol(a-1);
        printf("Case %d: %lld\n", ks + 1, ans);
    }
    return 0;
}
