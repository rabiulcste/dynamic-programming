#include <iostream>
#include <vector>
using namespace std;

int CoinChange(int amount, int d[], int size, int s[])
{
    // C[i,j] = C[denomination, amount of change]
    vector<vector<int> > C(size, vector<int>(amount+1));
    for(int i = 0; i < size; i++)
	C[i][0] = 0;
    for(int j = 0; j <= amount; j++) {
	C[0][j] = j;
	s[j] = 0;
    }

    for(int i = 1; i < size; i++) {
	for(int j = 1; j <= amount; j++) {
	    if(j < d[i]) {
		C[i][j] = C[i-1][j];
	    }
	    else {
		C[i][j] = min(C[i-1][j], C[i][j-d[i]] + 1);
		s[j] = i;
	    }
	}
    }
    return C[size-1][amount];
}


int main()
{
    int d[] = {1, 5, 10, 25};
    int amount = 67;
    int size = sizeof(d)/sizeof(d[0]);
    int *s = new int[amount+1];
    int ans = CoinChange(amount, d, size, s);
    cout << "Minimal # of coins = " << ans << endl;
    cout << "coins used: " ;
    int k = amount;
    while(k) {
	cout << d[s[k]] << " ";
	k = k - d[s[k]];
    }
    delete[] s;

    return 0;
}
