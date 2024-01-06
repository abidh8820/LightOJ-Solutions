#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 105;
int dp[N][N], a[N];

int call(int l, int r) {
    if (l == r) return 1;
    if (l > r) return 0;

    int& ret = dp[l][r];
    if (~ret) return ret;

    ret = call(l, r - 1) + 1;

    for (int i = l; i < r; i++) 
        if (a[i] == a[r]) ret = min(ret, call(l, i) + call(i + 1, r - 1));

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];

        memset(dp, -1, sizeof dp);
        cout << call(1, n) << "\n";
    }
}

