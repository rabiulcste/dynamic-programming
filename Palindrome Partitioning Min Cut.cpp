#include <bits//stdc++.h>
using namespace std;
 
#define ll long long
#define MX 1005
#define pb push_back
 
char s[MX];
bool pal[MX][MX];
int cut[MX][MX];

int palpart(){
    int n = strlen(s);
    for(int l = 1; l <= n; l++) {
        // starting positions
        for(int i = 0; i + l <= n; i++){
            int j = i + l - 1; // ending positions
            pal[i][j] = (s[i] == s[j]) && (pal[i+1][j-1] || i+1 >= j-1);

            if(pal[i][j] == 1)
                cut[i][j] = 0;
            else {
                for(int k = i; k <= j-1; k++)
                    cut[i][j] = min(cut[i][j], 1+cut[i][k]+cut[k+1][j]);
            }
        }
    }
    // returning minimum cut
    return cut[0][n-1];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   
    int test;
    scanf(" %d", &test);
   
    for(int ks = 0; ks < test; ks++)
    {
        scanf("%s", s);
        memset(pal, false, sizeof pal);
        memset(cut, 0x3f3f3f3f, sizeof cut);
        int ans = palpart();
        printf("Case %d: %d\n", ks+1, ans+1);
    }
    return 0;
}
