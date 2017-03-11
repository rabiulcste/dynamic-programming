#include <bits//stdc++.h>
using namespace std;
 
#define ll long long
#define MX 1005
#define pb push_back
 
char tmp[MX];
bool pal[MX][MX];
int cut[MX], n;
string s;
int palpart(){
    n = s.size();
    for(int l = 1; l <= n; l++) {
        // starting positions
        for(int i = 0; i + l <= n; i++){
            int j = i + l - 1; // ending positions
            pal[i][j] = (s[i] == s[j]) && (pal[i+1][j-1] || i+1 >= j-1);
        }
    }
    for(int i=0; i<n; i++) {
        if(pal[0][i] == 1)
            cut[i] = 0;
        else {
            for(int j=0; j<i; j++) {
                if(pal[j+1][i]){
                    cut[i] = min(cut[i], 1+cut[j]);
                }
            }
        }
    }
    // returning minimum cut
    return cut[n-1];
}

void allsol()
{
    for(int l = 1; l <= n; l++) {
        // starting positions
        for(int i = 0; i + l <= n; i++){
            int j = i + l - 1; // ending positions
            if(pal[i][j]) {
                cout << s.substr(i, j+1-i) << "\n";
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
   
    int test;
    scanf(" %d", &test);
   
    for(int ks = 0; ks < test; ks++)
    {
        scanf("%s", tmp);
        s = tmp;
        memset(pal, false, sizeof pal);
        memset(cut, 0x3f3f3f3f, sizeof cut);
        int ans = palpart();
        printf("Case %d: %d\n", ks+1, ans);
        //allsol();
    }
    return 0;
}
