#include <bits//stdc++.h>
using namespace std;
#define INF 9999
int CoinChange(int amount, int d[], int size)
{
    if(amount <= 0) return 0;
    int min_coins = INF;

    for(int i = 0; i < size; i++) {
	if(d[i] <= amount)
	    min_coins = min(min_coins, CoinChange(amount-d[i], d, size) + 1);
    }
    return min_coins;
}

int main()
{
    int d[] = {5, 6, 10, 25};
    int amount = 30;
    int size = sizeof(d)/sizeof(d[0]);
    int ans = CoinChange(amount, d, size);
    if(ans == 9999) cout<<"Impossible"<<endl;
    else
    cout << "Minimum number of coins = " << ans << endl;

    return 0;
}
