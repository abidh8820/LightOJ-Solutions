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

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout <<"Case "<<++cs<<": ";
        int n;
        cin >> n;

        vector<Point> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        map<PII, int> cnt[n];
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==i) continue;
                auto[x1, y1] = v[i]; auto[x2, y2] = v[j];
                int dx = x2-x1, dy = y2-y1;

                int g = gcd(abs(dx), abs(dy));
                dx /= g, dy /= g;

                if(dy<0) dx *= -1, dy *= -1;
                if(dx==0) dy = 1;
                if(dy==0) dx = 1;

                cnt[i][PII(dx, dy)]++;
                ans = max(ans, cnt[i][PII(dx, dy)]);
            }
        }

        cout << ans+1 <<"\n";

    }
}

