#include <bits/stdc++.h>
#define lli long long int
using namespace std;

// dp[x][n] = max numero di pag spendendo x e comprando libri fino all'(n+1)-simo
// dp[x][0] = s_0 if x>= h_0  / zero otherwise
// dp[x][i] = max(dp[x][i-1],dp[x-h_i][i-1]+s_i)
// Note: below I inverted the two components cause having the bigger on the right speeds up the code!!!

int dp[1001][100001];

int main() {    
    int n, x, i, j;
    cin >> n >> x;
    int pages[n+1];
    int prices[n+1];
    for (i = 0; i < n; i++) {
        cin >> prices[i];
    }
     for (i = 0; i < n; i++) {
        cin >> pages[i];
    }
    for (i = prices[0]; i <= x; i++) dp[0][i] = pages[0];
    for (j = 1; j < n; j++) {
        for (i = 1; i <= x; i++) {
            if (i >= prices[j]) dp[j][i] = max(dp[j-1][i],dp[j-1][i-prices[j]]+pages[j]);
            else dp[j][i] = dp[j-1][i];
        }
    }
    cout << dp[n-1][x];
    return 0;
}