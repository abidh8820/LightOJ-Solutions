#include "bits/stdc++.h"
using namespace std;

const int N = 1e3 + 7;

int dp[N][N];
string s;

int call(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int& ret = dp[l][r];

    ret = 1e8;
    if (s[l] == s[r]) ret = call(l + 1, r - 1);
    ret = min(ret, call(l + 1, r) + 1);
    ret = min(ret, call(l, r - 1) + 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        memset(dp, -1, sizeof dp);

        cin >> s;
        cout << call(0, s.size() - 1) << endl;
    }
}

