#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int M = 1e9 + 7;
const int N = 1 << 18;

bool comp(pii a, pii b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

LL tree[N * 4],  a[N], dp[N];

void update(int u, int l, int r, int i, int j, int val) {
    if (r < i || l > j) return;
    if (l >= i && r <= j) {
        tree[u] += val; return;
    }
    int mid = (l + r) / 2;
    update(u * 2, l, mid, i, j, val);
    update(u * 2 + 1, mid + 1, r, i, j, val);
    tree[u] = (tree[u * 2] + tree[u * 2 + 1]) % M;
}

LL query(int u, int l, int r, int i, int j) {
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) return tree[u];
    int mid = (l + r) / 2;
    return (query(u * 2, l, mid, i, j) + query(u * 2 + 1, mid + 1, r, i, j)) % M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < n; i++) a[i] = v[i].second;
        for (int i = 0; i <= 4 * n; i++) tree[i] = 0;

        for (int i = 0; i < n; i++) {
            int idx = a[i];   dp[idx] = 1;
            dp[idx] = (dp[idx] + query(1, 0, n - 1, 0, idx - 1)) % M;
            update(1, 0, n - 1, idx, idx, dp[idx]);
        }
        long long ans = 0;

        for (int i = 0; i < n; i++) ans = (ans + dp[i]) % M;
        cout << ans << endl;
    }
}

