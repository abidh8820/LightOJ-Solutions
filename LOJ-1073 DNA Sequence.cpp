#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9;

void buildPi(string &p, vector<int> &pi) {
    pi.resize(p.size());
    int k = -2;
    for (int i = 0; i < p.size(); ++i) {
        while (k >= -1 and p[k + 1] != p[i]) k = k == -1 ? -2 : pi[k];
        pi[i] = ++k;
    }
}

bool KMP(string &t, string &p) {
    vector<int> pi;
    buildPi(p, pi);
    int k = -1;
    for (int i = 0; i < t.size(); ++i) {
        while (k >= -1 and p[k + 1] != t[i]) k = k == -1 ? -2 : pi[k];
        ++k;
        if (k == p.size() - 1) return true;
    }
    return false;
}

vector<vector<int>> lps;
int match(int i, int j) { return lps[i][j] + 1; }

void pre(vector<string> s) {
    int n = s.size();
    lps.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            string temp = s[j] + '#' + s[i];
            vector<int> pi;
            buildPi(temp, pi);
            lps[i][j] = pi.back();
        }
    }
}

int dp[17][1 << 16];

int call(int last, int mask, int n, const vector<string> &s) {
    if (__builtin_popcount(mask) == n) return 0;
    int &ret = dp[last][mask];

    if (~ret) return ret; ret = INF;

    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) continue;
        int len = match(last, i);
        ret = min(ret, int(s[i].size() - len + call(i, mask | (1 << i), n, s)));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n; cin >> n;

        memset(dp, -1, sizeof dp);
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        vector<bool> good(n, true);
        sort(s.begin(), s.end(), [&](auto x, auto y) { return x.size() < y.size(); });

        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                if (KMP(s[j], s[i])) { good[i] = false; break; }

        vector<string> rem;
        for (int i = 0; i < n; i++)
            if (good[i]) rem.push_back(s[i]);

        s = rem, n = s.size(), pre(s);
        int res = INF, best = 0;

        vector<int> cand;
        for (int i = 0; i < n; i++) {
            int now = call(i, 1 << i, n, s) + s[i].size();
            if (now == res) cand.push_back(i);
            if (now < res) res = now, cand.clear(), cand.push_back(i);
        }

        sort(cand.begin(), cand.end(),
             [&](int x, int y) { return s[x] < s[y]; });

        string ans = s[cand[0]];
        int last = cand[0], mask = (1 << last);

        while (__builtin_popcount(mask) < n) {
            vector<pair<string, int>> candp;
            res = INF;

            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                string rem = "";
                int len = match(last, i);
                for (int j = len; j < s[i].size(); j++) rem += s[i][j];
                int now = call(i, mask | (1 << i), n, s) + rem.size();

                if (res == now) candp.emplace_back(rem, i);
                if (now < res) candp.clear(), res = now, candp.emplace_back(rem, i);
            }

            assert(candp.size());
            sort(candp.begin(), candp.end());
            last = candp[0].second, ans += candp[0].first, mask |= (1 << last);
        }

        cout << ans << "\n";
    }
}

