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
    VI A (N); rep(i, 0, N) cin >> A[i];
    int msum = A[0];
    int cur = max(0LL, A[0]);
    rep(i, 1, N){
        if ((A[i] ^ A[i - 1]) & 1){
            cur += A[i];
            msum = max(msum, cur);
            cur = max(0, cur);
        } else {
            cur = A[i];
            msum = max(msum, cur);
            cur = max(0, cur);
        }
    }
    cout << msum << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
