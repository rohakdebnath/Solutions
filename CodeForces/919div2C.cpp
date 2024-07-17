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
    i64 N; cin >> N;
    VI A (N); 
    rep(i, 0, N){
        cin >> A[i];
    }
    
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    init();
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
