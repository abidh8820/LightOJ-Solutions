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
        int n, p, q;
        cin >> n >> p >> q;


        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int g = 0, tot = 0;
        for (int i = 0; i < n; i++) {
            tot += a[i];
            if (tot <= q) g = i + 1;
            else break;
        }

        n = min(n, g);
        n = min(n, p);
        cout << n << "\n";
    }
}

