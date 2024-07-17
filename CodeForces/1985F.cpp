#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 N, H;
vector<i64> A, C; 
bool check(i64 m){ //can the monster be killed till move m
    i64 t = H;
    rep(i, 0, N){
        t -= ((m - 1) / C[i] + 1) * A[i];
        if (t <= 0) break;
    }
    return t <= 0;
}
void solve()
{
    cin >> H >> N; A.resize(N), C.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> C[i];

    i64 l = 0, r = 50000000000LL;

    while(r - l > 1){
        i64 m = l + (r - l) / 2;
        if (check(m)){
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
