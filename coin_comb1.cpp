#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int mod = (int) 1e9 + 7;
lli ways[1000001];

int main() {
  int n,x, i, j;
  cin >> n >> x;
  int coins[n];
  for (i = 0; i < n; i++) {
    cin >> coins[i];
    ways[coins[i]] = 1;
  }
  //sort(coins, coins+n);
  for (i = 1; i <= x; i++) {
    for(j = 0; j < n; j++) {
      if(coins[j] < i) {
        ways[i] += ways[i-coins[j]];
        ways[i] %= mod;
      }
  }
  }
  cout << ways[x];
  return 0;
}
