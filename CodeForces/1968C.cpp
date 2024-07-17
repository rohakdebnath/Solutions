#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<int> A (N - 1); rep(i, 0, N - 1) cin >> A[i];
    vector<int> ans (N);
    ans[0] = *max_element(all(A)) + 1;
    rep(i, 0, N - 1){
        ans[i + 1] = ans[i] + A[i];
    }
    rep(i, 0, N) cout << ans[i] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
