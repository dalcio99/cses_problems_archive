#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli comb[1000001];
lli schifo = 1e9+7;

int main(){
  int n;
  comb[1] = 1;
  comb[2] = 2;
  comb[3] = 4;
  comb[4] = 8;
  comb[5] = 16;
  comb[6] = 32;
  for(int i = 7; i <= 1000000; i++) {
    for (int j = 1; j <= 6; j++) {
      comb[i] += comb[i-j];
      comb[i] = comb[i] % schifo;
    }
  }
  cin >> n;
  cout << comb[n];
  return 0;
}
