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
    i64 cur = (1LL << 31) - 1;
    vector<i64> vis (N);
    vector<i64> seq;
    while (seq.size() < N){
        i64 mx = 0;
        rep(i, 0, N){
            if (vis[i]) continue;
            mx = max(mx, cur & A[i]);
        }
        rep(i, 0, N){
            if (vis[i]) continue;
            if ((cur & A[i]) == mx){
                vis[i] = 1;
                seq.push_back(cur & A[i]);
            }
        }
        cur = *(seq.end() - 1);
    }

    rep(i, 0, N) cout << seq[i] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
