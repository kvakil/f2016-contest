#include "contest.h"

typedef pair<int,int> coord_t;

int main(void) {
  string line;
  vector<coord_t> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}; 
  while (getline(cin, line)) {
    int N, r1, c1, r2, c2;
    deque<coord_t> d;
    istringstream in(line);
    in >> N >> r1 >> c1 >> r2 >> c2;
    int mat[N][N];
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        mat[i][j] = -1;
    mat[r1][c1] = 0;
    d.push_back({r1, c1});
    while (!d.empty()) {
      coord_t cur = d.front();
      d.pop_front();
      if (cur.first == r2 && cur.second == c2) {
        break;
      }
      for (coord_t m : moves) {
        int newr = cur.first + m.first;
        int newc = cur.second + m.second;
        if (newr >= 0 && newr < N && newc >= 0 && newc < N) {
          if (mat[newr][newc] == -1) {
            mat[newr][newc] = mat[cur.first][cur.second] + 1;
            d.push_back({newr, newc});
          }
        }
      }
    }
    cout << mat[r2][c2] << endl;
  }
  exit(0);
}
