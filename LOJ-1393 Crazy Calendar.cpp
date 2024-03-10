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
    int n, m;
    cin >> n >> m;

    int XOR = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int x;
        cin >> x;

        int parity = (n + m + i + j) % 2;
        if (parity) XOR ^= x;
      }
    }

    if (XOR) cout << "win\n";
    else cout << "lose\n";
  }
}

