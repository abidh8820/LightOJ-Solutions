#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
using PLL = pair<LL, LL>;

#define ff first
#define ss second

const PLL M = {1e9 + 7, 1e9 + 9};  /// Should be large primes
const LL base = 1259;              /// Should be larger than alphabet size
const int N = 1e6 + 7;             /// Highest length of string

PLL operator+(const PLL& a, LL x) { return {a.ff + x, a.ss + x}; }
PLL operator-(const PLL& a, LL x) { return {a.ff - x, a.ss - x}; }
PLL operator*(const PLL& a, LL x) { return {a.ff * x, a.ss * x}; }
PLL operator+(const PLL& a, PLL x) { return {a.ff + x.ff, a.ss + x.ss}; }
PLL operator-(const PLL& a, PLL x) { return {a.ff - x.ff, a.ss - x.ss}; }
PLL operator*(const PLL& a, PLL x) { return {a.ff * x.ff, a.ss * x.ss}; }
PLL operator%(const PLL& a, PLL m) { return {a.ff % m.ff, a.ss % m.ss}; }
ostream& operator<<(ostream& os, PLL hash) { return os << "(" << hash.ff << ", " << hash.ss << ")"; }
PLL pb[N];  /// powers of base mod M

/// Call pre before everything
void hashPre() {
  pb[0] = {1, 1};
  for (int i = 1; i < N; i++) pb[i] = (pb[i - 1] * base) % M;
}

/// Calculates hashes of all prefixes of s including empty prefix
vector<PLL> hashList(string s) {
  int n = s.size();
  vector<PLL> ans(n + 1);
  ans[0] = {0, 0};
  for (int i = 1; i <= n; i++) ans[i] = (ans[i - 1] * base + s[i - 1]) % M;
  return ans;
}

/// Calculates hash of substring s[l..r] (1 indexed)
PLL substringHash(const vector<PLL>& hashlist, int l, int r) {
  return (hashlist[r] + (M - hashlist[l - 1]) * pb[r - l + 1]) % M;
}

/// Calculates Hash of a string
PLL Hash(string s) {
  PLL ans = {0, 0};
  for (int i = 0; i < s.size(); i++) ans = (ans * base + s[i]) % M;
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  hashPre();
  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    auto hashlist1 = hashList(s1);
    auto hashlist2 = hashList(s2);
    auto hashlist3 = hashList(s3);

    auto check = [&](int len) {
      map<PLL, bool> mp1, mp2;
      for (int i = len; i <= s1.size(); i++)
        mp1[substringHash(hashlist1, i - len + 1, i)] = true;

      for (int i = len; i <= s2.size(); i++)
        mp2[substringHash(hashlist2, i - len + 1, i)] = true;

      for (int i = len; i <= s3.size(); i++) {
        auto curHash = substringHash(hashlist3, i - len + 1, i);
        if (mp1[curHash] && mp2[curHash]) return true;
      }
      return false;
    };

    int lo = 0, hi = min({s1.size(), s2.size(), s3.size()}), ans = 0;
    while (lo <= hi) {
      int mid = lo + hi >> 1;
      if (check(mid)) ans = mid, lo = mid + 1;
      else hi = mid - 1;
    }

    cout << ans << "\n";
  }
}

