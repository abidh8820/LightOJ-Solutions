#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        double L, W;
        cin >> L >> W;

        auto f = [&](double x) { return x * (L - 2 * x) * (W - 2 * x); };

        double l = 0, r = min(L / 2.0, W / 2.0);
        while (r - l > EPS) {
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            if (f(mid1) > f(mid2)) r = mid2;
            else l = mid1;
        }

        cout << fixed << setprecision(10) << f(l) << "\n";
    }
}

