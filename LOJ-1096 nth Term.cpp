#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int M = 10007;
int a, b, n, c;

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

        cin >> n >> a >> b >> c;

        if (n <= 2) {
            cout << 0 << "\n";
            continue;
        }

        Matrix base(4, 4);

        base.mat[0][0] = 1;
        base.mat[1][2] = 1;
        base.mat[2][3] = 1;
        base.mat[3][1] = b;
        base.mat[3][3] = a;
        base.mat[3][0] = 1;

        base = power(base, n - 2);

        cout << (base.mat[3][0] * c) % M << "\n";
    }
}

