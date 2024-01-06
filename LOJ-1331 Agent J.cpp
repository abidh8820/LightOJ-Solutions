#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

double angle(double a, double b, double c) {
    double ret = (a * a + c * c - b * b) / (2.0 * a * c);
    return acos(ret);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        double a, b, c;
        cin >> a >> b >> c;

        double s = a + b + c;
        double area = sqrt(s * (s - a - b) * (s - b - c) * (s - c - a));

        area -= .5 * a * a * angle(a + b, b + c, c + a);
        area -= .5 * b * b * angle(b + c, c + a, a + b);
        area -= .5 * c * c * angle(c + a, a + b, b + c);

        cout << fixed << setprecision(10) << area << "\n";
    }
}

