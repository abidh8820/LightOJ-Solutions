#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 7;

int bpf[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (bpf[i] == 0) {
            primes.push_back(i);
            for (int j = i; j < N; j += i) bpf[j] = i;
        }
    }
}

LL divs(LL n) {
    LL ret = 1;
    for (LL p : primes) {
        if (p * p > n) break;
        if (n % p) continue;
        int c = 0;
        while (n % p == 0) n /= p, c++;
        ret *= (1 + c);
    }
    if (n > 1) ret *= 2;
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL a, b;
        cin >> a >> b;

        if (b * b > a) {
            cout << 0 << "\n";
            continue;
        }

        LL ans = divs(a) / 2;
        for (int i = 1; i < b; i++) {
            if (a % i == 0) ans--;
        }
        cout << ans << "\n";
    }
}

