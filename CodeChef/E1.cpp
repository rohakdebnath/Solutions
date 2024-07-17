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

i64 S; 
void solve()
{
    i64 N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));
    if (S == 0)
    {
        i64 ans = 0;
        if (N % 2) rep(i, 0, N/2 + 1) ans += A[i];
        else rep(i, 1, N/2 + 1) ans += A[i];
        cout << ans << '\n';
    }
    else
    {
        VI pref (N + 1);
        rep(i, 1, N + 1) pref[i] = pref[i - 1] + A[i - 1];
        i64 ans = 0;
        i64 len = 1;
        i64 ptre = N;
        i64 ptrb = ptre - len;
        while (ptrb >= 0)
        {
            ans = max(ans, pref[ptre] - pref[ptrb]);
            ++len;
            --ptre;
            ptrb = ptre - len;
        }
        cout << ans << '\n';
    }
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    cin >> S;
    while(T--) solve();
    return 0;
}
