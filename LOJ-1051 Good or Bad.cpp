#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool vis[55][7][7][7][7];
bool good, bad;

set<char> vowel = {'A', 'E', 'I', 'O', 'U'};
string s;

void call(int pos, int vcnt, int ccnt, int mxv, int mxc) {
    vcnt = min(vcnt, 3), mxv = min(mxv, 3);
    ccnt = min(ccnt, 5), mxc = min(mxc, 5);

    if (pos == s.size()) {
        if (mxv < 3 && mxc < 5) good = true;
        if (mxv >= 3 || mxc >= 5) bad = true;
        return;
    }

    if (vis[pos][vcnt][ccnt][mxv][mxc]) return;

    if (s[pos] == '?' || vowel.count(s[pos])) call(pos + 1, vcnt + 1, 0, max(mxv, vcnt + 1), mxc);
    if (s[pos] == '?' || !vowel.count(s[pos])) call(pos + 1, 0, ccnt + 1, mxv, max(mxc, ccnt + 1));
    vis[pos][vcnt][ccnt][mxv][mxc] = true;
}

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> s;

        good = false, bad = false;
        memset(vis, 0, sizeof vis);
        call(0, 0, 0, 0, 0);

        if (good && bad) cout << "MIXED\n";
        else if (good) cout << "GOOD\n";
        else cout << "BAD\n";
    }
}

