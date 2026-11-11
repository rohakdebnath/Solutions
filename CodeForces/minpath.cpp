#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 inf = 3e18;

template<typename T>
struct Matrix {
    i64 size;
    vector<vector<T>> mat;

    Matrix(i64 k) : size(k), mat(k, vector<T>(k, inf)) {}

    static Matrix<T> identity(i64 k) {
        Matrix<T> I(k);
        for(i64 i = 0; i < k; ++i) {
            I.mat[i][i] = 0;
        }
        return I;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if(size != other.size) {
            throw invalid_argument("Matrix sizes do not match for multiplication.");
        }
        Matrix<T> result(size);
        for(i64 i = 0; i < size; ++i) {
            for(i64 j = 0; j < size; ++j) {
                for(i64 k = 0; k < size; ++k) {
                    if(mat[i][k] == inf or other.mat[k][j] == inf) continue;
                    result.mat[i][j] = min(result.mat[i][j], mat[i][k] + other.mat[k][j]);
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
        i64 u, v, c; cin >> u >> v >> c;
        --u, --v;
        M.mat[u][v] = c; 
    }

    M = power(M, k);
    i64 ans = inf;
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < n; ++j) {
            ans = min(ans, M.mat[i][j]);
        }
    }
    if (ans == inf) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
