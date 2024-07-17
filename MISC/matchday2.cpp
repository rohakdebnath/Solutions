#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, K; cin >> N >> K;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    multiset<int> sw;
    rep(i, 0, K - 1) sw.insert(A[i]);
    vector<int> ans (N - K + 1);

    rep(i, K - 1, N){
        sw.insert(A[i]);
        ans[i - K + 1] = *(--sw.end());
        sw.erase(sw.find(A[i - K + 1]));
    }
    rep(i, 0, N - K + 1) cout << ans[i] << " \n"[i == N - K];
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
