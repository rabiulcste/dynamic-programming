#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

int dp[81][81];
set<string> sequences;
map<string,bool> processed[81][81];

void backtrack(string s1, string s2, int i, int j, string word)
{
    if(processed[i][j].find(word)!=processed[i][j].end())
        return;
    if(i==0 || j==0) {
        sequences.insert(word);
        //printf("%s\n",word.c_str());
    }
    else if(s1[i-1] == s2[j-1]) {
        word = s1[i-1] + word;
        backtrack(s1, s2, i-1, j-1, word);
    }
    else if(dp[i][j-1] > dp[i-1][j]) {
        backtrack(s1, s2, i, j-1, word);
    }
    else if(dp[i-1][j] > dp[i][j-1]) {
        backtrack(s1, s2, i-1, j, word);
    }
    else {
        backtrack(s1, s2, i, j-1, word);
        backtrack(s1, s2, i-1, j, word);
    }
    processed[i][j][word] = true;
}

void lcs(string a, string b)
{
    int n = a.length();
    int m = b.length();

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=m; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
        if(a[i-1] == b[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    //printf("%d\n",table[l1][l2]);
    backtrack(a, b, n, m, "");
}

int main()
{
    int t;
    scanf("%d", &t);
    char c_s1[81], c_s2[81];
    string s1, s2;
    while(t--)
    {
        sequences.clear();
        scanf("%s %s", c_s1, c_s2);

        s1 = c_s1; s2 = c_s2;
        lcs(s1, s2);
        set<string>::iterator it;
        for(it=sequences.begin(); it!=sequences.end(); it++)
        printf("%s\n",it->c_str());
        printf("\n");
    }
    return 0;
}
