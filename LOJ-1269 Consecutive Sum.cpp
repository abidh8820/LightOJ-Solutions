#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct Trie {
    static const int B = 31;
    struct node {
        node* nxt[2];
        int cnt;
        node() {
            nxt[0] = nxt[1] = NULL;
            cnt = 0;
        }
    } * root;

    Trie() { root = new node(); }

    void insert(int val) {
        node* cur = root;
        cur->cnt++;
        for (int i = B - 1; i >= 0; i--) {
            int b = val >> i & 1;
            if (cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->cnt++;
        }
    }

    int XorMax(int x) {
        node* cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int k = x >> i & 1;
            if (cur->nxt[!k]) cur = cur->nxt[!k], ans <<= 1, ans++;
            else cur = cur->nxt[k], ans <<= 1;
        }
        return ans;
    }

    int XorMin(int x) {
        node* cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
            int k = x >> i & 1;
            if (cur->nxt[k]) cur = cur->nxt[k], ans <<= 1;
            else cur = cur->nxt[!k], ans <<= 1, ans++;
        }
        return ans;
    }

    void del(node* cur) {
        for (int i = 0; i < 2; i++)
            if (cur->nxt[i]) del(cur->nxt[i]);
        delete (cur);
    }
} ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        Trie trie;
        trie.insert(0);

        int ans1 = 0, ans2 = INT_MAX;

        for(int i = 0; i < n; i++){
            if(i) a[i] ^= a[i - 1];
            ans1 = max(ans1, trie.XorMax(a[i]));
            ans2 = min(ans2, trie.XorMin(a[i]));
            trie.insert(a[i]);
        }

        cout << ans1 << " " << ans2 << "\n";
        trie.del(trie.root);
    }
}

