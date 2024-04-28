#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 7;
const int M = 1e9 + 7;

int bpf[N], prime[N], ptr;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (bpf[i] == 0) {
            prime[++ptr] =i;
            for (int j = i; j < N; j += i) bpf[j] = i;
        }
    }
}

int dp[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    dp[0][0] = 1;

    for(int i = 1; i <= 500; i++){
        for(int j = 1; j <= i; j++){
            (dp[i][j] += (1LL * dp[i - 1][j - 1] * (prime[j] - 1)) % M) %= M;
            (dp[i][j] += (1LL * dp[i - 1][j] * (prime[j])) % M) %= M;
        }
    }

    int t, cs = 0;
    cin >> t;


    while (t--) {
        cout << "Case " << ++cs << ": ";
        int k, p;
        cin >> k >> p;

        cout << dp[k][p] <<"\n";
    }
}

