#include <bits//stdc++.h>
using namespace std;

int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int editDist(string s1, string s2, int m, int n) {
    if(m == 0) return n;
    if(n == 0) return m;

    if(s1[m-1] == s2[n-1])
        return editDist(s1, s2, m-1, n-1);

    return 1 + min3 ( editDist(s1, s2, m, n-1), // insert
                     editDist(s1, s2, m-1, n), // remove
                     editDist(s1, s2, m-1, n-1) // replace
                   );
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << editDist(s1, s2, s1.size(), s2.size()) <<endl;;
}
