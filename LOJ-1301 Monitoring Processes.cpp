#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    int n;
    cin >> n;

    map<int, int> st, en;
    set<int> p;
    for (int i = 1; i <= n; i++) {
      int l, r;
      cin >> l >> r;
      st[l]++, en[r]++;
      p.insert(l), p.insert(r);
    }

    int cnt = 0, ans = 0;
    for (int x : p) {
      cnt += st[x];
      ans = max(ans, cnt);
      cnt -= en[x];
    }

    cout << ans << "\n";
  }
}

