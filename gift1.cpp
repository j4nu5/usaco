/*
ID: sinha.k1
PROG: gift1
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

int main() {
  ios_base::sync_with_stdio(0);
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");

  int np;
  fin >> np;
  fin.ignore(1, '\n');

  vector<string> friends(np);
  unordered_map<string, int> ids;
  vector<int> accounts(np, 0);

  for (int i = 0; i < np; i++) {
    fin >> friends[i];
    ids[friends[i]] = i;
  }

  for (int i = 0; i < np; i++) {
    string person;
    fin >> person;

    int id = ids[person];
    int total, f;
    fin >> total >> f;
    fin.ignore(1, '\n');

    if (!f)
      continue;

    int gift = total / f;
    accounts[id] -= (gift * f);

    for (int j = 0; j < f; j++) {
      string fr;
      fin >> fr;

      accounts[ids[fr]] += gift;
    }
  }

  for (const string& f : friends) {
    fout << f << " " << accounts[ids[f]] << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
