#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 n, k; cin >> n >> k;
    vector<i64> A (n); rep(i, 0, n) cin >> A[i];
    sort(all(A));
    i64 l = -1, r = 2e9 + 1;
    while(r - l > 1){
        i64 m = l + (r - l)/2;
        i64 sum = accumulate(n/2 + all(A), 0LL, [&] (i64 s, i64 t) {
            return s + min(t, m);
        });
        if ((n + 1)/2*m - sum <= k){ //Lleq BS
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
    return 0;
}
