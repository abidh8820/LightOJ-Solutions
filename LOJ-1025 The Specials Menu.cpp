#include <bits/stdc++.h>
using namespace std;

long long dp[61][61];
string s;

long long call(int i, int j) {
    if (i >= j) return (i == j);

    auto &ret = dp[i][j];
    if (ret != -1) return ret;

    ret = 0;
    if (s[i] == s[j]) ret = 1 + call(i + 1, j - 1);
    ret += call(i + 1, j) + call(i, j - 1) - call(i + 1, j - 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> s;   int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) dp[i][j] = -1;
        }
        cout << call(0, n - 1) << "\n";
    }
}

