#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
template<typename T>
struct Matrix {
    int size;
    vector<vector<T>> mat;

    Matrix(int k) : size(k), mat(k, vector<T>(k, 0)) {}

    static Matrix<T> identity(int k) {
        Matrix<T> I(k);
        for(int i = 0; i < k; ++i) {
            I.mat[i][i] = 1;
        }
        return I;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if(size != other.size) {
            throw invalid_argument("Matrix sizes do not match for multiplication.");
        }
        Matrix<T> result(size);
        for(int i = 0; i < size; ++i) {
            for(int k = 0; k < size; ++k) {
                if(mat[i][k] == 0) continue;
                for(int j = 0; j < size; ++j) {
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
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
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
    i64 n; cin >> n;
    double p; cin >> p;
    Matrix<double> m (2);
    m.mat[0][0] = 1 - p;
    m.mat[0][1] = p;
    m.mat[1][0] = p;
    m.mat[1][1] = 1 - p;
    m = power(m, n);
    cout << setprecision(10) << fixed << m.mat[0][0] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
