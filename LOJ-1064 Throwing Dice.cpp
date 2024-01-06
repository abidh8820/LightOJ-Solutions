#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, x;
const int N = 205;

LL dp[N][N];

LL call(int idx, int sum) {
    if (idx >= n) {
        if (sum >= x) return 1;
        else return 0;
    }

    LL &ret = dp[idx][sum];
    if (~ret) return ret;

    ret = 0;
    for (int i = 1; i <= 6; i++) ret += call(idx + 1, sum + i);

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        memset(dp, -1, sizeof dp);
        cout << "Case " << ++cs << ": ";
        cin >> n >> x;

        LL d = 1, u = call(0, 0);
        for (int i = 1; i <= n; i++) d *= 6;

        LL g = gcd(u, d);

        u /= g, d /= g;

        if(u==0) cout << 0 <<"\n";
        else if(u==1 && d==1) cout << 1<<"\n";
        else cout << u << "/" << d << "\n";
    }
}

