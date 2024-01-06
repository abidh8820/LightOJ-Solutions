#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    cin.ignore();
    while (t--) {

        cout <<"Case "<<++cs<<": ";
        string a, b;
        getline(cin, a);
        getline(cin, b);

        multiset<char> aa, bb;

        for (char x : a) if (x != ' ') aa.insert(tolower(x));
        for (char x : b) if (x != ' ') bb.insert(tolower(x));

        if (aa == bb) cout << "Yes\n";
        else cout << "No\n";
    }
}

