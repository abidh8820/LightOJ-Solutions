#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
using PII = pair<int,int>;
const int N = 1e5 + 7;

vector<int> primes;
bool prime[N];
int spf[N], phi[N], sod[N];
int nod[N], cnt[N], pw[N];

void init() {
    fill(prime + 2, prime + N, 1);
    sod[1] = nod[1] = phi[1] = spf[1] = 1;
    for (LL i = 2; i < N; i++) {
        if (prime[i]) {
            primes.push_back(i), spf[i] = i;
            phi[i] = i - 1;
            nod[i] = 2, cnt[i] = 1;
            sod[i] = i + 1, pw[i] = i;
        }
        for (auto p : primes) {
            if (p * i >= N or p > spf[i]) break;
            prime[p * i] = false, spf[p * i] = p;
            if (i % p == 0) {
                nod[p * i] = nod[i] / (cnt[i] + 1) * (cnt[i] + 2);
                sod[p * i] = sod[i] / sod[pw[i]] * (sod[pw[i]] + p * pw[i]);
                phi[p * i] = p * phi[i];
                cnt[p * i] = cnt[i] + 1;
                pw[p * i] = p * pw[i];
                break;
            } else {
                phi[p * i] = phi[p] * phi[i];
                nod[p * i] = nod[p] * nod[i], cnt[p * i] = 1;
                sod[p * i] = sod[p] * sod[i], pw[p * i] = p;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    int t, cs = 0;
    cin >> t;

    vector<PII> a;
    for (int i = 1; i <= 1000; i++) {
        a.emplace_back(nod[i], -i);
    }

    sort(a.begin(), a.end());
    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n;
        cin >> n;

        cout << -a[n - 1].second << "\n";
    }
}

