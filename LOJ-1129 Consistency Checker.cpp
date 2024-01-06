#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct Trie {
    struct node {
        node* nxt[10];
        int sz;
        node() {
            for (int i = 0; i < 10; i++) nxt[i] = NULL;
            sz = 0;
        }
    } * root;
    Trie() { root = new node(); }

    void insert(string s) {
        node* cur = root;
        cur->sz++;
        for (int i = 0; i < s.size(); i++) {
            int b = s[i] - '0';
            if (cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->sz++;
        }
    }

    bool query(string s) {
        node* cur = root;
        for (int i = 0; i < s.size(); i++) {
            int b = s[i] - '0';
            if (cur->nxt[b] == NULL) return false;
            cur = cur->nxt[b];
        }
        return cur->sz;
    }

    void del(node* cur ) {
        for (int i = 0; i < 10; i++)
            if (cur->nxt[i]) del(cur->nxt[i]);
        delete (cur);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        Trie trie;

        int n;
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(),
             [&](string a, string b) { return a.size() > b.size(); });

        bool ok = true;

        for (string s : v) {
            ok &= !trie.query(s);
            trie.insert(s);
        }

        trie.del(trie.root);
        cout << (ok ? "YES" : "NO") << "\n";
    }
}

