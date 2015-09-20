#include <bits//stdc++.h>
#define MAXN 1000
#define MAXLOGN 10
using namespace std;
int M[MAXN][MAXLOGN];

void Compute_ST(int A[MAXN], int N)
{
    int i, j;
    // initialize M for the intervals with length 1
    for (i = 0; i < N; i++)
        M[i][0] = i;
    // compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int RMQ(int A[], int s, int e)
{
    int k = (int)log(e-s+1); // length of query range is e-s+1

    if(A[M[s][k]] <= A[M[e-(1<<k)+1][k]])
        return A[M[s][k]];
    return A[M[e-(1<<k)+1][k]];
}

int main(){
    int A[10] = {3, 1, 2, -1, 5, 4, 6, 0, 9, 8};
    // scanf("%d", &n);
    // for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    Compute_ST(A, 10);
    int s, e;
    scanf("%d %d" ,&s, &e);
    printf("%d\n", RMQ(A, s, e));

    return 0;
}
