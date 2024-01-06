#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;
map<string, int> dep;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++c << ": ";
        int n;    cin >> n;
        adj.clear(),  dep.clear();

        for (int i = 0; i < n; i++) {
            string u, v;  cin >> u >> v;
            adj[u].push_back(v);
            dep[v]++; dep[u]++, dep[u]--;
        }

        set<pair<int, string>> PQ;
        for (auto [x, w] : dep) {
            PQ.insert({w, x});
        }

        bool cycle = false;
        while (!PQ.empty()) {
            auto [cnt, u] = *PQ.begin();
            PQ.erase(*PQ.begin());

            if (cnt) {
                cycle = true; break;
            }

            for (auto v : adj[u]) {
                PQ.erase({dep[v], v});
                dep[v]--;
                PQ.insert({dep[v], v});
            }
        }

        cout << (cycle ? "No" : "Yes") << endl;
    }
}

