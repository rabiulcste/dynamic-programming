#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#define MX 210
using namespace std;

int dp[MX][MX], s[MX][MX];
vector<string> v1, v2;
int m, n;
int flag;

void lcsprint(int i, int j)
{
    if(i == 0 || j == 0)return;
    if(s[i][j] == 1)
    {
        lcsprint(i-1, j-1);
        if(flag == 0) cout << v1[i-1];
        else cout <<" " << v1[i-1];
        flag = 1;
    }
    else if(s[i][j] == 2)
    {
        lcsprint(i-1, j);
    }
    else lcsprint(i, j-1);
}


void LCSLength(){
	int i, j;

	for (i = 0; i <= m; ++i) dp[i][0] = 0;

	for (j = 0; j <= n; ++j) dp[0][j] = 0;

	for (i = 1; i <= m; ++i){
		for (j = 1; j <= n; ++j){
			if (v1[i-1] == v2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    s[i][j] = 1;
			}
			else if (dp[i-1][j] >= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    s[i][j] = 2;
			}
			else{
                    dp[i][j] = dp[i][j-1];
                    s[i][j] = 3;
			}
		}
	}
	lcsprint(m, n);
	return;
}


int main()
{
    string s1, s2;

    while(getline(cin, s1))
    {
        // strcpy(a[length1++],temp);
        v1.clear();
        v2.clear();
        istringstream is(s1);
        while(is>>s2) v1.push_back(s2);
        while(getline(cin, s1)) {
                if(s1 == "#") break;
                istringstream is(s1);
                while(is>>s2) v1.push_back(s2);
        }
        while(getline(cin, s1)) {
            if(s1 == "#") break;
            istringstream is(s1);
            while(is>>s2) v2.push_back(s2);
        }
        flag = 0;
        m = v1.size();
        n = v2.size();
        LCSLength();
        printf("\n");
    }
    return 0;
}
