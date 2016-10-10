#include "contest.h"

int main() {
  int n, t;
  cin >> n;
  int idx = 1;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t == idx) {
      ++idx;
    }
  }
  cout << n - idx + 1 << endl;
}
