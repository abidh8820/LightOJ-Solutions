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

struct Circle {
    Point o;
    Tf r;
    Circle(Point o = Point(0, 0), Tf r = 0) : o(o), r(r) {}

    // returns true if point p is in || on the circle
    bool contains(Point p) { return dcmp(sqLength(p - o) - r * r) <= 0; }

    // returns a point on the circle rad radians away from +X CCW
    Point point(Tf rad) {
        static_assert(is_same<Tf, Ti>::value);
        return Point(o.x + cos(rad) * r, o.y + sin(rad) * r);
    }

    // area of a circular sector with central angle rad
    Tf area(Tf rad = PI + PI) { return rad * r * r / 2; }

    // area of the circular sector cut by a chord with central angle alpha
    Tf sector(Tf alpha) { return r * r * 0.5 * (alpha - sin(alpha)); }
};

// intersection area between two circles c1, c2
Tf circleCircleIntersectionArea(Circle c1, Circle c2) {
    Point AB = c2.o - c1.o;
    Tf d = length(AB);
    if (d >= c1.r + c2.r) return 0;
    if (d + c1.r <= c2.r) return PI * c1.r * c1.r;
    if (d + c2.r <= c1.r) return PI * c2.r * c2.r;

    Tf alpha1 = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2.0 * c1.r * d));
    Tf alpha2 = acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2.0 * c2.r * d));
    return c1.sector(2 * alpha1) + c2.sector(2 * alpha2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        Point c1, c2;
        double r1, r2;
        cin >> c1 >> r1 >> c2 >> r2;
        Circle a(c1, r1), b(c2, r2);

        cout << fixed << setprecision(10) << circleCircleIntersectionArea(a, b) << endl;
    }
}

