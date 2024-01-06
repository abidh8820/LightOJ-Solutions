#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    map<string, bool> mp;
    for (auto x : s) mp[x] = true;

    for (auto x : s) {
        cout<<"Case "<<++cs<<": ";
        if (x[4] == 's') {
            cout << x << endl;
        } else {
            x.insert(4, "s");
            cout << x<<endl;
        }
    }
}

