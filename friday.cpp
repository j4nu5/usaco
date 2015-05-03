/*
ID: sinha.k1
PROG: friday
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

vector<int> freq(7, 0);
int days_in_month[] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool IsLeapYear(const int& year) {
  if (year % 100) {
    return (year % 4 == 0);
  }
  return (year % 400 == 0);
}

int DaysInMonth(const int& month, const int& year) {
  if (month != 1 || !IsLeapYear(year))
    return days_in_month[month];

  return 29;
}

int Get13Day(const int& month, const int& year, int& day) {
  // Return 13th day of the month and update day to the last day of the month
  int day13 = (day + 12) % 7;

  day = (day + DaysInMonth(month, year) - 1) % 7;

  return day13;
}

int main() {
  ios_base::sync_with_stdio(0);
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");

  int N;
  fin >> N;

  int day = 2; // Jan 1, 1900 was a Monday
  for (int year = 1900; year < 1900 + N; year++) {
    for (int month = 0; month < 12; month++) {
      int day13 = Get13Day(month, year, day);
      day = (day + 1) % 7;

      freq[day13]++;
    }
  }

  fout << freq[0];
  for (int i = 1; i < 7; i++)
    fout << " " << freq[i];
  fout << "\n";

  fin.close();
  fout.close();
  return 0;
}
