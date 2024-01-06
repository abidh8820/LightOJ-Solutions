#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const double PI = acos(-1.0);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {

        cout <<"Case "<<++cs<<": ";
        double r1, r2, h, p;
        cin >> r1 >> r2 >> h >> p;

        double del = (r1 - r2) / h;
        double ans = r2 * r2 * p + r2 * del * p * p + del * del * p * p * p / 3.0;
        ans *= PI;
        cout << fixed << setprecision(10) << ans << "\n";
    }
}

