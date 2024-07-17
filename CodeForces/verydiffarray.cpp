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

void solve()
{
    i64 n, m; cin >> n >> m;
    VI A (n), B(m); 
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, m) cin >> B[i];
    sort(all(A));
    sort(all(B), greater<i64> ());
    i64 ans = 0;
    rep(i, 0, n){
        ans += abs(A[i] - B[i]);
    }
    i64 masn = ans;
    per(j, n - 1, 0){
        ans -= abs(A[j] - B[j]);
        ans += abs(A[j] - B[j + m - n]);
        masn = max(masn, ans);
    }
    cout << masn << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
