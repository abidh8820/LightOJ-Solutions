#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int get(char c){
    if(c=='A') return 0;
    if(c=='G') return 1;
    if(c=='C') return 2;
    if(c=='T') return 3;
}
struct Trie {
    LL ans = 0;
    static const int B = 31;
    static const int alpha = 4;
    struct node {
        node* nxt[alpha];
        int cnt;
        node() {
            for (int i = 0; i < alpha; i++) nxt[i] = NULL;
            cnt = 0;
        }
    } * root;

    Trie() { root = new node(); }

    void insert(string s) {
        node* cur = root;
        cur->cnt++;
        for (int i = 0; i < s.size(); i++) {
            int b = get(s[i]);
            if (cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->cnt++;
        }
    }

    void del(node* cur) {
        for (int i = 0; i < alpha; i++)
            if (cur->nxt[i]) del(cur->nxt[i]);
        delete (cur);
    }

    void dfs(node* now, int depth) {
        ans = max(ans, 1LL * depth * (now->cnt));
        for (int i = 0; i < alpha; i++)
            if (now->nxt[i]) dfs(now->nxt[i], depth + 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n; cin >> n;
        Trie machine;

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            machine.insert(s);
        }

        machine.dfs(machine.root, 0);
        cout << machine.ans << "\n";
        machine.del(machine.root);
    }
}

