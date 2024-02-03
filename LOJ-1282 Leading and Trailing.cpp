#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int M = 1000;
LL bigMod(LL a, LL e) {
  if (e == -1) e = M - 2;
  LL ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % M;
    a = a * a % M, e >>= 1;
  }
  return ret;
}

int main() {
  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    int n, k;
    cin >> n >> k;

    double g = k * log10(n * 1.0);
    g -= (int)g, g = pow(10.0, g);

    printf("%03d %03d\n", int(g * 100), (int)bigMod(n, k));
  }
}

