#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int M;

struct Matrix {
    int n, m;
    vector<vector<int>> mat;

    Matrix(int n = 0, int m = 0) : n(n), m(m) {
        mat.resize(n, vector<int>(m, 0));
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
                    ans[i][j] = (ans[i][j] + 1LL * mat[i][k] * b.mat[k][j]) % M;
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
        cout << "Case " << ++cs << ":\n";
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;

        int a2, b2, c2;
        cin >> a2 >> b2 >> c2;

        int f0, f1, f2;
        cin >> f0 >> f1 >> f2;

        int g0, g1, g2;
        cin >> g0 >> g1 >> g2;

        cin >> M;

        int q;
        cin >> q;

        while (q--) {
            int n;
            cin >> n;

            if (n <= 2) {
                if (n == 0) cout << f0%M << " " << g0%M << "\n";
                if (n == 1) cout << f1%M << " " << g1%M << "\n";
                if (n == 2) cout << f2%M << " " << g2%M << "\n";
                continue;
            }

            Matrix transform(6, 6);
            Matrix base(6, 1);
            base.mat[0][0] = f2;
            base.mat[1][0] = f1;
            base.mat[2][0] = f0;
            base.mat[3][0] = g2;
            base.mat[4][0] = g1;
            base.mat[5][0] = g0;

            transform.mat[0][0] = a1;
            transform.mat[0][1] = b1;
            transform.mat[0][5] = c1;
            transform.mat[1][0] = 1;
            transform.mat[2][1] = 1;
            transform.mat[3][2] = c2;
            transform.mat[3][3] = a2;
            transform.mat[3][4] = b2;
            transform.mat[4][3] = 1;
            transform.mat[5][4] = 1;

            transform = power(transform, n - 2);
            Matrix res = transform * base;
            cout << res.mat[0][0] << " " << res.mat[3][0] << "\n";
        }
    }
}

