//You will be given several queries of the form l, r, v and which means add v in the range [l, r], 
//you have to output the total area of segments where sum of indexes of active segments is prime. ans %= 1e9 + 7;
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;
const int maxn = 1e7;

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long x) : v(x % mod) { v += (v < 0) * mod; }
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
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }

mi pw(mi a, long long p) {
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

vector<mi> fct(maxn + 1, 1);

void prefact() {
    for (int i = 2; i <= maxn; ++i)
        fct[i] = fct[i - 1] * i;
}

mi ncr(int n, int r) {
    if (r < 0 or r > n) return 0;
    return fct[n] * inv(fct[r] * fct[n - r]);
}

const int inf = 2e5;
vector<int> lowestfactor (inf + 1);

void solve() {
    int n; cin >> n;
    vector<int> l (n), r (n), v (n);
    vector<int> sp {0};
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> v[i];
        ++r[i];
        sp.push_back(l[i]);
        sp.push_back(r[i]);
    }
    sort(sp.begin(), sp.end());
    sp.erase(unique(sp.begin(), sp.end()), sp.end());
    int m = sp.size();

    vector<mi> d (m); 
    map<int, vector<int>> start, end;

    auto cmp = [&] (int x) {
        return lower_bound(sp.begin(), sp.end(), x) - sp.begin();
    };

    for (int i = 0; i < n; ++i) {
        int x = cmp(l[i]), y = cmp(r[i]);
        d[x] += v[i];
        d[y] -= v[i];
        start[x].push_back(i);
        end[y].push_back(i);
    }
    partial_sum(d.begin(), d.end(), d.begin());

    mi ans = 0;
    int curs = 0;
    for (int i = 0; i < m - 1; ++i) {
        for (int id: start[i]) curs += id;
        for (int id: end[i]) curs -= id;

        if (lowestfactor[curs] == curs) {
            ans += (sp[i + 1] - sp[i]) * d[i];
        }
    }
    cout << int(ans) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 2; i <= inf; ++i) lowestfactor[i] = i;
    for (int i = 2; i <= inf; ++i) {
        for (int j = 2 * i; j <= inf; j += i) {
            if (lowestfactor[j] != j) continue;
            lowestfactor[j] = i;
        }
    }  
    solve();
    return 0;
}
