#include <bits//stdc++.h>

using namespace std;


int solve1(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;

    for(int i = 1; i < n; i++) {
        int temp = incl;
        incl = max(excl+arr[i], incl);
        excl = temp;
    }
    return incl;
}

int solve2(int arr[], int indx)
{
    if(indx == 0)
        return arr[0];
    else if(indx == 1)
        return max(arr[0], arr[1]);
    return max(solve2(arr, indx-2) + arr[indx], solve2(arr, indx-1));
}

int main()
{
    int n, arr[100];
    cin >> n;
    for(int i=0; i<n; i++) cin >>arr[i];
    cout << solve2(arr, n-1) << endl;
    return 0;
}
