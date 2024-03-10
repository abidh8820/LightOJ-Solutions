#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
using LL = long long;

vector<VI> c;
VI sort_cyclic_shifts(const string &s) {
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

VI lcp_construction(const string &s, const VI &sa) {
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

PII intersection(PII a, PII b) {
  if (a.first < 0) return PII(-2, -1);
  if (b.first < 0) return PII(-2, -1);
  int x = max(a.first, b.first);
  int y = min(b.second, a.second);
  if (x > y) return {-2, -1};
  return PII(x, y);
}

int len(PII a) {
  auto [x, y] = a;
  if (x < 0) return 0;
  return y - x + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";

    string s;
    cin >> s;
    int p, q;
    cin >> p >> q;

    vector<int> sa = suffix_array_construction(s);
    VI lcp = lcp_construction(s, sa);

    int n = s.size();
    LL ans = len(intersection(PII(p, q), PII(1, n - sa[0])));

    for (int i = 1; i < n; i++) {
      PII now = intersection(PII(p, q), PII(1, n - sa[i]));
      int cur = max(0, len(now) - len(intersection(now, PII(1, lcp[i - 1]))));
      ans += cur;
    }

    cout << ans << "\n";
  }
}
