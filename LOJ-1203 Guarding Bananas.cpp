#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
 
typedef double Tf;
typedef double Ti;            /// use long long for exactness
const Tf PI = acos(-1), EPS = 1e-9;
int dcmp(Tf x) { return abs(x) < EPS ? 0 : (x<0 ? -1 : 1);}
 
struct Point {
    Ti x, y;
    Point(Ti x = 0, Ti y = 0) : x(x), y(y) {}
 
    Point operator + (const Point& u) const { return Point(x + u.x, y + u.y); }
    Point operator - (const Point& u) const { return Point(x - u.x, y - u.y); }
    Point operator * (const long long u) const { return Point(x * u, y * u); }
    Point operator * (const Tf u) const { return Point(x * u, y * u); }
    Point operator / (const Tf u) const { return Point(x / u, y / u); }
 
    bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const Point& u) const { return !(*this == u); }
    bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x - u.x) == 0 && dcmp(y - u.y) < 0); }
    friend istream &operator >> (istream &is, Point &p) { return is >> p.x >> p.y; }
    friend ostream &operator << (ostream &os, const Point &p) { return os << p.x << " " << p.y; }
};
 
Ti dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
Ti cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
Tf length(Point a) { return sqrt(dot(a, a)); }
Ti sqLength(Point a) { return dot(a, a); }
Tf distance(Point a, Point b) {return length(a-b);}
Tf angle(Point u) { return atan2(u.y, u.x); }

// returns angle between oa, ob in (-PI, PI]
Tf angleBetween(Point a, Point b) {
    Tf ans = angle(b) - angle(a);
    return ans <= -PI ? ans + 2*PI : (ans > PI ? ans - 2*PI : ans);
}

using Polygon = vector<Point>;

Polygon convexHull(Polygon p, bool removeRedundant) {
    int check = removeRedundant ? 0 : -1;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    Polygon ch(n+n);
    int m = 0;      // preparing lower hull
    for(int i = 0; i < n; i++) {
        while(m > 1 && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= check) m--;
        ch[m++] = p[i];
    }
    int k = m;      // preparing upper hull
    for(int i = n - 2; i >= 0; i--) {
        while(m > k && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= check) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    return ch;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout <<"Case "<<++cs<<": ";
        int n;
        cin >> n;

        vector<Point> p(n);
        for(int i=0; i<n; i++) cin >> p[i];

        auto hull = convexHull(p, 1);
        n = hull.size();

        if(n<=2){
            cout << "0\n";
            continue;
        }
        for(int i=0; i<n; i++) hull.push_back(hull[i]);

        double ans = 1e9;
        for(int i=1; i<hull.size()-1; i++){
            Point a = hull[i-1] - hull[i];
            Point b = hull[i+1] - hull[i];
            ans = min(ans, abs(angleBetween(a, b)));
        }
        cout << fixed<< setprecision(8)<<ans*180/acos(-1) <<"\n";
    }
}

