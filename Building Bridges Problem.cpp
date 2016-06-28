#include <bits//stdc++.h>
using namespace std;
#define MAX 1000

int lis(int arr[], int n)
{
    int dp[n];
    for(int i=0; i<n; i++) dp[i] = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i]>=arr[j] && dp[i] < dp[j]+ 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int ans = dp[0];

    for(int i=1; i<n; i++) {
        if(dp[i] > ans) ans = dp[i];
    }

    return ans;
}

int main()
{
    int n, a[MAX], b[MAX];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    vector<pair<int, int> >v;

    for(int i=0; i<n; i++)
        v.push_back(make_pair(b[i], a[i]));
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
        a[i] = v[i].second;

    int res =  lis(a, n);
    printf("%d\n", res);

    return 0;
}
