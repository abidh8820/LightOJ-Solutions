#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9;

struct BIT {
    int n;
    vector<int> ft;
    BIT(int n_) {
        n = n_ + 5;
        ft.assign(n, 0);
    }
    void update(int idx, int val) {
        for (idx++; idx < n; idx += idx & -idx) ft[idx] = max(ft[idx],  val);
    }
    int query(int idx) {
        int sum = 0;
        for (idx++; idx > 0; idx -= idx & -idx) sum = max(sum, ft[idx]);
        return sum;
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        map<int,int> ID;
        int c = 0;

        for(int x : a) ID[x];
        ID[-INF];
        for(auto&[x,y] : ID) y = ++c;

        vector<int> dp1(n), dp2(n);
 

        BIT bit1(c), bit2(c);
        for(int i = 0; i < n; i++) {
            int x = ID[a[i]];
            dp1[i] = bit1.query(x - 1) + 1;
            bit1.update(x, dp1[i]);
        }

        for(int i = n - 1; i >= 0; i--) {
            int x = ID[a[i]];
            dp2[i] = bit2.query(x - 1) + 1;
            bit2.update(x, dp2[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int score = min(dp1[i], dp2[i]);
            ans = max(ans, score * 2 - 1);
        }

        cout << ans << "\n";
    }
}

