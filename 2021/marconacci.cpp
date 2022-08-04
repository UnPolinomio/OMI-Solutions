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
constexpr lli MOD = 1000000007;

vi fibb() {
  vi ans(1e6);
  ans[0] = 0, ans[1] = 1;
  fore(i, 2, ans.size()) ans[i] = (ans[i - 2] + ans[i - 1]) % MOD;
  return ans;
}

int marcc(vi& fib, lli a, lli b, int i) {
  if (i == 1) return a;
  lli m_a{(fib[i - 2] * a) % MOD};
  lli m_b{(fib[i - 1] * b) % MOD};
  return (m_a + m_b) % MOD;
}

int main() {
  _;
  vi fib{fibb()};
  int p{}, a{}, b{}, i{};
  cin >> p;
  while (p--) {
    cin >> a >> b >> i;
    a %= MOD, b %= MOD;
    cout << marcc(fib, a, b, i) << '\n';
  }
  return 0;
}
