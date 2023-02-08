#include <bits/stdc++.h>
#define lli long long int
#define piii pair<int,pair<int,int>>

using namespace std;

multiset <tuple<int,int,int>> ans;
vector <tuple<int,int,int>> pairs;
int order[200001];

int main () {
  int i, n, a, d, rooms;
  cin >> n;
  priority_queue<piii,vector<piii>, greater<piii>> pq;
  for (int i = 1; i <= n; i++ ) {
      cin >> a >> d;
      pq.push(make_pair(a,make_pair(-1, i)));
      pq.push(make_pair(d,make_pair(1, i)));

      //pairs.push_back(make_tuple(d,a,i)); // (departour, arrival, customer id)
  }

  int ms=0;
  int cp=0;

  int p=-1;
  stack<int> freees;
  vector<int> ris(n+5);

  while(!pq.empty()){
    piii t=pq.top();
    pq.pop();
    if(t.second.first==-1){

      if(freees.empty()){
          ms++;
          freees.push(ms);
      }
      ris[t.second.second]=freees.top();
      freees.pop();
    }else{
      freees.push(ris[t.second.second]);
    }

    cp-=t.second.first;


  }

  cout<<ms<<"\n";


  for(i = 1 ; i <= n; i++) cout << ris[i] << " ";
/*
  sort(pairs.begin(), pairs.end());
  rooms = 1;
  ans.insert(pairs[0]);
  int j = 1; // room number
  order[get<2>(pairs[0])] = j;
  //cout << order[1] << "\n";
  j ++;
  for (int i = 1; i < n; i++) {
      auto smallest = ans.begin();
      if(get<1>(pairs[i]) > get<0>(*smallest) ){
          order[get<2>(pairs[i])] = order[get<2>(*smallest)];
          ans.erase(smallest);
          ans.insert(pairs[i]);
      }
      else {
        ans.insert(pairs[i]);
        order[get<2>(pairs[i])] = j;
        j++;
        rooms++;
      }
  }
  cout << rooms << "\n";
  for(i = 1 ; i <= n; i++) cout << order[i] << " ";*/
  return 0;
}
