#include "contest.h"

typedef pair<int, int> c_t;

vector<c_t> moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
c_t start;
c_t mw;
int n, m;
map<c_t, char> mp;
map<pair<c_t, int>, int> d; 
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      if (c == 'S') {
        start = {i, j};
        c = '.';
      } else if (c == 'W') {
        mw = {i, j};
      }
      mp[{i, j}] = c;
      d[{{i, j}, 0}] = d[{{i, j}, 1}] = -1;
    }
  }

  queue<pair<c_t, int>> q;
  q.push({start, 0});
  d[{start, 0}] = 0;
  while (!q.empty()) {
    c_t cur = q.front().first;
    int s = q.front().second;
    q.pop();
    for (const auto m : moves) {
      c_t next = {cur.first + m.first, cur.second + m.second};
      if (mp[next] == 'W')
        continue;
      int news = s;
      if (cur.first > mw.first &&
        ((cur.second == mw.second && next.second > mw.second) ||
        ((next.second == mw.second && cur.second > mw.second)) )) {
        news = 1 - news;
      }
      if (d[{next, news}] == -1) {
        d[{next, news}] = d[{cur, s}] + 1;
        q.push({next, news});
      }
    }
  }
  cout << d[{start, 1}] << endl;
}
