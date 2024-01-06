#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const LL N = 1e8 + 1;

bitset<N> prime;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < N; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j < N; j += i) prime[j] = 1;
    }

    unsigned int cur = 1;

    int cnt = 0;
    vector<int> primes;
    vector<unsigned int> mul;
    for (int i = 2; i < N; i++) {
        if (prime[i]) continue;
        primes.push_back(i);
        if (mul.empty()) mul.push_back(i);
        else mul.push_back(mul.back() * i);
    }
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        auto id = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
        unsigned int ans = mul[id];

        for (LL p : primes) {
            if (p * p > n) break;
            LL now = p;
            while (now * p <= n) ans *= p, now *= p;
        }
        cout << ans << "\n";
    }
}

