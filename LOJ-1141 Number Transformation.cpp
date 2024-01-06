#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 7;
const int INF = 1e9 + 7;

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

int n, m;
vector<int> adj[N];

vector<int> bfs(int s) {
    vector<int> d(1005, INF);
    d[s] = 0;
    vector<int> Q = {s};

    for (int i = 0; i < Q.size(); i++) {
        int u = Q[i];
        for (int v : adj[u]) {
            if(v>1000) continue;
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                Q.push_back(v);
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();


    for (int i = 2; i <= 1000; i++) {
        int cur = i;
        if(bpf[i]==i) continue;
        while (cur > 1) {
            int p = bpf[cur];
            if(i==p) break;
            adj[i].push_back(i + p);
            while (cur % p == 0) cur /= p;
        }
    }

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> n >> m;

        auto d1 = bfs(n);
        if ( m>1000 || d1[m] > 1000) {
            cout << -1 << "\n";
            continue;
        }
        cout << d1[m] << "\n";
    }
}

