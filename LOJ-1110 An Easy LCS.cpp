#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 101;

string dp[N][N];
bool vis[N][N];

string a, b;
int n, m;

string call(int x, int y) {
    if (x >= n || y >= m) return "";
    string& ret = dp[x][y];

    if (vis[x][y]) return ret;
    vis[x][y] = true;
    ret = "";

    if (a[x] == b[y]) {
        ret = string(1, a[x]) + call(x + 1, y + 1);
    } else {
        string ans1 = call(x + 1, y);
        string ans2 = call(x, y + 1);
        if (ans1.size() > ans2.size()) ret = ans1;
        if (ans1.size() < ans2.size()) ret = ans2;
        if (ans1.size() == ans2.size()) ret = min(ans1, ans2);
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

        cin >> a >> b;
        n = a.size(), m = b.size();

        memset(vis, 0, sizeof vis);
        string ans = call(0,0);
        if(ans=="") ans = ":(";
        cout << ans << "\n";
    }
}

