#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
template<typename T>
struct Matrix {
    i64 size;
    vector<vector<T>> mat;

    Matrix(i64 k) : size(k), mat(k, vector<T>(k, 0)) {}

    static Matrix<T> identity(i64 k) {
        Matrix<T> I(k);
        for(i64 i = 0; i < k; ++i) {
            I.mat[i][i] = 1;
        }
        return I;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if(size != other.size) {
            throw invalid_argument("Matrix sizes do not match for multiplication.");
        }
        Matrix<T> result(size);
        for(i64 i = 0; i < size; ++i) {
            for(i64 k = 0; k < size; ++k) {
                if(mat[i][k] == 0) continue;
                for(i64 j = 0; j < size; ++j) {
                    if constexpr (is_integral<T>::value) {
                        result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % mod;
                    } else {
                        result.mat[i][j] += mat[i][k] * other.mat[k][j];
                    }
                }
            }
        }
        return result;
    }

    void print() const {
        for(i64 i = 0; i < size; ++i) {
            for(i64 j = 0; j < size; ++j) {
                if constexpr (is_floating_point<T>::value) {
                    cout << fixed << setprecision(6) << mat[i][j] << ' ';
                } else {
                    cout << mat[i][j] << ' ';
                }
            }
            cout << '\n';
        }
    }
};

template<typename T>
Matrix<T> power(Matrix<T> base, i64 exponent) {
    Matrix<T> result = Matrix<T>::identity(base.size);
    while(exponent > 0) {
        if(exponent & 1) {
            result = result * base;
        }
        base = base * base;
        exponent >>= 1;
    }
    return result;
}

void solve() {
    i64 n, m, k; cin >> n >> m >> k;
    Matrix<i64> M (n);
    while (m--) {
        i64 u, v; cin >> u >> v;
        --u, --v;
        M.mat[v][u] = 1;
    }
    M = power(M, k);
    i64 ans = 0;
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < n; ++j) {
            ans = (ans + M.mat[i][j]) % mod;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
