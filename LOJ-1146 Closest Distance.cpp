#include <bits/stdc++.h>
using namespace std;
//#define static_assert(...)

typedef double Tf;
typedef double Ti;  /// use long long for exactness
const Tf PI = acos(-1), EPS = 1e-9;
int dcmp(Tf x) { return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1); }

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
        return is >> p.x >> p.y;
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

// returns angle between oa, ob in (-PI, PI]
Tf angleBetween(Point a, Point b) {
    Tf ans = angle(b) - angle(a);
    return ans <= -PI ? ans + 2 * PI : (ans > PI ? ans - 2 * PI : ans);
}

// Rotate a ccw by rad radians
Point rotate(Point a, Tf rad) {
    static_assert(is_same<Tf, Ti>::value);
    return Point(a.x * cos(rad) - a.y * sin(rad),
                 a.x * sin(rad) + a.y * cos(rad));
}

// rotate a ccw by angle th with cos(th) = co && sin(th) = si
Point rotatePrecise(Point a, Tf co, Tf si) {
    static_assert(is_same<Tf, Ti>::value);
    return Point(a.x * co - a.y * si, a.y * co + a.x * si);
}

Point rotate90(Point a) { return Point(-a.y, a.x); }

// scales vector a by s such that length of a becomes s
Point scale(Point a, Tf s) {
    static_assert(is_same<Tf, Ti>::value);
    return a / length(a) * s;
}

// returns an unit vector perpendicular to vector a
Point normal(Point a) {
    static_assert(is_same<Tf, Ti>::value);
    Tf l = length(a);
    return Point(-a.y / l, a.x / l);
}

// returns 1 if c is left of ab, 0 if on ab && -1 if right of ab
int orient(Point a, Point b, Point c) { return dcmp(cross(b - a, c - a)); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        Point a, b, c, d;
        cin >> a >> b >> c >> d;

        Point ab = b - a;
        Point cd = d - c;
        double eps = 1e-9; 
        double l = 0, r = 1.0;

        auto f = [&](double pert) {
            Point p1 = scale(ab, pert*length(ab)); 
            Point p2 = scale(cd, pert*length(cd));
            p1 = a + p1;
            p2 = c + p2;
            double ret = distance(p1,p2);
            return ret;
        };

        while (r - l > eps) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            double f1 = f(m1);
            double f2 = f(m2);
            if (f1 > f2) l = m1;
            else r = m2;
        }
        double ans = f(l);
        cout << fixed<<setprecision(10)<<ans<<"\n";
    }
}

