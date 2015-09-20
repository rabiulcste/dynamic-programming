#include <iostream>

using namespace std;

int search(int a[], int i, int j, int key)
{
    int mid = (i+j)/2;
    if(j < i)
        return j;
    else
        if(a[mid] > key)
            search(a, i, mid-1, key);
        else
            search(a, mid+1, j, key);
}

int LIS_n2(int a[], int size)
{
    int i, j, len[size];
    for(i = 0; i < size; i++) len[i] = 1;

    for(i = 1; i < size; i++) {
        for(j = 0; j < i; j++) {
            if(a[i] > a[j] && len[i] < len[j]+1)
                len[i] = len[j] + 1;
        }
    }
    return len[size-1];
}

int LIS_nlogn(int a[], int size)
{
    int s[size];
    int i;
    int j = -1;
    int p, k;
    for(i = 0; i <= size; i++) s[i] = 0;

    for(i = 0; i <= size; i++) {
        if(j == -1)
            s[++j] = a[i];
        else
        {
            if(s[j]<a[i])
                s[++j] = a[i];
            else {
                p = search(s, 0, j, a[i]);
                s[p+1] = a[i];
            }
        }
    }
    cout<<"O(nlogn) algorithm subsequence: \n";
    for(i = 0; i <= j; i++) cout<<s[i]<<" ";
    cout<<"\n";
    return j+1;
}

int main()
{
    int a[]={10, 22, 9, 33, 21, 50, 41, 60, 80};
	int size = sizeof(a)/sizeof(a[0]);
	cout << "O(n^2) algorithm subsquence length: " << LIS_n2(a, size) << "\n";
	cout << "Subsquence length: " << LIS_nlogn(a, size-1) << "\n";
}
