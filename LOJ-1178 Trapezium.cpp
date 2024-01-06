#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const double EPS = 1e-9;
int dcmp(double x) { return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        double a, b, c, d;
        cin >> a >> b >> c >> d;

        double h =(b*b - d*d + (a-c) * (a-c))/ (2.0*(a-c));
        h = h*h; h = b*b -h; h = sqrt(h);
        double area = (a+c)*h*0.5;
        cout<<fixed<<setprecision(10)<<area<<"\n";
    }
}

