#include <bits//stdc++.h>
using namespace std;

struct Job {
    int start, end, profit;
};

bool comp(Job p1, Job p2){
    return (p1.end < p2.end);
}

int solve(Job arr[], int n)
{
    sort(arr, arr+n, comp);

    int *T = new int[n];
    T[0] = arr[0].profit;

    for(int i=1; i<n; i++) {
        T[i] = max(arr[i].profit, T[i-1]);
        for(int j=i-1; j>=0; j--) {
            if(arr[j].end <= arr[i].start) {
                T[i] = max(T[i], arr[i].profit+T[j]);
                break;
            }
        }
    }

    int maxi = 0;
    for(int i=0; i<n; i++)
        maxi = max(maxi, T[i]);
    return maxi;
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Job Scheduling Result is " << solve(arr, n);
    return 0;
}
