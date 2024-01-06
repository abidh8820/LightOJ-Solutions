#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e8 + 1;
bitset<N> ans;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    vector<int> Q;
    int mx = 0;
    while (t--) {
        int n;
        cin >> n;
        Q.push_back(n);
        mx = max(mx, n);
        ans[n] = 1;
    }

    double cur = 0;
    map<int, double> res;

    for (int i = 1; i <= mx; i++) {
        cur = cur + 1.0 / i;
        if (ans[i]) res[i] = cur;
    }

    for (auto x : Q) {
        cout << "Case " << ++cs << ": ";
        cout << fixed<<setprecision(10)<<res[x] << "\n";
    }
}

