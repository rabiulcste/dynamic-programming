#include <bits/stdc++.h>
using namespace std;

vector<char> vc;
char s1[1005] , s2[1005];
int dp[105][105];

void backtrace(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    else if(s1[i-1] == s2[j-1]) {
            backtrace(i-1, j-1);
            vc.push_back(s1[i-1]);
    }
    else {
        if(dp[i][j-1] > dp[i-1][j])
            backtrace(i, j-1);
        else
            backtrace(i-1, j);
    }
}

/// finding lcs of s1 and s2 whose lengths are len1 and len2 respectively
/// LCS is stored in the vector "vc"
void lcs()
{
    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=n; ++i) dp[i][0] = 0;   //base cases
    for(int i=0; i<=m; ++i) dp[0][i] = 0;	 //base cases

    // filling up dp[][] table for LCS
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

int main()
{
    while(scanf("%s %s", s1, s2) == 2)
    {
        vc.clear();
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        lcs();
        backtrace(len1, len2); //getting LCS by backtracing

        int l1 = 0, l2 = 0;

        /// then printing SCS of s1 and s2 with the help of LCS of s1 and s2
        for(int i=0; i<vc.size(); ++i) {
            while(l1 < len1 && s1[l1] != vc[i]) {
                cout << s1[l1];
                ++l1;
            }

            while(l2 < len2 && s2[l2] != vc[i]) {
                cout << s2[l2];
                ++l2;
            }

            cout<<vc[i];
            ++l2, ++l1;
        }

        while(l1<len1)
            cout<<s1[l1++];
        while(l2<len2)
            cout<<s2[l2++];
        cout<<endl;
	}
	return 0;
}
