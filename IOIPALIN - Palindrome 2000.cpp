#include <bits//stdc++.h>

using namespace std;

#define MAX 5000

char A[MAX+10], B[MAX+10];
int N, dp[2][MAX+10];

int solve()
{
    int state = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(A[i-1] == B[j-1]) dp[state][j] = dp[state^1][j-1] + 1;
            else dp[state][j] = max(dp[state^1][j], dp[state][j-1]);
        }
        state^=1;
    }
    return N - dp[state^1][N];
}

int main()
{
    scanf("%d %s", &N, &A);
    strcpy(B, A);
    reverse(B, B+N);
    printf("%d\n", solve());
    return 0;
}
