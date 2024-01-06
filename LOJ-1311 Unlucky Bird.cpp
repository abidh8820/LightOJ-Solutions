#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        double v1, v2, v3;
        cin >> v1 >> v2 >> v3;

        double a1, a2;
        cin >> a1 >> a2;

        double t1 = v1 / a1, t2 = v2 / a2;

        double s1 = v1 * t1 - 0.5 * a1 * t1 * t1;
        double s2 = v2 * t2 - 0.5 * a2 * t2 * t2;

        double d = s1 + s2;
        double dis = max(t1, t2) * v3;

        cout << fixed << setprecision(10);
        cout << d << " " << dis << "\n";
    }
}

