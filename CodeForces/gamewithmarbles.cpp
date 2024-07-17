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
    i64 n; cin >> n;
    VI A(n), B(n);
    rep(i, 0, n)
    {
        i64 a; cin >> a;
        A[i] = a - 1;
    }
    rep(i, 0, n)
    {
        i64 a; cin >> a;
        B[i] = a - 1;
    }
    VI s (n);
    rep(i, 0, n) s[i] = A[i] + B[i];

    VI preidx (n);
    iota(all(preidx), 0);
    sort(all(preidx), [&s] (i64 i, i64 j){
        return s[i] > s[j];
    });
    VI newA (n), newB (n);
    rep(i, 0, n)
    {
        newA[i] = A[preidx[i]];
        newB[i] = B[preidx[i]];
    }
    i64 Alice = 0, Bob = 0;
    for(i64 i = 0; i < n; i += 2) Alice += newA[i];
    for(i64 i = 1; i < n; i += 2) Bob += newB[i];
    cout << Alice - Bob << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
