#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
// #define i64 long long

void solve()
{
    i64 N; cin >> N;
    i64 ans = 1;
    while (N){
        i64 x = N % 10;
        N /= 10;
        ans *= (x + 2) * (x + 1) / 2;
    }
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
