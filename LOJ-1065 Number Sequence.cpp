#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int a, b, n, M;

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
        cout << "Case " << ++cs << ": ";

        cin >> a >> b >> n >> M;
        M = pow(10, M);

        Matrix base(2, 2);

        base.mat[0][0] = 0;
        base.mat[0][1] = 1;
        base.mat[1][0] = 1;
        base.mat[1][1] = 1;

        base = power(base, n - 1);
        cout << (a * base.mat[1][0] % M + b * base.mat[1][1] % M) % M << "\n";
    }
}

