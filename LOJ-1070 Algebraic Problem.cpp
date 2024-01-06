#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using ULL = unsigned long long;

struct Matrix {
    int n, m;
    vector<vector<ULL>> mat;

    Matrix(int n = 0, int m = 0) : n(n), m(m) {
        mat.resize(n, vector<ULL>(m, 0));
    }

    void unity() {
        for (int i = 0; i < n; i++) mat[i][i] = 1;
    }

    Matrix operator*(const Matrix& b) const {
        Matrix ret(n, b.m);
        auto& ans = ret.mat;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++)
                    ans[i][j] = (ans[i][j] + 1LL * mat[i][k] * b.mat[k][j]);
        return ret;
    }
};

Matrix power(Matrix a, LL b) {
    Matrix ret(a.n, a.n);
    ret.unity();

    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        ULL p, q, n;
        cin >> p >> q >> n;

        Matrix base(2, 2);
        base.mat[0][0] = 0;
        base.mat[0][1] = 1;
        base.mat[1][0] = -q;
        base.mat[1][1] = p;

        if (n == 0) {
            cout << 2 << endl;
            continue;
        }

        if(n==1){
            cout << p <<endl;
            continue;
        }

        base = power(base, n - 1);
        cout << (base.mat[1][0] << 1) + (base.mat[1][1] * p) << "\n";
    }
}

