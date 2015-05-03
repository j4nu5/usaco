/*
ID: sinha.k1
PROG: ride
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

const int kMod = 47;

int Checksum(const string& s) {
  int csum = 1;
  for (char ch : s) {
    csum = (csum * (ch - 'A' + 1)) % kMod;
  }
  return csum;
}

int main() {
  ios_base::sync_with_stdio(0);
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");

  string comet, group;
  fin >> comet >> group;

  int comet_chksum = Checksum(comet);
  int group_chksum = Checksum(group);

  if (comet_chksum == group_chksum)
    fout << "GO\n";
  else
    fout << "STAY\n";

  fin.close();
  fout.close();
  return 0;
}
