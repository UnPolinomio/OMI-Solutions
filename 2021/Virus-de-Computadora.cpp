#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

int N{}, M{}, K{};
vector<vi> msgs{};
vi initial{};

int get_min() {
  int ans{K};
  vb visited(N + 1, false);

  for (int i : initial) visited[i] = true;

  fore(i, 0, initial.size()) {
    for (int to : msgs[initial[i]]) {
      if (visited[to]) continue;
      ++ans;
      visited[to] = true;
    }
  }

  return ans;
}

int get_max(int root) {
  static vb visited(N + 1, false);

  if (visited[root]) return 0;

  int ans{1};
  visited[root] = true;
  for (int msg : msgs[root]) ans += get_max(msg);

  return ans;
}

int main() {
  _;

  cin >> N >> M >> K;

  initial.resize(K);
  msgs.resize(N + 1);

  int a{}, b{};
  fore(i, 0, K) cin >> initial[i];
  while (M--) {
    cin >> a >> b;
    msgs[a].push_back(b);
  }

  int ans_max{0};
  for (int i : initial) {
    ans_max += get_max(i);
  }

  cout << get_min() << ' ' << ans_max << '\n';

  return 0;
}
