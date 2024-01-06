#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const LL M = 1e8 + 7;
const LL N = 5005;

LL dp[N];
vector<LL> v;

LL findCnt(LL x) { return LL(upper_bound(v.begin(), v.end(), x) - v.begin()); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<LL> st;
    for (LL num = 2; num <= 2e5; num++) {
        for (LL pw = 2; pw <= 64; pw++) {
            LL now = 1, cnt = pw;
            while (cnt > 0 && now * num <= 2e10) {
                now *= num, cnt--;
            }
            if (cnt <= 0) st.insert(now);
        }
    }

    for (LL x : st) v.push_back(x);

    dp[0] = 1;
    for (LL i = 1; i < N; i++) {
        dp[i] = 0;
        for (LL left = 0; left < i; left++) {
            LL right = i - left - 1;
            dp[i] += (1LL * dp[left] * dp[right]) % M;
            if (dp[i] >= M) dp[i] -= M;
        }
    }

    LL t, cs = 0;
    cin >> t;

    dp[0] = 0;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL a, b;
        cin >> a >> b;

        int len = findCnt(b) - findCnt(a - 1);
        cout << dp[len] << "\n";
    }
}

