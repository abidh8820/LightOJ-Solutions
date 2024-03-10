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

using Polygon = vector<Point>;
// returns the signed area of polygon p of n vertices
Tf signedPolygonArea(const Polygon &p) {
    Tf ret = 0;
    for(int i = 0; i < (int) p.size() - 1; i++)
        ret += cross(p[i]-p[0],  p[i+1]-p[0]);
    return ret / 2;
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

        vector<Point> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        double area = abs(signedPolygonArea(v));
        v.push_back(v[0]);
       
        LL boundary = 0;
        for(int i=0; i<n; i++){
            auto[x1, y1] = v[i]; auto[x2, y2] = v[i+1];
            LL dx = abs(x2-x1), dy = abs(y2-y1);
            LL g = gcd(dx, dy); dx /= g, dy /= g;
            if(dx)boundary += abs((x2-x1)/dx);
            else boundary += abs((y2-y1)/dy);
        }
    
        LL inside = (2*area - boundary+2)/2;
        cout << inside <<"\n";
    }
}

