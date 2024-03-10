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

typedef vector<int> VI;

/// Equivalence Class INFO
vector<VI> c;
VI sort_cyclic_shifts(const string& s) {
  int n = s.size();
  const int alphabet = 256;
  VI p(n), cnt(alphabet, 0);

  c.clear();
  c.emplace_back();
  c[0].resize(n);

  for (int i = 0; i < n; i++) cnt[s[i]]++;
  for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;

  c[0][p[0]] = 0;
  int classes = 1;

  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) classes++;
    c[0][p[i]] = classes - 1;
  }

  VI pn(n), cn(n);
  cnt.resize(n);

  for (int h = 0; (1 << h) < n; h++) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.end(), 0);

    /// radix sort
    for (int i = 0; i < n; i++) cnt[c[h][pn[i]]]++;
    for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) p[--cnt[c[h][pn[i]]]] = pn[i];

    cn[p[0]] = 0;
    classes = 1;

    for (int i = 1; i < n; i++) {
      PII cur = {c[h][p[i]], c[h][(p[i] + (1 << h)) % n]};
      PII prev = {c[h][p[i - 1]], c[h][(p[i - 1] + (1 << h)) % n]};
      if (cur != prev) ++classes;
      cn[p[i]] = classes - 1;
    }
    c.push_back(cn);
  }
  return p;
}

VI suffix_array_construction(string s) {
  s += "!";
  VI sorted_shifts = sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}

/// LCP between the ith and jth (i != j) suffix of the STRING
int suffixLCP(int i, int j) {
  assert(i != j);
  int log_n = c.size() - 1;

  int ans = 0;
  for (int k = log_n; k >= 0; k--) {
    if (c[k][i] == c[k][j]) {
      ans += 1 << k;
      i += 1 << k;
      j += 1 << k;
    }
  }
  return ans;
}

// lcp[i] = lcp(i,i+1) in sorted order
VI lcp_construction(const string& s, const VI& sa) {
  int n = s.size();
  VI rank(n, 0);
  VI lcp(n - 1, 0);

  for (int i = 0; i < n; i++) rank[sa[i]] = i;

  for (int i = 0, k = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }

    int j = sa[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }
  return lcp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  hashPre();
  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    string a, b;
    cin >> a >> b;

    auto hashlist = hashList(a);
    vector<int> ends;

    auto hashb = Hash(b);
    int len = b.size(), n = a.size();

    for (int i = len; i <= a.size(); i++) {
      auto curHash = substringHash(hashlist, i - len + 1, i);
      if (curHash == hashb) ends.push_back(i - 1);
    }

    ends.push_back(n * 2);
    auto sa = suffix_array_construction(a);
    auto lcp = lcp_construction(a, sa);

    LL ans = 0;
    for (int i = 0; i < n; i++) {
      int l = i ? lcp[i - 1] + sa[i] : sa[i];
      int r = (*lower_bound(ends.begin(), ends.end(), sa[i] + b.size()-1))- 1;
      r = min(r, n - 1), ans += max(0, r - l + 1);
    }

    cout << ans << "\n";
  }
}

