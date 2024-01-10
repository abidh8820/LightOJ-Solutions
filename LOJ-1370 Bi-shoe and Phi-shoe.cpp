#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const LL N = 1e6 + 7 + 1e4;

vector<LL> primes;
bool prime[N];
LL phi[N], spf[N];

void init() {
    fill(prime + 2, prime + N, 1);
    phi[1] = 1;
    for (LL i = 2; i < N; i++) {
        if (prime[i]) {
            primes.push_back(i), spf[i] = i;
            phi[i] = i - 1;
        }
        for (auto p : primes) {
            if (p * i >= N or p > spf[i]) break;
            prime[p * i] = false, spf[p * i] = p;
            if (i % p == 0) {
                phi[p * i] = p * phi[i];
                break;
            } else {
                phi[p * i] = phi[p] * phi[i];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL t, cs = 0;
    cin >> t;

    map<LL, LL> mp;

    init();
    for (LL i = N - 1; i >= 2; i--) mp[phi[i]] = i;

    auto it = prev(mp.end());
    int last = it->second;

    while (true) {
        last = min(last, (int)it->second);
        it->second = last;
        if (it == mp.begin()) break; it--;
    }

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL n;
        cin >> n;

        LL ans = 0;
        for (LL i = 1; i <= n; i++) {
            LL x; cin >> x;
            auto it = mp.lower_bound(x);
            ans += it->second;
        }

        cout << ans << " Xukha\n";
    }
}

