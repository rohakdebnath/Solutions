#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 rangexor(i64 m) {
    if(m < 0) return 0;
    if(m % 4 == 0) return m;
    if(m % 4 == 1) return 1;
    if(m % 4 == 2) return m + 1;
    return 0;
}

void solve() {
    i64 l, r, i, k; cin >> l >> r >> i >> k;
    i64 pow2i = (i == 0) ? 1LL : (1LL << i);
    i64 s = (l > k) ? ((l - k + pow2i - 1) / pow2i) : 0;
    i64 e = (r >= k) ? ((r - k) / pow2i) : -1;
    i64 rem = 0;
    if (e >= s){
        i64 S_m = rangexor(e) ^ rangexor(s - 1);
        i64 cnt = e - s + 1;
        rem = (S_m << i) ^ ((cnt % 2) ? k : 0);
    }
    i64 fin = rangexor(r) ^ rangexor(l - 1);
    cout << (fin ^ rem) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
