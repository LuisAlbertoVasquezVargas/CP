#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int N;
int D[100000];

void output(int x1, int x2) {
  bool nonzero = 0;
  for (int i = 0; i < N; i++) {
    if (i == x1 || i == x2) continue;
    if (D[i] == 0) {
      if (nonzero) cout << D[i];
    }
    else {
      nonzero = 1;
      cout << D[i];
    }
  }
  if (!nonzero) cout << 0;
  cout << "\n";
}

int main() {
  while(cin >> N)
  {
  for (int i = 0; i < N; i++) cin >> D[i];
  sort(D, D+N); reverse(D, D+N);

  if (D[N-1] != 0) {
    cout << -1 << "\n";
    return 0;
  }

  int alls = 0;
  vector<int> zero, one, two;
  for (int i = 0; i < N; i++) {
    alls += D[i];
    if (D[i] % 3 == 0) zero.push_back(i);
    if (D[i] % 3 == 1) one.push_back(i);
    if (D[i] % 3 == 2) two.push_back(i);
  }

  bool nonzero = 0;
  if (alls % 3 == 0) output(-1,-1);
  else if (alls % 3 == 1) {
    if (one.size() > 0) {
      output(one.back(), -1);
    }
    else if (two.size() > 1) {
      output(two[two.size()-2], two[two.size()-1]);
    }
  }
  else if (alls % 3 == 2) {
    if (two.size() > 0) {
      output(two.back(), -1);
    }
    else if (one.size() > 1) {
      output(one[one.size()-2], one[one.size()-1]);
    }
  }
     }
}
