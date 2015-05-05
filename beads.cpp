/*
ID: sinha.k1
PROG: beads
LANG: C++11
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <utility>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <limits>

using namespace std;

typedef long long int64;

void CalculateRuns(const string& necklace, vector<int>& fr, vector<int>& fb) {
  const int N = necklace.length();

  fr[0] = 0;
  fb[0] = 0;
  for (int i = 0; i < N && (necklace[i] == 'r' || necklace[i] == 'w'); i++) {
    fr[0]++;
  }
  for (int i = 0; i < N && (necklace[i] == 'b' || necklace[i] == 'w'); i++) {
    fb[0]++;
  }

  for (int i = N-1; i >= 0; i--) {
    if (necklace[i] == 'r') {
      fr[i] = min(N, fr[(i+1) % N] + 1);
      fb[i] = 0;
    }
    else if (necklace[i] == 'b') {
      fb[i] = min(N, fb[(i+1) % N] + 1);
      fr[i] = 0;
    }
    else {
      fr[i] = min(N, fr[(i+1) % N] + 1);
      fb[i] = min(N, fb[(i+1) % N] + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");

  int N;
  fin >> N;

  string necklace;
  fin >> necklace;

  vector<int> fr(N), fb(N), br(N), bb(N);
  CalculateRuns(necklace, fr, fb);

  reverse(necklace.begin(), necklace.end());
  CalculateRuns(necklace, br, bb);

  int maxrun = 0;
  for (int i = 0; i < N; i++) {
    int local = max(fr[i], fb[i]) + max(br[(N - i) % N], bb[(N - i) % N]);
    local = min(local, N);
    maxrun = max(maxrun, local);
  }

  fout << maxrun << "\n";

  fin.close();
  fout.close();
  return 0;
}
