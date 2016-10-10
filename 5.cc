#include "contest.h"

int N, M;
typedef pair<long   long, long long> coord_t;
vector<long long> Sx;
vector<long long> Sy;
vector<long long> Bx;
vector<long long> By;


long long sxmin = 1000000000LL, sxmax = -1000000000LL, symin = 1000000000LL, symax = -1000000000LL;

inline bool unreason(long long x, long long y) {
  return (x < sxmin || x > sxmax || y < symin || y > symax);
}

inline bool on(long long px, long long py, long long s1x, long long s1y, long long s2x, long long s2y) {
  return ((s1x <= px) && (s2x <= px))
  && ((s2x - s1x)*(py - s1y) == (s2y - s1y)*(px - s1x));
}

inline bool check(long long px, long long py, long long s1x, long long s1y, long long s2x, long long s2y) {
  return ((s1y>=py) != (s2y>=py)) &&
   (((s2y >= s1y) && (px - s1x)*(s2y-s1y) <= (s2x-s1x)*(py-s1y))
   || ((s2y < s1y) && (px - s1x)*(s2y-s1y) >= (s2x-s1x)*(py-s1y)));
}

//((p.first - s1.first)*(s2.second - s.second) < (s2.first - s1.first)*(p.second-s1.second) )
bool scores(long long px, long long py) {
  int i, j;
  bool c = false;
//  if (unreason(px, py)) return false;
  for (i = 0, j = N-1; i < N; j = i++) {
    if (on(px, py, Sx[i], Sy[i], Sx[j], Sy[j])) return false;
    if (check(px, py, Sx[i], Sy[i], Sx[j], Sy[j]))
      c = !c;
  }
  return c;
}
/*
bool scores(long long p) {
  if (unreason(p)) return false;
  bool c = check(p, S[0], S[S.size() - 1]);
  for (int i = 0; i < S.size() - 1; ++i) {
    if (on(p, S[i], S[i+1])) return false;
    if (check(p, S[i], S[i+1]) || check(p, S[i], S[i+1])) {
      c = !c;
    }
  }
  return c;
}*/

int main(void) {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    long long x, y;
    cin >> x >> y;
    if (x < sxmin) sxmin = x;
    if (y < symin) symin = y;
    if (x > sxmax) sxmax = x;
    if (y > symax) symax = y;
    Sx.push_back(x);
    Sy.push_back(y);
  }

  cin >> M;
  int score = 0;
  for (int i = 0; i < M; ++i) {
    long long int x, y;
    cin >> x >> y;
    if (scores(x, y)) {
      score++;
    }
  }
  cout << score << endl;
  exit(0);
}
