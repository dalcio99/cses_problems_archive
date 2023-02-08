#include <bits/stdc++.h>
#define lli long long int
using namespace std;



void sortrows(vector<vector<int>>& matrix, int col) {
    sort(matrix.begin(),
            matrix.end(),
            [col](const vector<int>& lhs, const vector<int>& rhs) {
              return lhs[col] < rhs[col];
            });
}

int main() {
  int n, start, end, end2, length, res;
  bool found;
  cin >> n;
  vector<vector<int>> films(n);
  for (int i = 0; i < n; i++) {
    cin >> start >> end;
    length = end - start;
    films[i].push_back(i);
    films[i].push_back(start);
    films[i].push_back(end);
    films[i].push_back(length);
  }
  sortrows(films, 2);
  res = 1;
  end = films[0][2];
  //for (int i = 0; i < n; i++) cout << films[i][0] << "\n";
  for (int i = 0; i < n; i++) {
    if(!found && i < n && films[i][2] >= end) {
      while(!found && i < n && films[i][2] >= end) {
        if (films[i][2] > end && films[i][1]>= end) {
          found = true;
          res++;
          end = films[i][2];
        }
        i++;
      }
      i--;
      found = false;
      }
    }
  cout << res;
  return 0;
}
