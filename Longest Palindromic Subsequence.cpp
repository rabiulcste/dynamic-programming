#include <bits//stdc++.h>
using namespace std;

int dp[1024][1024];

int main()
{
    int T;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin >> T; cin.ignore();

    while(T--) {
        string s;
        getline(cin, s);

        if(s == ""){
            cout << "0" << endl;
            continue;
        }

        int len = s.size();

        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
        }

        for(int l = 2; l <= len; l++){
            for(int i = 0; i+l <= len; i++) {
                int j = i+l-1;

                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        cout << dp[0][len-1] << endl;
    }
    return 0;
}
