#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXC 1000
char A[MAXC], B[MAXC];
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
int lenA, lenB;

// Count Longest Common Subsequence length
int calcLCS(int i, int j)
{
    if(A[i] == '\0' || B[j] == '\0') return 0;
    if(visited[i][j]) return dp[i][j];

    int ans = 0;
    if(A[i] == B[j]) ans = 1 + calcLCS(i+1, j+1);
    else
    {
        int val1 = calcLCS(i+1, j);
        int val2 = calcLCS(i, j+1);
        ans = max(val1, val2);
    }
     visited[i][j] = 1;
     dp[i][j] = ans;
     return dp[i][j];
}

// Print the longest common subsequent
string ans;
void printLCS(int i, int j)
{
    if(A[i] == '\0' || B[j] == '\0'){
        cout<<ans<<endl;
        return;
    }

    if(A[i] == B[j]){
        ans += A[i];
        printLCS(i+1, j+1);
    }
    else
    {
       if(dp[i+1][j] > dp[i][j+1]) printLCS(i+1, j);
       else printLCS(i, j+1);
    }
}

// If there are more than one solution, print them too
string sol;
void printAll(int i, int j)
{
    if(A[i] == '\0' || B[j] == '\0'){
        cout<<sol<<endl;
        return;
    }

    if(A[i] == B[j]){
        sol += A[i];
        printAll(i+1, j+1);
        sol.erase(sol.end()-1); // Delete last character
    }
    else
    {
       if(dp[i+1][j] > dp[i][j+1]) printAll(i+1, j);
       else if(dp[i+1][j] < dp[i][j+1]) printAll(i, j+1);
       else
       {
            printAll(i+1, j);
            printAll(i, j+1);
       }
    }
}


int main()
{
    scanf("%s %s", A, B);
    lenA = strlen(A);
    lenB = strlen(B);
    // Print LCS length
    printf("%d\n", calcLCS(0, 0));
    // Print One Solution
    printLCS(0, 0);
    // Print All Solution
    printAll(0, 0);

    return 0;
}
