#include "contest.h"

int n;
int h[50], w[50], c[50], num[50], smallest;
string cat[50];
vector<int> diff[4];
map<string, int> cat_idx;

void sol(int lvl, int work) {
  if (lvl > 3) {
    smallest = min(smallest, work);
    return;
  }
  for (auto a : diff[lvl]) {
    for (auto b : diff[lvl]) {
      if (b > a) {
        ++num[c[a]];
        ++num[c[b]];
        if (num[c[a]] <= 2 && num[c[b]] <= 2) {
          sol(lvl + 1, work + w[a] + w[b]);
        }
        --num[c[a]];
        --num[c[b]];
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> cat[i] >> w[i];
    diff[--h[i]].push_back(i);
    cat_idx.insert(pair<string, int>(cat[i], cat_idx.size()));
    c[i] = cat_idx[cat[i]];
  }
  smallest = 5000000;
  sol(0, 0);
  cout << smallest << endl;
  exit(0);
}
