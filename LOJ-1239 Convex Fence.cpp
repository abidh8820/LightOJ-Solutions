#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

typedef double Tf;
typedef double Ti;            
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

Tf signedPolygonArea(const Polygon &p) {
    Tf ret = 0;
    for(int i = 0; i < (int) p.size() - 1; i++)
        ret += cross(p[i]-p[0],  p[i+1]-p[0]);
    return ret / 2;
}

Polygon convexHull(Polygon p, bool removeRedundant) {
    int check = removeRedundant ? 0 : -1;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    Polygon ch(n+n);
    int m = 0;     
    for(int i = 0; i < n; i++) {
        while(m > 1 && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= check) m--;
        ch[m++] = p[i];
    }
    int k = m;    
    for(int i = n - 2; i >= 0; i--) {
        while(m > k && dcmp(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= check) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    return ch;
}

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout <<"Case "<<++cs<<": ";
        int n, d;
        cin >> n >> d;

        vector<Point> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        Polygon p = convexHull(v,1);

        p.push_back(p[0]);

        double perim = 0;
        for(int i=1; i<p.size(); i++)
            perim += distance(p[i], p[i-1]);

        perim += 2.0*acos(-1)*d;
        cout<<fixed<<setprecision(10)<<perim<<"\n";
    }
}

