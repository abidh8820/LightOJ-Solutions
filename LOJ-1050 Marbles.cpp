#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 505;

double dp[N][N][2];

double call(int R, int B, int me) {
    if (B == 1 && R == 0) return 1.0;
    if (!me && B == 0) return 0;

    double &ret = dp[R][B][me];
    if (abs(ret + 1) > 1e-5) return ret;

    ret = 0;
    if (me) {
        if (R) ret += 1.0 * R / (R + B) * call(R - 1, B, !me);
        if (B) ret += 1.0 * B / (R + B) * call(R, B - 1, !me);
    } else ret = call(R, B - 1, !me);

    return ret;
}

int main() {
    int t, cs = 0;
    cin >> t;

    memset(dp, -1, sizeof dp);
    while (t--) {
        cout << "Case " << ++cs << ": ";

        int R, B;
        cin >> R >> B;

        cout << fixed << setprecision(10) << call(R, B, 1) << "\n";
    }
}

