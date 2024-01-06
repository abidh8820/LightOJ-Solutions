#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int dp[N][N][N];

string a, b, c;
int lcs(int i, int j, int k) {
    if (i >= a.size() || j >= b.size() || k >= c.size()) return 0;
    int &ret = dp[i][j][k];
    if (ret != -1) return dp[i][j][k]; ret = 0;

    if (a[i] == b[j] && b[j] == c[k]) {
        ret = max(ret, lcs(i + 1, j + 1, k + 1) + 1);
    } 
    else {
        ret = max(ret, lcs(i + 1, j, k));
        ret = max(ret, lcs(i, j + 1, k));
        ret = max(ret, lcs(i, j, k + 1));
        ret = max(ret, lcs(i + 1, j + 1, k));
        ret = max(ret, lcs(i + 1, j, k + 1));
        ret = max(ret, lcs(i, j + 1, k + 1));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {

        memset(dp, -1, sizeof dp);
        cin >> a >> b >> c;

        cout << "Case " << ++cs << ": ";

        cout << lcs(0, 0, 0) << endl;
    }
}

