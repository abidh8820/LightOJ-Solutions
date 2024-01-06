#include "bits/stdc++.h"
using namespace std;

const int N = 100 + 7;
int a[N];
int dp[N][N][2];

int call(int l, int r, bool alice) {
    if (l > r) return 0;
    int& ret = dp[l][r][alice];

    if (ret != -1) return ret;
    ret = -1e9;

    int cum = 0;
    for (int i = l; i <= r; i++) {
        cum += a[i];
        ret = max(ret, cum - call(i + 1, r, !alice));
    }
    cum = 0;
    for (int i = r; i >= l; i--) {
        cum += a[i];
        ret = max(ret, cum - call(l, i - 1, !alice));
    }
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
        memset(dp, -1 ,sizeof dp);
        cout << call(1, n, 1)<<endl;
    }
}

