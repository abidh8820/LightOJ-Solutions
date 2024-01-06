#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-6;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        double n, c;
        cin >> n >> c;


        if(n==0){
            cout<<0<<endl;
            continue;
        }
        double l = EPS, r = 1e9;

        auto f = [&](double t) {
            return t * (c - n * t);
        };

        int cnt = 100;
        while (r-l>EPS) {
            double mid1 = l + (r - l) / 3;
            double mid2 = r - (r - l) / 3;
            if (f(mid2) > f(mid1)) l = mid1;
            else r = mid2;
        }

        int T = l;
        LL best = max(f(T + 1), f(T));

        int ans = (f(T + 1) > f(T) ? T + 1 : T);
         while (f(ans - 1) == best) ans--;
        cout << ans << "\n";
    }
}

