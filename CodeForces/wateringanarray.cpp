#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int n, k, d; cin >> n >> k >> d;
    VI a(n); rep(i, 0, n) cin >> a[i];
    VI v(k); rep(i, 0, k) cin >> v[i];
    int ans = 0;

    rep(i, 0, min(d, 2*n)){
        int ind = 0;    
        int curr = accumulate(all(a), 0, [&ind] (int s, int l) {
            ++ind;
            return s + (l == ind);
        });
        curr += (d - i - 1)/2;
        ans = max(ans, curr);
        transform(a.begin(), a.begin() + v[i % k], a.begin(), [&] (int k) {return k + 1;});
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
