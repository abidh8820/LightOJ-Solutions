#include <bits/stdc++.h>
using namespace std;

// x1+y1 == x2+y2 holds, so keeping x1,y1,x2 is enough to know the state of the transition.
const int N = 100 + 7;
int n, m, a[N][N];
int dp[N][N][N];

int call(int x1, int y1, int x2, int y2) {
    if (x1 >= n || x2 >= n || y1 >= m || y2 >= m) return 0;
    if (x1 == x2 && y1 == y2) return 0;
    if (dp[x1][y1][x2] != -1) return dp[x1][y1][x2];
    int cur = 0;
    cur = max(cur, call(x1 + 1, y1, x2 + 1, y2));
    cur = max(cur, call(x1 + 1, y1, x2, y2 + 1));
    cur = max(cur, call(x1, y1 + 1, x2 + 1, y2));
    cur = max(cur, call(x1, y1 + 1, x2, y2 + 1));
    return dp[x1][y1][x2] = cur + a[x1][y1] + a[x2][y2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp, -1, sizeof dp);;

        int ans = call(0, 1, 1, 0);
        ans += a[0][0] + a[n - 1][m - 1];

        cout << "Case " << ++c << ": " << ans << endl;
    }
}

