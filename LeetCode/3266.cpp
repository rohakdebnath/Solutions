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

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n = nums.size();
        multiset<pair<i64, int>> a;
        for (int i = 0; i < n; ++i) a.insert({nums[i], i});

        while (m != 1) {
            i64 x = a.begin() ->first * m;
            i64 y = prev(a.end()) ->first;
            int id = a.begin() ->second;
            if (x >= y or k == 0) break;
            a.erase(a.begin());
            a.insert({x, id});
            --k;
        }
        vector<pair<mi, int>> ans;
        for (auto x: a) ans.push_back(x);

        for (int i = 0; i < n; ++i) {
            ans[i].first *= pw(m, k / n + (i < k % n));
        }
        vector<int> fin (n);
        for (auto[u, v]: ans) {
            fin[v] = int(u);
        }
        return fin;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution s; 
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    int k, m; cin >> k >> m;
    a = s.getFinalState(a, k, m);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}
