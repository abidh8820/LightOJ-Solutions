#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";

        int n, k;
        cin >> n >> k;

        string s = "";
        for (char i = 'A'; i < 'A' + n; i++) s += (char)i;

        do {
            cout << s << endl; k--;
        } while (next_permutation(s.begin(), s.end()) && k);
    }
}

