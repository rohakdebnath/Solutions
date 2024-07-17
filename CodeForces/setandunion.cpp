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
    int N; cin >> N;

    i64 OR = 0;
    VI A (N);
    rep(i, 0, N){
        int M; cin >> M;
        while(M--){
            int k; cin >> k;
            A[i] |= (1LL << k);
        }
        OR |= A[i];
    }
    int ans = 0;
    rep(i, 1, 51){
        if (OR >> i & 1){
            i64 t = 0;
            rep(j, 0, N){
                if (~A[j] >> i & 1){
                    t |= A[j];
                }
            }
            ans = max(ans, __builtin_popcountll(t));
        } 
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
