#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int dp[N][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char, int> mp;

    for (char c = '0'; c <= '9'; c++) mp[c] = c - '0';
    for (char c = 'A'; c <= 'F'; c++) mp[c] = 10 + c - 'A';

    int t, cs = 0;

    cin >> t;
    while (t--) {
        int base, k;
        cin >> base >> k;
        string s; cin >> s;

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        int comb = (1 << s.size()) - 1;

        for (int mask = 0; mask <= comb; mask++) {
            for (int i = 0; i < s.size(); i++) {
                if (mask >> i & 1) continue;
                for (int rem = 0; rem < k; rem++) {
                    dp[mask | (1 << i)][(rem * base + mp[s[i]]) % k] +=  dp[mask][rem];
                }
            }
        }
        cout<<"Case "<<++cs<<": ";
        cout<<dp[comb][0]<<endl;
    }
}

