#include "contest.h"

int n, a[401][401];
int w[2][2][401][401];

int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        cin >> a[i][j];
    }
  }
  bool p = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = j; k <= n; ++k) {
        w[p][false][j][k] = max(a[i][j] + a[i][k] * (j != k) + w[!p][true][j][k],
                                          a[i][j] * (j != k) + w[p][false][j-1][k]);
        w[p][true ][j][k] = max({w[p][false][j][k],
                                w[p][true][j][k] + a[i][j] + a[i][k] * (j != k),
                                (j != k) * (w[p][true][j][k-1] + a[i][k])});
      }
    }
    p = !p;
  }
  cout << w[n % 2][true][n][n] << endl;
  exit(0);
}
