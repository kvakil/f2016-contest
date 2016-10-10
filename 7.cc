#include "contest.h"

// ugh I hate this problem...............

#define MAXN 50000
typedef long long ll;

ll N;
ll K, S, MAX;
ll C[50001], R[50001];

ll try_row(ll LUCK){
  int j = N - 1;
  ll sum = 0;
  for (int i = 0; i < N; ++i){
    while (j >= 0 && C[i] * R[j] > LUCK) {
      --j;
    }
    sum += j + 1;
  }
  return sum;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; ++i) { long int x; cin >> x; C[i] = x; }
  for (int i = 0; i < N; ++i) { long int x; cin >> x; R[i] = x; }

  sort(C, C+N);
  sort(R, R+N);
  K = N * N - K + 1;
  if (try_row(0) >= K) {
      cout << 0 << endl;
      exit(0);
  }

  MAX = C[N-1] * R[N-1];

  ll low = 0;
  ll high = MAX + 1;
  ll mid;
  while (low + 1 < high){
      mid = (low + high)/2;
      if (try_row(mid) >= K) { 
        high = mid;
      } else {
        low = mid;
      }
  }
  cout << high << endl;
}
