#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    i64 n, f, a, b; cin >> n >> f >> a >> b;
    VI A (n); rep(i, 0, n) cin >> A[i];
    VI waits (n); waits[0] = A[0];
    rep(i, 1, n){
        waits[i] = A[i] - A[i - 1];
    }
    i64 sum = 0;
    rep(i, 0, n){
        sum += min(b, waits[i]*a);
    }
    cout << (sum < f ? "YES\n": "NO\n");
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
