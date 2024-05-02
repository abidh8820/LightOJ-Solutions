#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF =  1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n, W;
        cin >> n >> W;

        vector<int> p(n), c(n), w(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i] >> c[i] >> w[i];
            W -= w[i] * c[i];
        }

        if(W < 0){
            cout << "Impossible\n";
            continue;
        }

        vector<LL> dp(W + 1, 0);
        for(int j = 1; j <= W; j++){
            for(int i = 0; i < n; i++){
                if( j >= w[i]) dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
            }
        }

        cout << dp[W] << "\n";

    }
}

