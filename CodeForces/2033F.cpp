#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
const i64 MAXN = 1e7;

struct mi {
    i64 v;
    explicit operator i64() const { return v; }
    mi() { v = 0; }
    mi(i64 x) : v(x % mod) { v += (v < 0) * mod; }
};

mi& operator+=(mi& a, mi b) {
    if ((a.v += b.v) >= mod) a.v -= mod;
    return a;
}

mi& operator-=(mi& a, mi b) {
    if ((a.v -= b.v) < 0) a.v += mod;
    return a;
}

mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((i64)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }

mi pw(mi a, i64 p) {
    mi res = 1;
    while (p > 0) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

mi inv(mi a) {
    return pw(a, mod - 2);
}

mi operator/(mi a, mi b) { return a * inv(b); }

vector<mi> factorial(MAXN + 1, 1);

void prefact() {
    for (i64 i = 2; i <= MAXN; ++i)
        factorial[i] = factorial[i - 1] * i;
}

mi ncr(i64 n, i64 r) {
    if (r < 0 or r > n) return 0;
    return factorial[n] * inv(factorial[r] * factorial[n - r]);
}

const i64 maxk = 1e5;

vector<mi> pisano(maxk + 1, 0);
vector<vector<i64>> pos(maxk + 1);

void run(i64 k) {
    if (i64(pisano[k]) != 0) return;

    vector<i64> tmp;
    i64 prev = 0;
    i64 curr = 1;
    i64 p = 1;

    while (p <= 6 * k) {
        i64 next = (prev + curr) % k;
        prev = curr;
        curr = next;
        p++;

        if (curr == 0) {
            tmp.push_back(p);
        }

        if (prev == 0 and curr == 1) {
            pisano[k] = p - 1;
            break;
        }
    }

    if (i64(pisano[k]) == 0) {
        pisano[k] = 6 * k;
    }

    pos[k] = tmp;
}

void solve() {
    i64 n,  k; cin >> n >> k;

    if (k == 1) {
        cout << n % mod << '\n';
        return;
    }
    run(k);
    i64 m = pos[k].size();

    if (m == 0) {
        cout << 0 << '\n';
        return;
    }

    i64 q = (n - 1) / m;
    i64 r = (n - 1) % m;

    mi index = q * pisano[k];
    index += pos[k][r];

    cout << i64(index) % mod << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T;
    while(T--) solve();
    return 0;
}
