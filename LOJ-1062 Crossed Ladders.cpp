#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        double x, y, h;
        cin >> x >> y >> h;

        double lo = 0, hi = 1e9;
        int cnt = 62;

        while (cnt--) {
            double c = (lo + hi) / 2.0;
            double h1 = sqrt(-c * c + x * x);
            double h2 = sqrt(-c * c + y * y);
            double h_ = h1 * h2 / (h1 + h2);

            if (h_ > h) lo = c;
            else hi = c;
        }

        printf("%6lf\n", lo);
    }
}

