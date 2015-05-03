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

int CollectF(int start, char color, const string& necklace) {
  int run = 0;
  int N = necklace.length();

  for (int i = 0; i < N; i++) {
    int pos = (start + i) % N;

    if (necklace[pos] != 'w' && necklace[pos] != color)
      break;

    run++;
  }

  return run;
}

int CollectB(int start, char color, const string& necklace) {
  int N = necklace.length();
  int run = 0;

  for (int i = 0; i < N; i++) {
    int pos = (start - i - 1 + N) % N;

    if (necklace[pos] != 'w' && necklace[pos] != color)
      break;

    run++;
  }

  return run;
}

int main() {
  ios_base::sync_with_stdio(0);
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");

  int N;
  fin >> N;
  fin.ignore(1, '\n');

  string necklace;
  fin >> necklace;

  int opt = 0;
  for (int i = 0; i < N; i++) {
    int forward = max(CollectF(i, 'r', necklace), CollectF(i, 'b', necklace));
    int backward = max(CollectB(i, 'r', necklace), CollectB(i, 'b', necklace));

    opt = max(opt, min(forward + backward, N));
  }

  fout << opt << "\n";

  fin.close();
  fout.close();
  return 0;
}
