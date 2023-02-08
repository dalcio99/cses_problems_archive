#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli num[200000];

lli sol(int i, lli x) { // soluzioni che usano l'i-esimo numero e quelli più piccoli
  lli s = 0;
  if (i < 0) return 0;
  if(num[i] == x) return 1;
  for (int j = i-1; j >= 0; j--) {
      s += sol(j,x-num[i]);
  }
  return s;
}

int main () {
  int n, l;
  lli x, buff, res;
  res = l = 0;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >>  buff;
    if (buff <= x) {
      num[i] = buff;
      l++;
    }
  }
  sort(num, num+l);
  for (int i = 0; i < n; i++) res += sol(i,x);
  cout << res;
  return 0;
}
