/*
ID: sinha.k1
PROG: test
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
  ofstream fout ("test.out");
  ifstream fin ("test.in");

  int a, b;
  fin >> a >> b;

  fout << a + b << "\n";

  fin.close();
  fout.close();
  return 0;
}
