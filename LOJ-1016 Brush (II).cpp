#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int solve() {
    int n, w;
    cin >> n >> w;
    pair<int, int> p[n];
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p[i] = {b, a};
    }

    sort(p, p + n);
    int index = 0, ans = 1;

    for (int i = 0; i < n; i++) {
        if (p[i].first - p[index].first > w) {
            ans++, index = i;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cout << "Case " << k << ": " << solve() << endl;
    }
}
