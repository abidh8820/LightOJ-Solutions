#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        string s;
        cin >> s;

        string ss = s;

        while (ss.size() > 1 && ss.back() == '0') ss.pop_back();
        reverse(ss.begin(), ss.end());

        cout << (ss == s ? "Yes" : "No") << "\n";
    }
}

