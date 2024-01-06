#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
typedef long long LL;

bool flag[N];
vector<LL> primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!flag[i]) {
            for (int j = 2 * i; j < N; j += i) flag[j] = 1;
            primes.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL n;
        cin >> n;

        LL ans = 1;
        for (auto i : primes) {
            if (i * i > n) break;
            int cnt = 0;
            while (n % i == 0) cnt++, n /= i;
            ans *= (cnt+1);
        }
        if (n > 1) ans *= 2;
        cout<< ans-1 <<endl;
    }
}

