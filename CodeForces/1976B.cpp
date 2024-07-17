#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> B (N + 1); rep(i, 0, N + 1) cin >> B[i];
    i64 ans = 0;
    i64 closest = A[0];
    rep(i, 0, N){
        i64 x = A[i], y = B[i];
        if (x > y) swap(x, y);
        ans += (y - x);
        if (B[N] <= y and B[N] >= x) closest = B[N];
        else {
            if (B[N] < x and abs(B[N] - closest) > (x - B[N])) closest = x;
            else if (B[N] > y and abs(B[N] - closest) > (B[N] - y)) closest = y;
        }
    }
    ans += abs(B[N] - closest) + 1;
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
