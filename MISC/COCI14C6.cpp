#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr i64 MOD = 1'000'000'000LL;

i64 dnc(const vector<int> &a, int l, int r)
{
    if (r - l == 1)
    {
        return (i64)a[l] * a[l] % MOD;
    }

    const int m = (l + r) >> 1;
    i64 ans = (dnc(a, l, m) + dnc(a, m, r)) % MOD;

    const int L = m - l, R = r - m;
    vector<int> lmin(L), lmax(L), rmin(R), rmax(R);

    lmin[0] = lmax[0] = a[m - 1];
    for (int i = 1; i < L; ++i)
    {
        int v = a[m - 1 - i];
        lmin[i] = min(lmin[i - 1], v);
        lmax[i] = max(lmax[i - 1], v);
    }
    rmin[0] = rmax[0] = a[m];
    for (int j = 1; j < R; ++j)
    {
        int v = a[m + j];
        rmin[j] = min(rmin[j - 1], v);
        rmax[j] = max(rmax[j - 1], v);
    }

    // Case 1: min on left, max on right
    {
        int j_lo = 0, j_hi = 0;
        for (int i = 0; i < L; ++i)
        {
            while (j_lo < R && rmin[j_lo] >= lmin[i])
                ++j_lo;
            while (j_hi < R && rmax[j_hi] <= lmax[i])
                ++j_hi;
            for (int j = j_hi; j < j_lo; ++j)
            {
                i64 len = (i + 1LL) + (j + 1LL);
                ans = (ans + (i64)lmin[i] * rmax[j] % MOD * len) % MOD;
            }
        }
    }

    // Case 2: min on right, max on left  (corrected)
    {
    int pmax = 0, pmin = 0;
    for (int i = 0; i < L; ++i) {
        // max on left: right‑max must be strictly less
        while (pmax < R && rmax[pmax] < lmax[i])
            ++pmax;
        // min on right: right‑min must be strictly less than left‑min
        while (pmin < R && rmin[pmin] < lmin[i])
            ++pmin;

        int cnt = min(pmax, pmin);
        for (int j = 0; j < cnt; ++j) {
            i64 len = (i + 1LL) + (j + 1LL);
            ans = (ans + (i64)rmin[j] * lmax[i] % MOD * len) % MOD;
        }
    }
}

    // Case 3: both min & max on right
    {
        int pref_limit = -1;
        for (int j = 0; j < R; ++j)
        {
            while (pref_limit + 1 < L &&
                   rmin[j] < lmin[pref_limit + 1] &&
                   rmax[j] >= lmax[pref_limit + 1])
            {
                ++pref_limit;
            }
            if (pref_limit >= 0)
            {
                i64 cnt = pref_limit + 1LL;
                i64 total_len =
                    ((j + 1LL) * cnt +
                     (cnt * (cnt + 1)) / 2) %
                    MOD;
                ans = (ans +
                       (i64)rmin[j] * rmax[j] % MOD * total_len) %
                      MOD;
            }
        }
    }

    // Case 4: both min & max on left
    {
        int suf_limit = 0;
        for (int i = 0; i < L; ++i)
        {
            while (suf_limit < R &&
                   rmin[suf_limit] >= lmin[i] &&
                   rmax[suf_limit] <= lmax[i])
            {
                ++suf_limit;
            }
            if (suf_limit)
            {
                i64 cnt = suf_limit;
                i64 total_len =
                    ((i + 1LL) * cnt +
                     (cnt * (cnt + 1)) / 2) %
                    MOD;
                ans = (ans +
                       (i64)lmin[i] * lmax[i] % MOD * total_len) %
                      MOD;
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; vector<int> a(n);for (int &v : a) cin >> v;

    cout << dnc(a, 0, n) % MOD << '\n';
    return 0;
}
