#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e6 + 1;

unsigned long long phi[N];
bool composite[N];

void totient() {
    phi[1] = 1; vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (!composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int p : primes) {
            if (p * i > N) break;
            composite[i * p] = true;

            if (i % p == 0) {
                phi[i * p] = phi[i] * p; break;
            } 
            else  phi[i * p] = phi[i] * phi[p];
        }
    }

    for (int i = 1; i < N; i++) phi[i] *= phi[i];
    for (int i = 1; i < N; i++) phi[i] += phi[i - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    totient();
    int t, c = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++c << ": ";
        int a, b; cin >> a >> b;

        cout << phi[b] - phi[a - 1] << endl;
    }
}

