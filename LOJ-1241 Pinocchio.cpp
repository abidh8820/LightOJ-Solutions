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

    int last = 2, ans = 0, n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      ans += (x - last + 4) / 5;
      last = x;
    }

    cout << ans << "\n";
  }
}

