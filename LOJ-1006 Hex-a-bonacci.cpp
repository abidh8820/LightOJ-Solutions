#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int a, b, c, d, e, f;

const int M = 1e7 + 7;
long long dp[N];

int main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        dp[0] = a%M, dp[1] = b%M, dp[2] = c%M, dp[3] = d%M, dp[4] = e%M, dp[5] = f%M;
        for (int i = 6; i <= n; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % M + (dp[i - 3] + dp[i - 4]) % M +(dp[i - 5] + dp[i - 6]) % M) % M;
        }
        printf("Case %d: %d\n", caseno, (int)dp[n]);
    }
    return 0;
}
