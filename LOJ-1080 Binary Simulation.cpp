#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const int N = 1 << 18;

LL tree[N * 4], prob[N * 4], a[N];

void build(int u, int l, int r) {
    if (l == r) {
        tree[u] = a[l];  return;
    }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    tree[u] = (tree[u * 2]+ tree[u * 2 + 1]);
}

void propagate(int u,int l, int r) {
    int mid = (l+r)/2;
    prob[u * 2] += prob[u];
    tree[u * 2] += prob[u]*(mid-l+1);
    prob[u * 2 + 1] += prob[u];
    tree[u * 2 + 1] += prob[u]*(r-mid);
    prob[u] = 0;
}

void update(int u, int l, int r, int i, int j, int val) {
    if (r < i || l > j) return;
    if (l >= i && r <= j) {
        prob[u] += val; tree[u] += val;  return;
    }
    propagate(u,l,r);int mid = (l + r) / 2;
    update(u * 2, l, mid, i, j, val);
    update(u * 2 + 1, mid + 1, r, i, j, val);
    tree[u] = tree[u * 2]+ tree[u * 2 + 1];
}

LL query(int u, int l, int r, int i, int j) {
    if (l > j || r < i) return 0;
    if (l >= i && r <= j) return tree[u];
    propagate(u,l,r);   int mid = (l + r) / 2;
    return (query(u * 2, l, mid, i, j)+ query(u * 2 + 1, mid + 1, r, i, j));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while(t--) {
        cout<<"Case "<<++cs<<":"<<endl;
        string s;   cin >> s;
        int n = s.size();

        for(int i=0; i<n; i++) a[i] = 0;
        for(int i=0; i<=4*n; i++) tree[i] = prob[i] = 0;

        int q;
        cin >> q;

        while(q--) {
            char ch;
            cin >> ch;
            if(ch=='I') {
                int l, r; cin >> l >> r;
                l--, r--;
                update(1,0,n-1,l,r,1);
            }
            else {
                int x;  cin >> x; x--;
                int res = query(1,0,n-1,x,x);
                if(res&1) cout<<(s[x]=='0'?1:0)<<endl;
                else cout<<(s[x]=='0'?0:1)<<endl;
            }
        }

    }
}
