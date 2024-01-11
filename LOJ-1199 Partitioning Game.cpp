#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 20005;
int dp[N];

int grundy(int n) {
    if (n <= 1) return 0;
    if (~dp[n]) return dp[n];

    set<int> st;
    for (int i = 1; i*2 < n; i++) {
        int XOR = grundy(i) ^ grundy(n - i);
        st.insert(XOR);
    }

    int ans;
    for (int i = 0; i < N; i++) {
        if (!st.count(i)) { ans = i; break; }
    }
    return dp[n] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t, cs = 0;
    cin >> t;

    memset(dp, -1, sizeof dp);
    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        LL XOR = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            XOR ^= grundy(x);
        }

        cout << (XOR? "Alice" : "Bob") << "\n";
    }
}

