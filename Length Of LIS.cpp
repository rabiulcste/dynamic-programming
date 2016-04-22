#include <bits//stdc++.h>
using namespace std;

int n; // the number of items in the sequence
int Sequence[32]; // the sequence of integers
int L[32]; // L[] for finding LIS

void takeInput() {
    scanf("%d", &n); // how many numbers in the sequence ?
    // take the sequence
    for(int i = 0; i < n; i++)
        scanf("%d", &Sequence[i]);
}

int LIS()
{
    int i, j;

    // initialize L[] with 1
    for(i = 0; i < n; i++)
        L[i] = 1;

    // start from the left most item and iterate them
    for(i = 0; i < n; i++) {
        // for the ith item find all items that are in right
        for(j = i + i; j < n; j++) {
            if(Sequence[j] > Sequence[i]) {
                // the item is greater than ith item
                // So, L[j] = L[i] + 1, since jth item can be added after ith
                // item. If L[j] is already greater than or equal to L[i] + 1 then ignore it
                if(L[j] < L[i] + 1)
                    L[j] = L[i] + 1;
            }
        }
    }
    // now find the item whose L[] is maximum
    int maxLength = 0;
    for(i = 0; i < n; i++) {
        if(maxLength < L[i])
            maxLength = L[i];
    }

    // return the result
    return maxLength;
}

int main()
{
    takeInput();
    int result = LIS();
    printf("The LIS length is %d\n", result);
    return 0;
}
