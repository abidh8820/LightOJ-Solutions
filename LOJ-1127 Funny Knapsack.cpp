#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PLL;

int a[40];

void fun(int idx, LL sum, int upto, vector<LL>& v) {
    if (idx > upto) {
        v.push_back(sum);
        return;
    }

    fun(idx + 1, sum + a[idx], upto, v);
    fun(idx + 1, sum, upto, v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL n, w;
        cin >> n >> w;

        for (int i = 0; i < n; i++) cin >> a[i];
        vector<LL> left, right;

        fun(0, 0, n / 2, left);
        fun(n / 2 + 1, 0, n - 1, right);

        sort(right.begin(), right.end());
        LL ans = 0;
        for(auto x : left){
            auto it = upper_bound(right.begin(), right.end(), w-x) - right.begin();
            ans += it;
        }
        cout << ans << endl;
    }
}

