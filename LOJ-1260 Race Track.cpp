using namespace std;
#include <bits/stdc++.h>
using namespace std;

using LL = long long;

typedef double Tf;
typedef double Ti;  /// use long long for exactness
const Tf PI = acos(-1), EPS = 1e-9;
int dcmp(Tf x) { return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1); }

int MX = 1e5;
struct Point {
    Ti x, y;
    Point(Ti x = 0, Ti y = 0) : x(x), y(y) {}

    Point operator+(const Point &u) const { return Point(x + u.x, y + u.y); }
    Point operator-(const Point &u) const { return Point(x - u.x, y - u.y); }
    Point operator*(const long long u) const { return Point(x * u, y * u); }
    Point operator*(const Tf u) const { return Point(x * u, y * u); }
    Point operator/(const Tf u) const { return Point(x / u, y / u); }

    bool operator==(const Point &u) const {
        return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;
    }

    bool operator!=(const Point &u) const { return !(*this == u); }
    bool operator<(const Point &u) const {
        return dcmp(x - u.x) < 0 || (dcmp(x - u.x) == 0 && dcmp(y - u.y) < 0);
    }
    friend istream &operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Point &p) {
        return os << p.x << " " << p.y;
    }
};

Ti dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
Ti cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
Tf length(Point a) { return sqrt(dot(a, a)); }
Ti sqLength(Point a) { return dot(a, a); }
Tf distance(Point a, Point b) { return length(a - b); }
Tf angle(Point u) { return atan2(u.y, u.x); }

using Polygon = vector<Point>;

Polygon convexHull(Polygon p, bool removeRedundant) {
    int check = removeRedundant ? 0 : -1;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    Polygon ch(n + n);
    int m = 0;  // preparing lower hull
    for (int i = 0; i < n; i++) {
        while (m > 1 &&
               dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= check)
            m--;
        ch[m++] = p[i];
    }
    int k = m;  // preparing upper hull
    for (int i = n - 2; i >= 0; i--) {
        while (m > k &&
               dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= check)
            m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    ch.resize(m);
    return ch;
}

const int R = 105;
int cnt[R][R];

// returns angle between oa, ob in (-PI, PI]
Tf angleBetween(Point a, Point b) {
    Tf ans = angle(b) - angle(a);
    return ans <= -PI ? ans + 2 * PI : (ans > PI ? ans - 2 * PI : ans);
}

struct Segment {
    Point a, b;
    Segment(Point aa, Point bb) : a(aa), b(bb) {}
};
typedef Segment Line;

bool onSegment(Point p, Segment s) {
    return dcmp(cross(s.a - p, s.b - p)) == 0 &&
           dcmp(dot(s.a - p, s.b - p)) <= 0;
}


Tf distancePointSegment(Point p, Segment s) {
    if (s.a == s.b) return length(p - s.a);
    Point v1 = s.b - s.a, v2 = p - s.a, v3 = p - s.b;
    if (dcmp(dot(v1, v2)) < 0) return length(v2);
    else if (dcmp(dot(v1, v3)) > 0) return length(v3);
    else return abs(cross(v1, v2) / length(v1));
}
bool segmentsIntersect(Segment p, Segment q) {
    if (onSegment(p.a, q) || onSegment(p.b, q)) return true;
    if (onSegment(q.a, p) || onSegment(q.b, p)) return true;

    Ti c1 = cross(p.b - p.a, q.a - p.a);
    Ti c2 = cross(p.b - p.a, q.b - p.a);
    Ti c3 = cross(q.b - q.a, p.a - q.a);
    Ti c4 = cross(q.b - q.a, p.b - q.a);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

Tf distanceSegmentSegment(Segment p, Segment q) {
    if (segmentsIntersect(p, q)) return 0;
    Tf ans = distancePointSegment(p.a, q);
    ans = min(ans, distancePointSegment(p.b, q));
    ans = min(ans, distancePointSegment(q.a, p));
    ans = min(ans, distancePointSegment(q.b, p));
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout<<"Case "<<++cs<<": ";
        Polygon p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        int m;
        cin >> m;

        Polygon q(m);
        for (int j = 0; j < m; j++) cin >> q[j];

        double ans = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Point a = p[i], b = p[(i + 1) % n];
                Point c = q[j], d = q[(j + 1) % m];
                Segment ab(a, b);
                Segment cd(c, d);
                ans = min(ans, distanceSegmentSegment(ab, cd));
            }
        }

        cout << fixed << setprecision(10) << ans/2 << endl;
    }
}

