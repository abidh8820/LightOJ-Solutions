#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

typedef double Tf;
typedef long long Ti;            
const Tf PI = acos(-1), EPS = 1e-9;
int dcmp(Tf x) { return abs(x) < EPS ? 0 : (x<0 ? -1 : 1);}
 
struct Point {
    Ti x, y, id;
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


Point pivot;
bool comp(Point a, Point b){
    LL orn  = cross(a-pivot, b-pivot);
    if(orn==0) return distance(a, pivot) < distance(b,pivot);
    return (orn < 0LL);
}

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout <<"Case "<<++cs<<":\n";

        int n;
        cin >> n;

        vector<Point> v(n);
        for(int i=0; i<n; i++) cin >> v[i], v[i].id = i;

        sort(v.begin(), v.end());
        pivot = v[0];
        sort(v.begin()+1, v.end(), comp);
        if(!cross(v[0]-v[n-1], v[0]-v[1])){
            cout <<"Impossible\n";
            continue;
        }

        int j = n-1;
        while(!cross(v[n-1]-v[0], v[j]-v[0]))j--;
        reverse(v.begin()+j+1, v.end());
         
        for(int i=0; i<n; i++) cout<<v[i].id<<" \n"[i==n-1];

    }
}

