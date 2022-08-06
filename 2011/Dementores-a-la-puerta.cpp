#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << (x) << '\n';
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

using Dementors_t = unordered_map<int, unordered_set<int>>;

int N{}, O{};
vector<vb> obstacles;

pair<Dementors_t, bool> to_dir(bool to_right, const Dementors_t& dementors) {
  Dementors_t new_dem{};
  bool changed{false};

  for (auto& row : dementors) {
    for (int j : row.second) {
      int i{row.first};
      if (to_right) {
        while (++j < N && !obstacles[i][j]) changed = true;
        --j;
      } else {  // to bottom
        while (++i < N && !obstacles[i][j]) changed = true;
        --i;
      }

      new_dem[i].insert(j);
    }
  }

  return {new_dem, changed};
}

int solve(bool to_right, Dementors_t curr) {
  int ans{0};

  while (curr.size() != 1 || curr.begin()->second.size() != 1) {
    auto nxt{to_dir(to_right, curr)};
    if (!nxt.second) return -1;
    curr = nxt.first;
    ++ans;
    to_right = !to_right;
  }

  return ans;
}

int main() {
  _;
  cin >> N >> O;

  obstacles.resize(N, vb(N, false));
  int a{}, b{};
  while (O--) {
    cin >> a >> b;
    obstacles[b][a] = true;
  }

  Dementors_t dementors{};
  fore(i, 0, N) dementors[i].insert(0);
  fore(j, 1, N) dementors[0].insert(j);

  int ans{INT_MAX};

  fore(i, 0, 2) {
    int slv{solve(i % 2 == 0, dementors)};
    if (slv != -1) ans = min(ans, slv);
  }

  cout << ans << '\n';

  return 0;
}
