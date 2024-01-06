#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 1e7 + 7;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    bpf[0] = 1;
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        int cnt = 0;
        for (int x : primes) {
            if (x > n) break;
            int y = n - x;
            if (bpf[y] == y && x<=y) cnt++;
        }

        cout << cnt<<"\n";
    }
}

